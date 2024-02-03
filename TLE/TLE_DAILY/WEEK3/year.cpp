#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n+1;i<10000;i++){
        int freq[10];
        for (int j = 0; j<10; j++)
        {
            freq[j]=0;
        }
        int year=i;
        while(year>0){
            int digit=year%10;
            freq[digit]++;
            year/=10;
        }
        int flag=0;
        for(int i=0;i<10;i++){
            if(freq[i]>1){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<i<<endl;
            break;
        }
    }
 }