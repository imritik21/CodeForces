#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        char A[3][3];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>A[i][j];
            }
        }
        int countA=0;
        int countB=0;
        int countC=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(A[i][j]=='A'){
                    countA++;
                }
                else if(A[i][j]=='B'){
                    countB++;
                }
                else if(A[i][j]=='C'){
                    countC++;
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(A[i][j]=='?' && countA!=3){
                    cout<<"A"<<endl;
                }
                else if(A[i][j]=='?' && countB!=3){
                    cout<<"B"<<endl;
                }
                else if(A[i][j]=='?' && countC!=3){
                    cout<<"C"<<endl;
                }
            }
        }
    }
}