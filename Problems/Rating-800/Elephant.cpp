/*An elephant decided to visit his friend. It turned out that the elephant's house is 
located at point 0 and his friend's house is located at point x(x > 0) of the coordinate line.
 In one step the elephant can move 1, 2, 3, 4 or 5 positions forward. Determine, what is the
minimum number of steps he need to make in order to get to his friend's house.

Input
The first line of the input contains an integer x (1 ≤ x ≤ 1 000 000) — The coordinate of the
 friend's house.*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int x;
    cin>>x;
    if(x<=5){
        cout<<"1";
    }else if(x%5==0){
        cout<<x/5;
    }
    else{
        cout<<(x/5+1)<<endl;
    }
}