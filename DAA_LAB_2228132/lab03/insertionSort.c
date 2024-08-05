#include <stdio.h>

int main()
{
    // Your code here
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // inertion sort
    for(int i=0;i<n;i++){
        int curr = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>curr){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=curr;
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}