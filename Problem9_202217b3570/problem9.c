#include <stdio.h>

// Function to sort an array with insertion sort
void insert(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i]; // Store the current element to be inserted
        j = i - 1;

        // Move elements of a[0..i-1], that are greater than temp,
        // to one position ahead of their current position
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j]; // Shift elements to the right
            j = j - 1;
        }
        a[j + 1] = temp; // Insert temp at correct position
    }
}

// Function to print the array
void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int a[] = {12, 31, 25, 8, 32, 17};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting, array elements are:\n");
    printArr(a, n);

    insert(a, n); // Call the insert function to sort the array

    printf("\nAfter sorting, array elements are:\n");
    printArr(a, n);

    return 0;
}
