#include <stdio.h>

// Function to perform Bubble Sort
void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) // Outer loop for passes
    {
        for (j = 0; j < n - i - 1; j++) // Inner loop for comparisons
        {
            if (arr[j] > arr[j + 1]) // Compare adjacent elements
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    bubble_sort(arr, n); // Call bubble_sort to sort the array

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); // Print sorted elements
    }
    printf("\n");

    return 0;
}
