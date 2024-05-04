#include "sort.h"

/**
 * radix_sort - Sorts an array using the LSD radix sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int max_num = array[0];
    for (size_t i = 1; i < size; i++)
        if (array[i] > max_num)
            max_num = array[i];

    for (int exp = 1; max_num / exp > 0; exp *= 10)
        count_sort(array, size, exp);
}

/**
 * count_sort - A function to do counting sort of array[] according to
 * the digit represented by exp (exponent).
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: Exponent corresponding to the digit to sort by
 */
void count_sort(int *array, size_t size, int exp)
{
    int output[size];
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the output array to array[], so that array now contains sorted numbers
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);
}
