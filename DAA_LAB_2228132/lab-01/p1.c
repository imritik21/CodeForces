#include<stdio.h>

int main() {
    // Your code here
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int max = arr[0];
    int secmax = arr[0];
    int min=1e7;
    int secmin=1e7;
    if(n==1){
        printf("2nd min and 2nd max wont exist");
        return 0 ;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            secmax=max;
            max=arr[i];
        }
        if(arr[i]>secmax && arr[i]<max){
            secmax=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            secmin=min;
            min=arr[i];
        }
        else if(arr[i]<secmin && arr[i]>min){
            secmin=arr[i];
        }
    }
    printf("%d %d \n",max,secmax);
    printf("%d %d ",min,secmin);
    // for(int i=0;i<n;i++){
    //     printf("%d ",arr[i]);
    // }
    return 0;
}