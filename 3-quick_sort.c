#include <stdio.h>
#include "sort.h"

/**
 * particion - this splits the array 
 * @array: this is an array
 * @bajo: this is an integer
 * @high: this is an integer
 * Return: partition
 */

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int x, i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			x = array[i];
			array[i] = array[j];
			array[j] = x;
		}
	}
	x = array[i + 1];
	array[i + 1] = array[high];
	array[high] = x;
	return (i + 1);
}

/**
 * quick_sort - wih this function you can sort an array 
 * @array: this is an array of integer
 * @size: this is a size
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int stack;
	int top = -1;

    stack = malloc(size * sizeof(int));
	stack[++top] = 0;
	stack[++top] = size - 1;

	while (top >= 0)
	{
		int high = stack[top--];
		int low = stack[top--];
		int pivot_index = partition(array, low, high);

		if (pivot_index - 1 > low)
		{
			stack[++top] = low;
			stack[++top] = pivot_index - 1;
		}
		if (pivot_index + 1 < high)
		{
			stack[++top] = pivot_index + 1;
			stack[++top] = high;
		}
		print_array(array, size);
	}
    free(stack);
}