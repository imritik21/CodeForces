#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void stockSpan(vector<int>& stock, vector<int>& span){
    stack<int> st;
    span[0]=1;
    st.push(0);
    for(int i=1;i<stock.size();i++){
        int currPrice=stock[i];

        while(!st.empty() && currPrice>stock[st.top()]){
            st.pop();
        }

        if(st.empty()){
            span[i]=i+1; // last me i+1
        }
        else{
            int prevHigh = st.top();
            span[i]=i-prevHigh;
        }
        st.push(i); /// end me index push kro
    }
}
int main(){
    vector<int> stock = {100,80,60,70,60,85,100};
    int n = stock.size();
    vector<int> span(n);
    stockSpan(stock,span);

    for(int i=0;i<span.size();i++) cout<<span[i]<<" ";
}
