#include "sort.h"

/**
 * bitonic_sort - Sorts an array using the bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_sort_recursive(array, size, 0, 1);
}

/**
 * bitonic_sort_recursive - Helper function to perform recursive bitonic sort
 * @array: The array to be sorted
 * @size: Size of the array
 * @low: Starting index of the array segment
 * @dir: Direction of sorting, 1 for ascending, 0 for descending
 */
void bitonic_sort_recursive(int *array, size_t size, int low, int dir)
{
    if (size < 2)
        return;

    int k = size / 2;
    for (int i = low; i < low + k; i++) {
        if (dir == (array[i] > array[i + k])) {
            swap_int(&array[i], &array[i + k]);
        }
    }
    bitonic_sort_recursive(array, k, low, 1);
    bitonic_sort_recursive(array, k, low + k, 0);
}

/**
 * swap_int - Swaps two integers in memory
 * @a: First integer
 * @b: Second integer
 */
void swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
