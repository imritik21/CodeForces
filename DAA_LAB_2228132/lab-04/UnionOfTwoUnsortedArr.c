#include<stdio.h>
int k=0;

void merge(int *arr1,int *arr2,int n,int m,int *arr3){
    int l = 0, r = 0;
    k = 0;
    while (l < n && r < m) {
        if (arr1[l] < arr2[r]) {
            if (k == 0 || arr3[k - 1] != arr1[l]) {
                arr3[k++] = arr1[l];
            }
            l++;
        } else if (arr1[l] > arr2[r]) {
            if (k == 0 || arr3[k - 1] != arr2[r]) {
                arr3[(k)++] = arr2[r];
            }
            r++;
        } else {
            if (k == 0 || arr3[k - 1] != arr1[l]) {
                arr3[(k)++] = arr1[l];
            }
            l++;
            r++;
        }
    }
    while (l < n) {
        if (arr3[k - 1] != arr1[l]) {
            arr3[(k)++] = arr1[l];
        }
        l++;
    }
    while (r < m) {
        if (arr3[k - 1] != arr2[r]) {
            arr3[(k)++] = arr2[r];
        }
        r++;
    }
}
// void mergeSort(int *arr,)
int main() {
    // Your code here
    int n,m;
    printf("Enter size of array 1: ");
    scanf("%d",&n);
    printf("Enter size of array 2: ");
    scanf("%d",&m);
    int arr1[n],arr2[m];
    for(int i=0;i<n;i++)scanf("%d",&arr1[i]);
    for(int i=0;i<m;i++)scanf("%d",&arr2[i]);

    int arr3[n+m];
    for(int i=0;i<(n+m);i++)arr3[i]=0;

    merge(arr1,arr2,n,m,arr3);
    for(int i=0;i<k;i++){
        printf("%d ",arr3[i]);
    }
    return 0;
}