#include "sort.h"

/**
 * counting_sort - Sorts an array using the counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *output, k = 0;
    size_t i;

    if (!array || size < 2)
        return;

    /* Find the largest element in the array */
    for (i = 0; i < size; i++)
        if (array[i] > k)
            k = array[i];

    /* Allocate memory for the count array and output array */
    count = calloc(k + 1, sizeof(int));
    output = malloc(size * sizeof(int));
    if (!count || !output)
        return;

    /* Store the count of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Update the count array */
    for (i = 1; i <= (size_t)k; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = 0; i < size; i++)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the output array to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(count, k + 1);  /* Print the counting array */
    free(count);
    free(output);
}
