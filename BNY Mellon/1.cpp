#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;;
    getline(cin,str);
    vector<string> v;
    string curr="";
    for(int i=0;i<str.size();i++){
        if((str[i]<='z' && str[i]>='a')||(str[i]<='Z' && str[i]>='A')){
            curr+=str[i];
        }
        else if(str[i]==' ' && !curr.empty()){
            v.push_back(curr);
            curr="";
        }
    }
    if(!curr.empty()){
        v.push_back(curr);
    }
    cout<<v.size()<<endl;
    for(auto ele: v)cout<<ele<<" ";
    int cnt=0;
    for(auto ele:v){
        if(ele!=" ")cnt++;
    }
    if(cnt&1){
        cout<<(cnt/2)+1<<endl;
    }
    else{
        cout<<cnt/2<<endl;
    }
    return 0;
}
