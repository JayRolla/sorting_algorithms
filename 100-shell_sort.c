#include "sort.h"

/**
 * shell_sort - Sorts an array using the shell sort algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t interval = 1, i, j;
    int temp;

    if (!array || size < 2)
        return;

    /* Generate the maximum interval size using the Knuth sequence */
    while (interval < size / 3)
        interval = interval * 3 + 1;

    while (interval > 0)
    {
        for (i = interval; i < size; i++)
        {
            temp = array[i];
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
        print_array(array, size);
        interval /= 3;
    }
}
