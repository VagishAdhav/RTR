// header file
// standard headers
#include <stdio.h>

// cuda headers
#include <cuda.h>
#include "helper_timer.h"

// macros
#define BLOCK_WIDTH (128)

// global variables
int *hostA = NULL;
int *hostB = NULL;
int *hostC = NULL;
int *gold = NULL;

int *deviceA = NULL;
int *deviceB = NULL;
int *deviceC = NULL;

float timeOnCPU = 0.0f;
float timeOnGPU = 0.0f;

// CUDA Kernel
__global__ void matMulGPU(int* A, int* B, int *C, int numARows, int numAColumns, int numBColumns, int numCColumns)
{
    // variable declaration
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int column =  blockIdx.x * blockDim.x + threadIdx.x;
    // code
    if ((row < numARows) && (column < numBColumns))
    {
        int value = 0.0;
        for (int k = 0; k < numAColumns; k++)
        {
            int a = A[row * numAColumns + k];
            int b = B[k * numBColumns + column];
            value += a * b;
        }
        C[row * numCColumns + column] = value;
    }
}

// entry point function
int main(void)
{
    // function declaration
    void InitA(int *data, int, int);
    void InitB(int *data, int, int);
    void matMulCPU(int*, int*, int*, int, int, int, int);
    void cleanup(void);

    // variable declaration
    int numARows = BLOCK_WIDTH;
    int numAColumns = BLOCK_WIDTH;
    int numBRows = BLOCK_WIDTH;
    int numBColumns = BLOCK_WIDTH;

    int numCRows = numARows;
    int numCColumns = numBColumns;

    int numGoldRows = numARows;
    int numGoldColumns = numBColumns;

    int sizeA = numARows * numAColumns * sizeof(int);
    int sizeB = numBRows * numBColumns * sizeof(int);
    int sizeC = numCRows * numCColumns * sizeof(int);
    int sizeGold = numGoldRows * numGoldColumns * sizeof(int);

    cudaError_t result = cudaSuccess;

    // code
    // host memory allocation
    hostA = (int *)malloc(sizeA);
    if (hostA == NULL)
    {
        printf("Host Memory allocation is failed for hostA matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostB = (int *)malloc(sizeB);
    if (hostB == NULL)
    {
        printf("Host Memory allocation is failed for hostB matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostC = (int *)malloc(sizeC);
    if (hostC == NULL)
    {
        printf("Host Memory allocation is failed for hostC matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    gold = (int *)malloc(sizeGold);
    if (gold == NULL)
    {
        printf("Host Memory allocation is failed for gold matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // printing matrix dimension and size
    printf("The dimension of Matrix 'hostA' are : %d x %d \n", numARows, numAColumns);
    printf("The dimension of Matrix 'hostB' are : %d x %d \n", numBRows, numBColumns);
    printf("The dimension of Matrix 'hostC' are : %d x %d \n", numCRows, numCColumns);
    printf("The dimension of Matrix 'gold' are : %d x %d \n", numGoldRows, numGoldColumns);
    
    printf("Size of Matrix hostA = %d\n", sizeA);
    printf("Size of Matrix hostB = %d\n", sizeB);
    printf("Size of Matrix hostC = %d\n", sizeC);

    printf("Size of Matric gold = %d\n", sizeGold);

    // fill source matrix
    InitA(hostA, numARows, numAColumns);
    InitB(hostB, numBRows, numBColumns);


    // devide memory allocation
    result = cudaMalloc((void **)&deviceA, sizeA);
    if (result != cudaSuccess)
    {
        printf("Device Memory allocation is failed for deviceA matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    result = cudaMalloc((void **)&deviceB, sizeB);
    if (result != cudaSuccess)
    {
        printf("Device Memory allocation is failed for deviceB matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    result = cudaMalloc((void **)&deviceC, sizeC);
    if (result != cudaSuccess)
    {
        printf("Device Memory allocation is failed for deviceC matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // copy data from host matrices into device matrices
    result = cudaMemcpy(deviceA, hostA, sizeA, cudaMemcpyHostToDevice);
    if (result != cudaSuccess)
    {
        printf("Host to device data copy is failed for deviceA matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    result = cudaMemcpy(deviceB, hostB, sizeA, cudaMemcpyHostToDevice);
    if (result != cudaSuccess)
    {
        printf("Host to device data copy is failed for deviceB matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // CUDA kernel configuration

    dim3 dimGrid = dim3((int)ceil((int)numBColumns / (int)BLOCK_WIDTH), (int)ceil((int)numARows / (int)BLOCK_WIDTH), 1);
    dim3 dimBlock = dim3(BLOCK_WIDTH, BLOCK_WIDTH, 1);

    // CUDA kernel for vector addition
    StopWatchInterface* timer = NULL;
    sdkCreateTimer(&timer);
    sdkStartTimer(&timer);

    matMulGPU <<< dimGrid, dimBlock >>> (deviceA, deviceB, deviceC, numARows, numAColumns, numBColumns, numCColumns);

    sdkStopTimer(&timer);
    timeOnGPU = sdkGetTimerValue(&timer);
    sdkDeleteTimer(&timer);
    timer = NULL;

    // copy data from device matrix to hostmatrix
    result = cudaMemcpy(hostC, deviceC, sizeC, cudaMemcpyDeviceToHost);
    if (result != cudaSuccess)
    {
        printf("Device to host data copy is failed for hostC matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // matrix multiplication oon Host
    matMulCPU(hostA, hostB, gold, numARows, numAColumns, numBColumns, numCColumns);

    // comparison
    int breakValue = -1;
    bool bAccuracy = true;
    for (int i = 0; i < (numCRows * numCColumns); i++)
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
        sprintf(str, "Comparison of CPU and GPU matrix multiplication is accurate");

    // output
    printf("Time taken for vector addition on CPU = %.6f\n", timeOnCPU);
    printf("Time taken for vector addition on GPU = %.6f\n", timeOnGPU);

    printf("%s\n", str);

    // cleanup
    cleanup();

    return 0;
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
        cudaFree(deviceC);
        deviceC = NULL;
    }

    if (deviceB)
    {
        cudaFree(deviceB);
        deviceC = NULL;
    }

    if (deviceA)
    {
        cudaFree(deviceA);
        deviceC = NULL;
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