#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int *array, int bajo, int alto)
{
    int pivote = array[alto];
    int i = bajo - 1;

    for (int j = bajo; j < alto; j++)
    {
        if (array[j] < pivote)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, alto + 1);
        }
    }

    swap(&array[i + 1], &array[alto]);
    print_array(array, alto + 1);

    return (i + 1);
}
void quick_sort_helper(int *array, int bajo, int alto)
{
    if (bajo < alto)
    {
        int indice_pivote = particion(array, bajo, alto);
        quick_sort_helper(array, bajo, indice_pivote - 1);
        quick_sort_helper(array, indice_pivote + 1, alto);
    }
}
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1);
}
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Arreglo original: ");
    print_array(array, n);

    printf("\nOrdenando el arreglo...\n");
    quick_sort(array, n);

    printf("\nArreglo ordenado: ");
    print_array(array, n);

    return 0;
}