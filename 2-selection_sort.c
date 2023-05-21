#include "sort.h"

/**
 * selection_sort- use the select_sort
 * @array: array of ints 
 * @size: this is the size of the array.
 * 
*/
void selection_sort(int *array, size_t size)
{
    size_t i, j, temp, swap = 0;

    for (i = 0; i < size; i++)
    {
        j = i + 1;
        for (; j < size; j++)
        {
            swap = 0;
            if (array[i] > array[j])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
                swap = 1;
            }
        }
        if (swap == 1)
        {
            print_array(array, size);
            swap = 0;
        }
    }
}