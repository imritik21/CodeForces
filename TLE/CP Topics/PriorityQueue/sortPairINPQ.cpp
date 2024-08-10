#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
class student{
public:
    int roll;
    string name;
    student(int roll,string name){
        this->roll=roll;
        this->name=name;
    }
};
class compareObj{
public:
    bool operator()(student&s1,student&s2){
        return s1.roll<s2.roll;
    }
};
// class comparePair{
// public:
//     bool operator()(pair<int,int>&p1,pair<int,int>&p2){
//         if(p1.first==p2.first){
//             return p1.second<=p2.second;
//         }
//         return p1.first<p2.first;
//     }
// };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    student s1(10,"ritik");
    student s2(2,"kira");
    student s3(1,"didi");
    student s4(11,"papa");

    vector<student> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);

    sort(v.begin(),v.end(),compareObj());

    for(auto el:v)cout<<el.roll<<" "<<el.name<<endl;


    /// but but but this doesnot apply in 
    // pair of priority queue
    // lets see
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({1,2});
    pq.push({1,3});
    pq.push({0,2});

    // sort(pq.begin(),pq.end(),comparePair());
    cout<<pq.top().first<<" "<<pq.top().second<<endl;
    return 0;
}
