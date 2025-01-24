#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int LadderLength(string begin,string end,vector<string>&wordList){
    set<string> st(wordList.begin(),wordList.end());
    queue<pair<string,int>> q;
    q.push({begin,1});
    st.erase(begin);

    while(!q.empty()){
        string word = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(word==end){
            return dis;
        }
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    q.push({word,dis+1});
                    st.erase(word);
                }
            }
            word[i]=original;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string begin = "hit";
    string end = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    // find the no of words in the shortest transformation seq from 
    // begin to end
    cout<<LadderLength(begin,end,wordList)<<endl;
    
    return 0;
}
