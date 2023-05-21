#include "sort.h"

/**
 * selection_sort- use the select_sort
 * @array: array of ints 
 * @size: this is the size of the array.
 * 
*/
void selection_sort(int *array, size_t size)
{
    int i, j, min_index, temp;

    for (i = 0; i < size; i++)
    {
        min_index = 0;
        min_index = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[min_index] > array[j])
            {
                temp = array[j];
                array[j] = array[min_index];
                array[min_index] = temp;
                print_array(array, size);
            }
        }
        
    }
}




