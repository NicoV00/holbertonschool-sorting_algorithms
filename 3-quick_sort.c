#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

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

void quick_sort(int *array, size_t size)
{
	int *stack = NULL;
	int top = -1;

	if (size <= 1)
		return;

	stack = malloc(size * sizeof(int));
	if (stack == NULL)
	{
		return;
	}

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
