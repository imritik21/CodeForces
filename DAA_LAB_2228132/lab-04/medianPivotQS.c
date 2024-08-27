#include <stdio.h>

// Function to find the median of three elements
int medianOfThree(int *arr, int lo, int mid, int hi) {
    if ((arr[lo] < arr[mid] && arr[mid] < arr[hi]) || (arr[hi] < arr[mid] && arr[mid] < arr[lo]))
        return mid;
    else if ((arr[mid] < arr[lo] && arr[lo] < arr[hi]) || (arr[hi] < arr[lo] && arr[lo] < arr[mid]))
        return lo;
    else
        return hi;
}

// Function to partition the array using the median of three as the pivot
int partition(int *arr, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;
    int medianIndex = medianOfThree(arr, lo, mid, hi);

    // Swap the median with the last element
    int temp = arr[medianIndex];
    arr[medianIndex] = arr[hi];
    arr[hi] = temp;

    int pivot = arr[hi];
    int i = lo - 1;

    for (int j = lo; j < hi; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Place the pivot element in its correct position
    temp = arr[i + 1];
    arr[i + 1] = arr[hi];
    arr[hi] = temp;

    return i + 1; // Return the pivot index
}

// Function to implement QuickSort
void QuickSort(int *arr, int lo, int hi) {
    if (lo < hi) {
        int pi = partition(arr, lo, hi); // Partition the array
        QuickSort(arr, lo, pi - 1);      // Recursively sort the left subarray
        QuickSort(arr, pi + 1, hi);      // Recursively sort the right subarray
    }
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Quick Sort
    QuickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
