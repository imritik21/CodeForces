#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
int main() {
    // Your code here
    int a = 5;
    int b = 6;
    printf("%d %d ",a,b);
    swap(&a,&b);
    printf("\n");
    printf("%d %d ",a,b);
    return 0;
}