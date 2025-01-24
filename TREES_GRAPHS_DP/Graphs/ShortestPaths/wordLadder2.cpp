#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<vector<string>> AllLadderSequence(string begin,string end,vector<string>& wordList){
    set<string> st(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    q.push({begin});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(begin);
    int level=0;
    vector<vector<string>> ans;

    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        // erase all words that has been used
        // in prev levels after using it ssame as removing from set
        // here instead using it for all ele in that level and then deleting
        if(vec.size()>level){
            level++;
            for(auto& it:usedOnLevel){
                st.erase(it);
            }
        }
        string word = vec.back();
        if(word==end){
            // if first occurance
            if(ans.size()==0){
                ans.push_back(vec);
            }
            else if(ans[0].size()==vec.size()){
                ans.push_back(vec);
            }
        }

        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string begin = "bat";
    string end = "coz";
    vector<string> wordList = {"pat","bot","pot","poz","coz"};
    vector<vector<string>> res = AllLadderSequence(begin,end,wordList);
    for(int i=0;i<res.size();i++){
        for(auto& ele:res[i])cout<<ele<<" ";
        cout<<endl;
    }
    return 0;
}
