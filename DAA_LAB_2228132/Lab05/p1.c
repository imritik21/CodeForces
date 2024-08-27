#include<stdio.h>

void Insert(int *arr,int idx){
    int i=idx;
    int temp=arr[idx];

    while(i>1 && temp>arr[i/2]){
        arr[i]=arr[i/2];
        i/=2;
    }
    // at last
    arr[i]= temp;
}

int Delete(int arr[], int n){
    int x = arr[1];  // Max hoga
    arr[1] = arr[n-1];
 
    int i = 1;
    int j = 2 * i ;
 
    while (j < n){
        if (arr[j] < arr[j+1]){
            j = j+1;
        }
 
        if (arr[i] < arr[j]){
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i = j;
            j = 2 * i  ;
        } else {
            break;
        }
    }
    arr[n-1]=x;
    return x;
}
void CreateHeap(int *arr,int n){
    for(int i=2;i<n;i++){
        Insert(arr,i);
    }
}
int main() {
    // Your code here
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements into array: ");
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);

    // 0 10 20 30 25 5 40 35
    CreateHeap(arr,n);
    for(int i=1;i<n;i++)printf("%d ",arr[i]);
    printf("\n");
    int del = Delete(arr,8);
    printf("%d\n",del);
    for(int i=1;i<n;i++)printf("%d ",arr[i]);
    
    printf("\n");
    int del2 = Delete(arr,7);
    printf("%d\n",del2);
    for(int i=1;i<n;i++)printf("%d ",arr[i]);
    return 0;
}