#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}
