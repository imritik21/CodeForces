#include<stdio.h>
int gcd(int a,int b){
    if(b==0) return a;
    else 
    return gcd(b,a%b);
}
int main() {
    // Your code here
    int n;
    printf("Enter no of contents ");
    scanf("%d",&n);
    int input[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&input[i][j]);
        }
    }
    int output[n] ;
    for(int i=0;i<n;i++) output[i]=0;
    for(int i=0;i<n;i++){
        output[i]=gcd(input[i][0],input[i][1]);
    }
    for(int i=0;i<n;i++){
        printf("Gcd of %d and %d is %d \n",input[i][0],input[i][1],output[i]);
    }
    // int res = toBin(n);
    // printf("%d ",res);
    return 0;
}