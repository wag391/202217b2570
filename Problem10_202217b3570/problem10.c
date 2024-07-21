#include <stdio.h>

/* Function to merge the subarrays of a[] */
void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1; // Size of LeftArray
    int n2 = end - mid;     // Size of RightArray

    int LeftArray[n1], RightArray[n2]; // Temporary arrays for merging

    /* Copy data to temporary arrays LeftArray[] and RightArray[] */
    for (i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = beg; // Initial index of merged sub-array

    /* Merge the temporary arrays back into a[l..r] */
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of LeftArray[], if any */
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of RightArray[], if any */
    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

/* Function to perform merge sort */
void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = beg + (end - beg) / 2; // Calculate mid point

        mergeSort(a, beg, mid); // Sort first half
        mergeSort(a, mid + 1, end); // Sort second half

        merge(a, beg, mid, end); // Merge the sorted halves
    }
}

/* Function to print the array */
void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {12, 31, 25, 8, 32, 17, 40, 42};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting array elements are - \n");
    printArray(a, n);

    mergeSort(a, 0, n - 1); // Call mergeSort to sort the array

    printf("After sorting array elements are - \n");
    printArray(a, n);

    return 0;
}
