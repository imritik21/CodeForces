#include<stdio.h>

int main() {
    // Your code here
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int prefix[n+1];
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
    for(int i=0;i<n;i++){
        printf("%d ",prefix[i]);
    }
    return 0;
}