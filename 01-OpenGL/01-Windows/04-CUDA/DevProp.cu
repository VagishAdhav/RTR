#include <stdio.h>
#include <cuda.h>

int main(void)
{
    // function declaration 
    void PrintCUDADeviceProperties(void);

    // code
    PrintCUDADeviceProperties();
}

void PrintCUDADeviceProperties(void)
{
    // code
    printf("CUDA Information : \n");
    printf("===========================================================\n");

    cudaError_t ret_cuda_rt;
    int dev_count;
    ret_cuda_rt = cudaGetDeviceCount(&dev_count);
    if (ret_cuda_rt != cudaSuccess)
    {
        printf("cuda Runtime API Error : %s\n", cudaGetErrorString(ret_cuda_rt));
    }
    else if (dev_count == 0)
    {
        printf("No CUDA supported device on this system.\n");
        return;
    }
    else
    {
        int driverVersion = 0, runtimeVersion = 0;
        printf("Total number of CUDA supported GPU/Devices on this system : %d\n", dev_count);
        cudaDriverGetVersion(&driverVersion);
        cudaRuntimeGetVersion(&runtimeVersion);
        printf("**************CUDA DRIVER AND RUNTIME VERSION**************\n");
        printf("===========================================================\n");
        printf("CUDA Driver Version                                          : %d.%d\n", driverVersion/1000, (driverVersion % 100)/10);
        printf("CUDA Runtime Version                                         : %d.%d\n", runtimeVersion/1000, (runtimeVersion % 100)/10);
        for (int i = 0; i < dev_count; i++)
        {
            cudaDeviceProp dev_prop;
            memset((void *)&dev_prop, 0, sizeof(cudaDeviceProp));


            ret_cuda_rt = cudaGetDeviceProperties(&dev_prop, i);
            if (ret_cuda_rt != cudaSuccess)
            {
                printf("%s in %s at line %d\n", cudaGetErrorString(ret_cuda_rt), __FILE__, __LINE__);
                return;
            }
            printf("\n");
            printf("===========================================================\n");
            printf("**************GPU DEVICE GENERAL INFORMATION***************\n");
            printf("===========================================================\n");
            printf("GPU device number                                           :%d\n", i);
            printf("GPU device name                                             :%s\n", dev_prop.name);
            printf("GPU device compute capability                               :%d.%d\n", dev_prop.major, dev_prop.minor);
            printf("GPU devie clock rate                                        :%d\n", dev_prop.clockRate);
            printf("GPU device Type                                             :");
            if (dev_prop.integrated)
                printf("Integrated (On- Board)\n");
            else
                printf("Discrete (Card)\n");
            printf("\n");
            printf("===========================================================\n");
            printf("**************GPU DEVICE MEMORY INFORMATION****************\n");
            printf("===========================================================\n");
            printf("GPU device Total Memory                                     : %.0f GB, %.0f MB, %llu Bytes\n", ((float)dev_prop.totalGlobalMem/1048576.0f)/1024.0f, (float)dev_prop.totalGlobalMem/1048576.0f, (unsigned long long)dev_prop.totalGlobalMem);
            printf("GPU device Constant Memory                                  : %llu Bytes\n", (unsigned long long)dev_prop.totalConstMem);
            printf("GPU device Shared Memory per SMProcessor                    : %llu Bytes\n", (unsigned long long)dev_prop.sharedMemPerBlock);
            printf("\n");
            printf("===========================================================\n");
            printf("**************GPU DEVICE MULTIPROCESSOR INFORMATION********\n");
            printf("===========================================================\n");
            printf("GPU device number of SMProcessors                           :%lu\n", dev_prop.multiProcessorCount);
            printf("GPU device registers per SMProcessors                       :%lu\n", dev_prop.regsPerBlock);
            printf("\n");
            printf("===========================================================\n");
            printf("*******************GPU DEVICE THREAD INFORMATION***********\n");
            printf("===========================================================\n");
            printf("GPU Device maximum number of threads per SMProcessor       : %d\n", dev_prop.maxThreadsPerMultiProcessor);
            printf("GPU Device maximum number of threads per Block             : %d\n", dev_prop.maxThreadsPerBlock);
            printf("GPU Device Threads per Warp                                : %d\n", dev_prop.warpSize);
            printf("GPU Device maximum thread dimensions                       :(%d, %d, %d)\n", dev_prop.maxThreadsDim[0], dev_prop.maxThreadsDim[1], dev_prop.maxThreadsDim[2]);
            printf("GPU device maximum number of Grid Dimension                :(%d, %d, %d)\n", dev_prop.maxGridSize[0], dev_prop.maxGridSize[1], dev_prop.maxGridSize[2]);
            printf("\n");
            printf("===========================================================\n");
            printf("*******************GPU DEVICE DIVER INFORMATION************\n");
            printf("===========================================================\n");
            printf("GPU Device has ECC support                                  :%s\n", dev_prop.ECCEnabled ? "Enabled" : "Disabled");
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
            printf("GPU decvice CUDA driver mode (TCC or WDDM)                  :%s\n", dev_prop.tccDriver ? "TCC (Tesla compute cluster driver)" : "WDDM (Windows display driver module)");
#endif
            printf("************************************************************\n");

        }

    }
}
