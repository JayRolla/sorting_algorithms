#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array using the quick sort algorithm with Hoare partition scheme
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    hoare_quick_sort(array, 0, size - 1);
}

/**
 * hoare_quick_sort - Recursive helper function for quick_sort_hoare
 * @array: Array to be sorted
 * @low: Starting index
 * @high: Ending index
 */
void hoare_quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high);
        hoare_quick_sort(array, low, pivot);
        hoare_quick_sort(array, pivot + 1, high);
    }
}

/**
 * hoare_partition - Hoare partition scheme
 * @array: Array to partition
 * @low: Lower bound of the partition
 * @high: Upper bound of the partition
 * Return: The index of the pivot
 */
int hoare_partition(int *array, int low, int high)
{
    int pivot = array[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap_int(&array[i], &array[j]);
        print_array(array, high + 1);
    }
}

