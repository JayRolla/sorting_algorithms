#include "sort.h"

/**
 * merge_sort - Sorts an array using the top-down merge sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int *temp = malloc(sizeof(int) * size);
    if (!temp)
        return;

    top_down_split_merge(temp, array, 0, size);
    free(temp);
}

/**
 * top_down_split_merge - Recursively splits and merges an array
 * @temp: Temporary array for merging
 * @array: The original array
 * @start: Starting index
 * @end: Ending index
 */
void top_down_split_merge(int *temp, int *array, size_t start, size_t end)
{
    if (end - start < 2)
        return;

    size_t middle = (end + start) / 2;
    top_down_split_merge(temp, array, start, middle);
    top_down_split_merge(temp, array, middle, end);
    top_down_merge(temp, array, start, middle, end);
    copy_array(temp, array, start, end);
}

/**
 * top_down_merge - Merges two halves of an array
 * @temp: Temporary array for merging
 * @array: The original array
 * @start: Starting index of the left half
 * @middle: Ending index of the left half and starting index of the right half
 * @end: Ending index of the right half
 */
void top_down_merge(int *temp, int *array, size_t start, size_t middle, size_t end)
{
    size_t i = start, j = middle;
    for (size_t k = start; k < end; k++)
    {
        if (i < middle && (j >= end || array[i] <= array[j]))
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
    }
}

/**
 * copy_array - Copies the sorted elements back to the original array
 * @temp: Temporary array containing sorted elements
 * @array: The original array
 * @start: Starting index of the elements to copy
 * @end: Ending index of the elements to copy
 */
void copy_array(int *temp, int *array, size_t start, size_t end)
{
    for (size_t k = start; k < end; k++)
        array[k] = temp[k];
}
