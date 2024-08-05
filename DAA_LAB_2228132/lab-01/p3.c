#include<stdio.h>
const int N = 1e3+1;
int main() {
    // Your code here
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int hash[N];
    for(int i=1;i<N;i++){
        hash[i]=0;
    }
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    int dup=0;
    for(int i=1;i<N;i++){
        if(hash[i]>1)dup++;
    }
    printf("%d \n",dup);
    int mostRep = -1;
    int mostRepCount = 0;
    for (int i = 1; i < N; i++) {
        if (hash[i] > mostRepCount) {
            mostRep = i;
            mostRepCount = hash[i];
        }
    }
    printf("%d ",mostRep);
    return 0;
}