#include <stdio.h>

int partition(int *arr, int lo, int hi)
{
    int i = lo - 1;
    int pivot = arr[hi];

    for (int j = lo; j <= hi - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // pivot ele ko place kro correctly
    int temp = arr[i+1];
    arr[i+1] = arr[hi];
    arr[hi] = temp;

    return i+1;
}
void QuickSort(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int pi = partition(arr, lo, hi);
        QuickSort(arr, lo, pi - 1);
        QuickSort(arr, pi + 1, hi);
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
    QuickSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}