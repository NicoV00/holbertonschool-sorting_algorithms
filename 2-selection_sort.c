#include "sort.h"
/**
 * selection_sort- use the select_sort
 * @array: array of ints 
 * @size: this is the size of the array.
 * 
*/
void selection_sort(int *array, size_t size)
{
    size_t i, j, min_index, temp;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;

        print_array(array, size);
    }
}