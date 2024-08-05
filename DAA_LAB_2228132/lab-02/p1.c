#include<stdio.h>
int toBin(int n){
    if(n==0) return 0;
    else 
    return (n%2+10*toBin(n/2));
}
int main() {
    // Your code here
    int n;
    printf("Enter no of contents ");
    scanf("%d",&n);
    int decArr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&decArr[i]);
    }
    int binArr[n] ;
    for(int i=0;i<n;i++) binArr[i]=0;
    for(int i=0;i<n;i++){
        binArr[i]=toBin(decArr[i]);
    }
    for(int i=0;i<n;i++){
        printf("Bin form of %d is %d \n",decArr[i],binArr[i]);
    }
    // int res = toBin(n);
    // printf("%d ",res);
    return 0;
}