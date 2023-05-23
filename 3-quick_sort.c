#include "sort.h"

/**
 * partition - Lomuto partition scheme
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 *
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_sort_helper - recursive function to perform quick sort
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high, size);

        quick_sort_helper(array, low, pivot - 1, size);
        quick_sort_helper(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}