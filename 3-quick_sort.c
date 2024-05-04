#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for the Quick sort.
 * @array: The array to sort.
 * @low: Lower index of the sub-array.
 * @high: Higher index of the sub-array.
 * @size: Total size of the main array.
 * Return: The partition index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int temp, j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (i != j)
                print_array(array, size);
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    if (i + 1 != high)
        print_array(array, size);
    return (i + 1);
}

/**
 * quick_sort_recursion - Helper function to implement Quick sort using recursion.
 * @array: The array to sort.
 * @low: Lower index of the sub-array.
 * @high: Higher index of the sub-array.
 * @size: Total size of the main array.
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);
        quick_sort_recursion(array, low, pi - 1, size);
        quick_sort_recursion(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick sort
 * algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursion(array, 0
