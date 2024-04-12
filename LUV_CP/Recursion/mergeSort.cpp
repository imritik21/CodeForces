#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int N = 1e5+10;
int a[N]; // array pass na krna pade 
void merge(int l,int r,int mid){
    int l_sz = mid - l + 1; // left array ka size
    int L[l_sz+1]; // breaking into 2 array from between +1 taaki INT_MAX
    int r_sz = r-mid; // right array ka size r-(mid+1)-1
    int R[r_sz+1];
    for(int i=0;i<l_sz;i++){
        L[i]=a[i+l]; // l phla ele hai left array ka
    }
    for(int i=0;i<r_sz;i++){
        R[i]=a[i+mid+1]; // mid+1 phla ele hai right array ka
    }
    L[l_sz]=R[r_sz]=INT_MAX; // dono array ke end me maximum to avoid while loop
    // compare krte waqt INT_MAX se chota hoga to rest ele apne aap fill 
    int l_i=0; // left  array me jaane wala index
    int r_i=0;
    // ye loop merge kr rha hai
    for(int i=l;i<=r;i++){
        if(L[l_i]<= R[r_i]){
            a[i]=L[l_i];
            l_i++;
        }
        else{
            a[i]=R[r_i];
            r_i++;
        }
    }
}
// merge sort recursion ke using in O(logn) kyuki half half every time
void mergeSort(int l,int r){
    if(l==r) return;
    int mid = (l+r)/2;
    //left array ko sort kro
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    // dono sort ho gya ab merge krdo
    merge(l,r,mid); // merge O(N) tc me
    // base cond - jb ek hi ele l==r 

}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    mergeSort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
