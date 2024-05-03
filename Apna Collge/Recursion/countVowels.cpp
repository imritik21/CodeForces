#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void countVowel(string str,int& count,int ind){
    if(ind==str.length()){
        return ;
    }
    if(str[ind]=='A'||str[ind]=='a'||str[ind]=='E'||str[ind]=='e'
    ||str[ind]=='I'||str[ind]=='i'||str[ind]=='O'||str[ind]=='o'||str[ind]=='U'||str[ind]=='u'){
        count++;
    }
    countVowel(str,count,ind+1);
}
int main(){
    string str;
    cin>>str;
    int n=str.length();
    int count=0;
    countVowel(str,count,0);
    cout<<count<<endl;
}
