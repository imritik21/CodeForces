#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int x=A>B?A:B;
    int x1=x>C?x:C;
    int y=A<B?A:B;
    int y1=y<C?y:C;
    int minVal=y<y1?y:y1;
    int maxVal=x>x1?x:x1;
    cout<<minVal<<" "<<maxVal;
}