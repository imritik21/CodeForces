#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    map<int,multiset<string>> mp;
    for(int i=0;i<n;i++){
        string name;
        int marks;
        cin>>name>>marks;
        mp[-1*marks].insert(name);
    }
    // reverse iterate the map
    // auto last_it = mp.end();
    // last_it--;
    // while(true){
    //     auto &nameSet = (*last_it).second;
    //     int marks = (*last_it).first;
    //     for(auto &names : nameSet){
    //         cout<<names<<" "<<marks<<endl;
    //     }
    //     if(last_it==mp.begin())break;
    //     last_it--;
    // }
    for(auto &marks_students:mp){
        auto &students = marks_students.second;
        int marks = marks_students.first;
        for(auto &name:students){
            cout<<name<<" "<<-1*marks<<endl;
        }
    }
    return 0;
}
