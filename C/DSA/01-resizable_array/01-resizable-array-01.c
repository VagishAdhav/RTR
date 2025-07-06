#include <stdio.h>
#include <stdlib.h>

void allocate_read_write_free_array(void);
void realloc_demo(void);

int main(void)
{
	puts("-------Entered main()");
	allocate_read_write_free_array();
	realloc_demo();
	return (0);
}

void allocate_read_write_free_array(void)
{
	puts("-------Entered allocate_read_write_free_array()");
	// step -1: Define array element type pointer and 
	// initialize it to NULL
	int* p_arr = NULL;
	int N = 5;
	puts("allocate_read_write_free_array(): Done defining");
	//Step -2 : Allocate required memory to store array
	// elements using dynamic memory allocation function malloc
	p_arr = (int*)malloc(N * sizeof(int));
	if (p_arr == NULL)
	{
		printf("Error in allocating memory. Exiting the application \n");
		exit(-1);
	}

	// step -3 : write some data in the memory.
	// strategy: all elements in array will be set to their (index + 1) * 100
	int i;
	for (i = 0; i < N; ++i)
	{
		*(p_arr + i) = (i + 1) * 100;
		p_arr[i] = (i + 1) * 100; // writing the same value but using different syntax
		// to access the element at index i
		// address of &p_arr[i] p_arr + i
	}

	// step 4: read all element in array and print those
	int value_at_current_index;
	for (i = 0; i < N; ++i)
	{
		value_at_current_index = p_arr[i];
		printf("value at index %d is %d\n", i, value_at_current_index);
	}
	// step 5: Release the memory given to array
	free(p_arr);
	// step 6: Make pointer NULL
	p_arr = NULL;

}

void realloc_demo(void)
{
	// Step 1: Define array of 5 elements and write some data on it and print it
	int* ptr_arr = NULL;
	int N = 5;
	int i;

	ptr_arr = (int*)malloc(N * sizeof(int));
	if (ptr_arr == NULL)
	{
		printf("Error in allocating memory. Exiting the application \n");
		exit(-1);
	}

	for (i = 0; i < N; ++i)
	{
		ptr_arr[i] = (i + 1) * 1000;
	}

	for (i = 0; i < N; ++i)
	{
		printf("ptr_arr [%d]:[%d]\n", i, ptr_arr[i]);
	}

	printf("%s():Done reading and dispalying data of array\n", __FUNCTION__);

	int* ptr_resized_array_1 = NULL;
	ptr_resized_array_1 = (int*)realloc(ptr_arr, 10 * sizeof(int));
	
	if (ptr_resized_array_1 == NULL)
	{
		exit(-1);
	}
	else if (ptr_resized_array_1 == ptr_arr)
	{

	}
	else if (ptr_resized_array_1 != ptr_arr)
	{

	}
	ptr_arr = NULL;
	N = 10;

	for (i = 0; i < N; ++i)
	{
		printf("ptr_resized_array_1 [%d]:[%d]\n", i, ptr_resized_array_1[i]);
	}

	for (i = 5; i < N; ++i)
	{
		ptr_resized_array_1[i] = (i + 1) * 1000;
	}

	for (i = 0; i < N; ++i)
	{
		printf("ptr_resized_array_1 [%d]:[%d]\n", i, ptr_resized_array_1[i]);
	}
}


