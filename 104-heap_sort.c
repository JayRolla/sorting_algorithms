#include "sort.h"

/**
 * heap_sort - Sorts an array using the sift-down heap sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    size_t i, last_unsorted;
    for (i = size / 2 - 1; (int)i >= 0; i--)
        sift_down(array, size, i);

    for (last_unsorted = size - 1; last_unsorted > 0; last_unsorted--)
    {
        swap_int(&array[0], &array[last_unsorted]);
        print_array(array, size);
        sift_down(array, last_unsorted, 0);
    }
}

/**
 * sift_down - Repairs the heap whose root element is at index 'start'
 * @array: The heap array
 * @size: Size of the heap
 * @start: Index of the root element of the heap
 */
void sift_down(int *array, size_t size, size_t start)
{
    size_t root = start, child, swap;

    while (root * 2 + 1 < size)
    {
        child = root * 2 + 1;
        swap = root;

        if (array[swap] < array[child])
            swap = child;

        if (child + 1 < size && array[swap] < array[child + 1])
            swap = child + 1;

        if (swap == root)
            return;

        swap_int(&array[root], &array[swap]);
        root = swap;
    }
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
