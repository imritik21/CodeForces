#include<stdio.h>
int binSearch(int *arr,int lo,int hi,int key){
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) hi=mid-1;
        else lo=mid+1;
    }
    return -1;
}
int main() {
    // Your code here
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // binary search
    int k=5;
    // find idx of k if exits else -1
    int idx = binSearch(arr,0,n-1,k);
    if(idx!=-1){
        printf("Ele exits at index %d",idx);
    }
    else{
        printf("ele doesnot exits");
    }
    return 0;
}