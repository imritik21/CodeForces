#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    vector<int> arr={ 1,2,3,3,3,5,5,5,5,8};
    //                0 1 2 3 4 5 6 7
    auto bs_it=binary_search(arr.begin(),arr.end(),3);
    auto lb_it=lower_bound(arr.begin(),arr.end(),3);
    int lb_index= lb_it-arr.begin();

    auto up_it=upper_bound(arr.begin(),arr.end(),3);
    int up_index= up_it-arr.begin();
    
    cout<< bs_it<<endl;
    cout<< *lb_it<<endl;
    cout<<"lower bound of 3: "<<lb_index<<endl;
    
    cout<< *up_it<<endl;
    cout<<"upper bound of 3: "<<up_index<<endl;

    string str = "hello world";
    str.push_back('!');
    str+="!!!!!"; // GOOD - O(1)
    str = str + "!"; // BAD - O(N) // bcz its adding and copying

    cout<<str.substr(10,5)<<endl; // 10 is basically starting point and 5 is length you want

    // lets see if you want to find hello in the string
    // return the first occurance
    //
    int index=str.find("o"); // return index else -1
    // now if you want to find next occurance
    cout<<"First occurance of o "<<index<<endl;
    index = str.find("o",index+1);// start searching from index posn
    cout<<"next occurance index: "<<index<<endl;
    cout<<str<<endl;

}
