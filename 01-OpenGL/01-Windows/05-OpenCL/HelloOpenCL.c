// header files
// standard headers

#include <stdio.h>

// OpenCL headers
#include <CL/opencl.h>

#include <stdlib.h>

// global variables
const int iNumbersOfArrayElements = 5;

cl_platform_id oclPlatformID = NULL;
cl_device_id oclDeviceID = NULL;

cl_context oclContext = NULL;
cl_command_queue oclCommandQueue =  NULL;

cl_program oclProgram = NULL;
cl_kernel oclKernel = NULL;

float *hostInput1 = NULL;
float *hostInput2 = NULL;
float *hostOutput = NULL;

cl_mem deviceInput1 = NULL;
cl_mem deviceInput2 = NULL;
cl_mem deviceOutput = NULL;

// OpenCL
const char *oclSourceCode =
"__kernel void vecAddGPU(__global float *in1, __global float *in2, __global float *out, int len) "\
"{" \
"int i=get_global_id(0);"\
"if(i < len)" \
"{" \
"out[i]=in1[i]+in2[i];"
"}"\
"}";

// entry point function
int main(void)
{
    // function declaration
    void cleanup(void);

    // variable declaration
    int size = iNumbersOfArrayElements * sizeof(float);
    cl_int result;

    //code
    // host memory allocation
    hostInput1 = (float*)malloc(size);
    if (hostInput1 == NULL)
    {
        printf("Host Memory allocation is failed for hostInput1 array\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostInput2 = (float *)malloc(size);
    if (hostInput2 == NULL)
    {
        printf("Host Memory allocation is failed for hostInput2 array\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostOutput = (float *)malloc(size);
    if (hostOutput == NULL)
    {
        printf("Host Memory allocation is failed for hostInput1 array\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // filling values into host 
    for (int index = 0; index < 5; index++)
    {
        hostInput1[index] = 101.0 + (float)index;
        hostInput2[index] = 201.0 + (float)index;
    }

    // get opencl suporting platform ID's
    result = clGetPlatformIDs(1, &oclPlatformID, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clGetPlatformIDs() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // get OpenCL suporting CPU decice's ID
    cl_uint dev_num;
    result = clGetDeviceIDs(oclPlatformID, CL_DEVICE_TYPE_GPU, 2, &oclDeviceID, &dev_num);
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
    oclKernel = clCreateKernel(oclProgram, "vecAddGPU", &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateKernel() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // devive memory allocation
    // 4th param - parameter of existing buffer if any ( maube for initialisation)
    deviceInput1=clCreateBuffer(oclContext, CL_MEM_READ_ONLY, size, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateBuffer() Failed for 1st input array : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    deviceInput2=clCreateBuffer(oclContext, CL_MEM_READ_ONLY, size, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateBuffer() Failed for 2nd input array : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    deviceOutput=clCreateBuffer(oclContext, CL_MEM_WRITE_ONLY, size, NULL, &result);
    if (result != CL_SUCCESS)
    {
        printf("clCreateBuffer() Failed for  output array : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 0th argument i.e. deviceInput1
    result = clSetKernelArg(oclKernel, 0, sizeof(cl_mem), (void *)&deviceInput1);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 1st Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 1st argument i.e. deviceInput2
    result = clSetKernelArg(oclKernel, 1, sizeof(cl_mem), (void *)&deviceInput2);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for  2nd Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 2nd argument i.e. deviceOutput
    result = clSetKernelArg(oclKernel, 2, sizeof(cl_mem), (void *)&deviceOutput);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for  3rd Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // set 0 based 3rd argument i.e. len
    result = clSetKernelArg(oclKernel, 3, sizeof(cl_int), (void *)&iNumbersOfArrayElements);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for  4th Argument : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }


    // write input device buffer into device memory
    //3rd arg - Sync or asunc writing
    // 4th 0 start offset
    // 7th - number event interested
    // 8th addrees of array of callback fun of event of interest
    // 9th related to event callback arguments
    result = clEnqueueWriteBuffer(oclCommandQueue, deviceInput1, CL_FALSE, 0, size, hostInput1, 0, NULL, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 1st Input device buffer : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    result = clEnqueueWriteBuffer(oclCommandQueue, deviceInput2, CL_FALSE, 0, size, hostInput2, 0, NULL, NULL);
    if (result != CL_SUCCESS)
    {
        printf("clSetKernelArg() Failed for 2nd Input device buffer : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // kernel configuration
    size_t global_size = 5; // 1d 5 element array operation
    // ND --> N dimensions
    // 3rd param - dimensions
    // 4th - reserved
    // 5th - global work size
    // 6th - local work size
    // 7, 8, 9 - related to event handling 
    result = clEnqueueNDRangeKernel(oclCommandQueue, oclKernel, 1, NULL, &global_size, NULL, 0, NULL, NULL);
    if (result != CL_SUCCESS)
    {        
        printf("clEnqueueNRRangeKernel() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // finish the openCl command queues
    clFinish(oclCommandQueue);

    // read back the result from the device (i.e. from deviceOutput) into CPU variable (i.e. HostPutput)
    result = clEnqueueReadBuffer(oclCommandQueue, deviceOutput, CL_TRUE, 0, size, hostOutput, 0, NULL, NULL);

    if (result != CL_SUCCESS)
    {        
        printf("clEnqueueReadBuffer() Failed : %d\n", result);
        cleanup();
        exit(EXIT_FAILURE);
    }

    // display result 
    int i;
    for (i = 0; i < iNumbersOfArrayElements; i++)
    {
        printf("%f + %f = %f\n", hostInput1[i], hostInput2[i], hostOutput[i]);
    }

    // cleanup
    cleanup();
    return 0;
}


void cleanup(void)
{
    // code
    if (deviceOutput)
    {
        clReleaseMemObject(deviceOutput);
    }

    if (deviceInput2)
    {
        clReleaseMemObject(deviceInput2);
    }

    if (deviceInput1)
    {
        clReleaseMemObject(deviceInput1);
    }

    if (oclKernel)
    {
        clReleaseKernel(oclKernel);
    }

    if (oclCommandQueue)
    {
        clReleaseCommandQueue(oclCommandQueue);
    }

    if (oclContext)
    {
        clReleaseContext(oclContext);
    }

    if (hostOutput)
    {
        free(hostOutput);
        hostOutput = NULL;
    }

    if (hostInput1)
    {
        free(hostOutput);
        hostInput1 = NULL;
    }

    if (hostInput1)
    {
        free(hostOutput);
        hostInput1 = NULL;
    }


}

