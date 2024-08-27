#include <stdio.h>

int partition(int *arr, int lo, int hi)
{
    int pivot = arr[lo];  // Pivot is now the first element
    int i = lo; // i is initialized to lo

    for (int j = lo + 1; j <= hi; j++)
    {
        if (arr[j] < pivot)
        {
            // swap
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Place the pivot in its correct position
    int temp = arr[i];
    arr[i] = arr[lo];
    arr[lo] = temp;

    return i;
}
int part(int *arr,int lo,int hi){
    // pivot is lo
    int pivot = arr[lo];
    int i = lo;

    for(int j=i+1;i<=hi;i++){
        if(arr[j]<pivot){
            i++;
            // swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // now place the pivot at correct placee
    int temp = arr[i];
    arr[i] = arr[lo];
    arr[lo] = temp;

    return i+1;// return the pivot index
}
void QuickSort(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int pi = partition(arr, lo, hi);// partition the array
        QuickSort(arr, lo, pi - 1);// recurively sort left sub array
        QuickSort(arr, pi + 1, hi);// right subarray
    }
}

int main()
{
    // Your code here
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Quick Sort
    QuickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
