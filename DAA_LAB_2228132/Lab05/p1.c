#include <stdio.h>

void Insert(int *arr, int idx) {
    int i = idx;
    int temp = arr[idx];

    while (i > 1 && temp > arr[i / 2]) {
        arr[i] = arr[i / 2];
        i /= 2;
    }
    arr[i] = temp;
}

int Delete(int arr[], int n) {
    int x = arr[1];  // Root element (max in max-heap)
    arr[1] = arr[n - 1];  // Move last element to root

    int i = 1;
    int j = 2 * i;

    while (j < n - 1) {  // Ensure j+1 does not exceed bounds
        if (j + 1 < n - 1 && arr[j] < arr[j + 1]) {
            j = j + 1;
        }

        if (arr[i] < arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }
    arr[n - 1] = x;
    return x;
}

void CreateHeap(int *arr, int n) {
    for (int i = 2; i < n; i++) {
        Insert(arr, i);
    }
}

int main() {
    int n;
    printf("Enter the size of array (including a dummy element at index 0): ");
    scanf("%d", &n);

    int arr[n + 1];  // Array of size n+1 to accommodate dummy at index 0
    arr[0] = -1;  // Dummy element (won't be used)
    printf("Enter %d elements into the array: ", n - 1);
    for (int i = 1; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    CreateHeap(arr, n);
    printf("Heap after creation: ");
    for (int i = 1; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Delete the root element
    int del = Delete(arr, n);
    printf("Deleted element: %d\n", del);
    printf("Heap after deletion: ");
    for (int i = 1; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
