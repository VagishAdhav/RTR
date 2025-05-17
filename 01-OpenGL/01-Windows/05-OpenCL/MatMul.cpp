// header files
// standard headers
#include <stdio.h>
#include <math.h> // fabs()

// cuda headers
// OpenCL headers
#include <CL/opencl.h>

#include "helper_timer.h"

// macros
#define BLOCK_WIDTH 128

// global variable
cl_platform_id oclPlatformID;
cl_device_id oclDeviceID;

cl_context oclContext;
cl_command_queue oclCommandQueue;

cl_program oclProgram;
cl_kernel oclKernel;

int *hostA=NULL;
int *hostB=NULL;
int *hostC= NULL;
int *gold=NULL;

cl_mem deviceA=NULL;
cl_mem deviceB=NULL;
cl_mem deviceC=NULL;

float timeOnCPU = 0.0f;
float timeOnGPU = 0.0f;

// OpenCL Kernel
const char *oclSourceCode = 
"__kernel void matMulGPU(__global int *A, __global int *B, __global int *C, int numARows, int numAColumns, int numBColumns, int numCColumns)" \
"{"\
"    int row=get_global_id(0);" \
"    int column=get_global_id(1);" \
"    if ((row < numARows) && (column < numBColumns))" \
"    {" \
"        int result = 0;" \
"        for (int k = 0; k < numAColumns; k++)" \
"        {" \
"            int a = A[row * numAColumns + k];" \
"            int b = B[k * numBColumns + column];" \
"            result += a*b;" \
"        }" \
"        C[row * numCColumns + column] = result;" \
"    }" \
"}";

int main(int argc, char *argv[])
{
    //function declaration
    void InitA(int *data, int, int);
    void InitB(int *data, int, int);
    void matMulCPU(int*, int*, int*, int, int, int, int);
    void cleanup(void);

    // variable declaration 
    int numARows = BLOCK_WIDTH;
    int numACols = BLOCK_WIDTH;
    int numBRows = BLOCK_WIDTH;
    int numBCols = BLOCK_WIDTH;

    int numCRows = numARows;
    int numCCols = numBCols;

    int numGoldRows = numARows;
    int numGoldCols = numBCols;

    int sizeA = numARows * numACols * sizeof(int);
    int sizeB = numBRows * numBCols * sizeof(int);
    int sizeC = numCRows * numCCols * sizeof(int);
    int sizeGold = numGoldRows * numGoldCols * sizeof(int);

    cl_int result;

    //code
    // host memory allocation
    hostA = (int *)malloc(sizeA);
    if (hostA == NULL)
    {
        printf("Host memory allocation is failed for host A matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostB = (int *)malloc(sizeB);
    if (hostB == NULL)
    {
        printf("Host memory allocation failed for host B matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostC = (int *)malloc(sizeC);
    if (hostC == NULL)
    {
        printf("Host memory allocation failed for HostC matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    gold = (int *)malloc(sizeGold);
    if (gold == NULL)
    {
        printf("Host memory allocation failed for gold matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // printing matrix dimension and sizes
    printf("The dimension of Matrix 'hostA' are : %d, %d\n", numARows, numACols);
    printf("The dimension of Matrix 'hostB' are : %d, %d\n", numBRows, numBCols);
    printf("The dimension of Matrix 'hostC' are : %d, %d\n", numCRows, numCCols);
    printf("The dimension of Matrix 'gold' are : %d, %d\n", numGoldRows, numGoldCols);

    printf("Size of Matrix hostA = %d\n", sizeA);
    printf("Size of Matrix hostB = %d\n", sizeB);
    printf("Size of Matrix hostC = %d\n", sizeC);
    printf("Size of Matrix gold = %d\n", sizeGold);

    // fill source matrices
    InitA(hostA, numARows, numACols);
    InitB(hostB, numBRows, numBCols);

    // get opencl suporting platform ID's
    result = clGetPlatformIDs(1, &oclPlatformID, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clGetPlatformIDs() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // get OpenCL suporting CPU decice's ID
    result = clGetDeviceIDs(oclPlatformID, CL_DEVICE_TYPE_GPU, 1, &oclDeviceID, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clGetDeviceIDs() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // get OpenCL compute context
    oclContext = clCreateContext(NULL, 1, &oclDeviceID, NULL, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateContext() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // create command queue
    oclCommandQueue = clCreateCommandQueueWithProperties(oclContext, oclDeviceID, 0, &result);

    if (result != CL_SUCCESS)
    {
        printf("clCreateCommandQueueWithProperties() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // create OpenCL progran from .cl
    oclProgram = clCreateProgramWithSource(oclContext, 1, (const char **)&oclSourceCode, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateProgramWithSource() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // build OpenCL program 
    result = clBuildProgram(oclProgram, 0, NULL, NULL, NULL, NULL);
    if (result != CL_SUCCESS)
    {
        size_t len;
        char buffer[2048];
        clGetProgramBuildInfo(oclProgram, oclDeviceID, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("Program Build Log : %s\n", buffer);
        printf("clBuildProgram() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // create OpenCL kernel by passing function name that we used in .cl file
    oclKernel = clCreateKernel(oclProgram, "matMulGPU", &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateKernel() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // devive memory allocation
    deviceA=clCreateBuffer(oclContext, CL_MEM_READ_ONLY, sizeA, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateBuffer() Failed for 1st input array : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    deviceB=clCreateBuffer(oclContext, CL_MEM_READ_ONLY, sizeB, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateBuffer() Failed for 2nd input array : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    deviceC=clCreateBuffer(oclContext, CL_MEM_WRITE_ONLY, sizeC, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateBuffer() Failed for  output array : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 0th argument i.e. deviceA
    result = clSetKernelArg(oclKernel, 0, sizeof(cl_mem), (void *)&deviceA);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 1st Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 1st argument i.e. deviceB
    result = clSetKernelArg(oclKernel, 1, sizeof(cl_mem), (void *)&deviceB);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for  2nd Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 2nd argument i.e. deviceC
    result = clSetKernelArg(oclKernel, 2, sizeof(cl_mem), (void *)&deviceC);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 3rd Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 3rd argument i.e. numARows
    result = clSetKernelArg(oclKernel, 3, sizeof(cl_int), (void *)&numARows);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 4th Argument : %d\n", result);
        cleanup();        exit(EXIT_FAILURE);
    }

    
    // set 0 based 4th argument i.e. numACols
    result = clSetKernelArg(oclKernel, 4, sizeof(cl_int), (void *)&numACols);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 5th Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }


    // set 0 based 5th argument i.e. numBCold
    result = clSetKernelArg(oclKernel, 5, sizeof(cl_int), (void *)&numBCols);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 6th Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }


    // set 0 based 6th argument i.e. numCCols
    result = clSetKernelArg(oclKernel, 6, sizeof(cl_int), (void *)&numCCols);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 7th Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }


    // write input device buffer into device memory
    result = clEnqueueWriteBuffer(oclCommandQueue, deviceA, CL_FALSE, 0, sizeA, hostA, 0, NULL, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 1st Input device buffer : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    result = clEnqueueWriteBuffer(oclCommandQueue, deviceB, CL_FALSE, 0, sizeB, hostB, 0, NULL, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 2nd Input device buffer : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // kernel configuration
    size_t globalWorkSize[2] = {BLOCK_WIDTH, BLOCK_WIDTH};

    //start timer
    StopWatchInterface *timer = NULL;
    sdkCreateTimer(&timer);
    sdkStartTimer(&timer);

    result = clEnqueueNDRangeKernel(oclCommandQueue, oclKernel, 2, NULL, globalWorkSize, NULL, 0, NULL, NULL);
    if (result != CL_SUCCESS)
    {        
        printf("clEnqueueNRRangeKernel() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // finish the openCl command queues
    clFinish(oclCommandQueue);

    // stop timer
    sdkStopTimer(&timer);
    timeOnGPU = sdkGetTimerValue(&timer);
    sdkDeleteTimer(&timer);

    // read back the result from the device (i.e. from deviceOutput) into CPU variable (i.e. HostPutput)
    result = clEnqueueReadBuffer(oclCommandQueue, deviceC, CL_TRUE, 0, sizeC, hostC, 0, NULL, NULL);

    if (result != CL_SUCCESS)
    {        
        printf("clEnqueueReadBuffer() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // matrix multiplication on Host
    matMulCPU(hostA, hostB, gold, numARows, numACols, numBCols, numCCols);

    // comparison
    int breakValue = -1;
    bool bAccuracy = true;
    for (int i = 0; i < numCRows * numCCols; i++)
    {
        int val1 = gold[i];
        int val2 = hostC[i];
        if (val1 != val2)
        {
            bAccuracy = false;
            breakValue = i;
            break;
        }
    }

    char str[128];
    if (bAccuracy == false)
        sprintf(str, "Comparison of CPU and GPU matrix multiplication is not accurate at aray index : %d", breakValue);
    else
        sprintf(str, "Comparison of CPU and  GPU matrix multiplication is accurate");

    // output
    printf("Time taken for matrix multiplication on CPU = %.6f\n", timeOnCPU);
    printf("Time taken for matrix multiplication on GPU = %.6f\n", timeOnGPU);
    printf("%s\n", str);

    // cleanup
    cleanup();

    return (0);
}

void InitA(int  *data, int row, int col)
{
    int num=1;
    //code
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(data + i * col + j) = num;
            num++;
        }
    }
}

void InitB(int  *data, int row, int col)
{
    int num=BLOCK_WIDTH;
    //code
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(data + i * col + j) = num;
            num--;
        }
    }
}

void matMulCPU(int *A, int *B, int *C, int numARows, int numAColumns, int numBColumns, int numCColumns)
{
    //code
    //start timer
    StopWatchInterface *timer = NULL;
    sdkCreateTimer(&timer);
    sdkStartTimer(&timer);

    for (int i = 0; i < numARows; ++i)
    {
        for (int j = 0; j < numBColumns; ++j)
        {
            int value = 0.0f;
            for(int k = 0; k < numAColumns; ++k)
            {
                int a = A[i * numAColumns + k];
                int b = B[k * numBColumns + j];
                value += a * b;
            }
            C[i * numCColumns + j] = value;
        }
    }

    sdkStopTimer(&timer);
    timeOnCPU = sdkGetTimerValue(&timer);
    sdkDeleteTimer(&timer);
    timer = NULL;
}

void cleanup(void)
{
    // code
    if (deviceC)
    {
        clReleaseMemObject(deviceC);
        deviceC = NULL;
    }

    if (deviceB)
    {
        clReleaseMemObject(deviceB);
        deviceB = NULL;
    }

    if (deviceA)
    {
        clReleaseMemObject(deviceA);
        deviceA = NULL;
    }

    if (oclKernel)
    {
        clReleaseKernel(oclKernel);
        oclKernel = NULL;
    }

    if (oclProgram)
    {
        clReleaseProgram(oclProgram);
        oclProgram = NULL;
    }

    if (oclCommandQueue)
    {
        clReleaseCommandQueue(oclCommandQueue);
        oclCommandQueue =  NULL;
    }

    if (oclContext)
    {
        clReleaseContext(oclContext);
        oclContext = NULL;
    }

    if (gold)
    {
        free(gold);
        gold = NULL;
    }

    if (hostC)
    {
        free(hostC);
        hostC = NULL;
    }

    if (hostB)
    {
        free(hostB);
        hostB = NULL;
    }

    if (hostA)
    {
        free(hostA);
        hostA = NULL;
    }
}




