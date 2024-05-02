#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int countVowel(string str,int n,int ind){
    if(ind==n){
        return;
    }
    if(str[ind]=='A'||str[ind]=='a'||str[ind]=='E'||str[ind]=='e'
    ||str[ind]=='I'||str[ind]=='i'||str[ind]=='O'||str[ind]=='o'||str[ind]=='U'||str[ind]=='u'){
        
    }
}
int main(){
    string str;
    cin>>str;
    int n=str.length();
    countVowel(str,n,0);
}
