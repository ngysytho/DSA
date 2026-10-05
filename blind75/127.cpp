#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <climits>
#include <utility>
#include <map>
#include <cmath>
#include <bitset>
#include <bit>
#include <cstdint>

using namespace std;

#define ll long long



class Solution {
public:

    int dfs(map<string,vector<string>>& v,int i, vector<string>& wordList, string& beginWord, string& endWord, string t, unordered_set<string>& st){
        if(t == endWord) return i;

        int ans = 1e9;
        for(auto& x : v[t]){
            if(st.find(x) != st.end()) continue;

            st.insert(x);
            ans = min(ans, dfs(v, i + 1, wordList, beginWord, endWord, x, st));

            st.erase(x);
        }

        return ans;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> v;

        for(int i = 0; i < wordList.size(); i++){
            int different = 0;
            
            for(int j = 0; j < beginWord.size(); j++){
                if(beginWord[j] != wordList[i][j]) different++;
                if(different >= 2) break;
            }
            if(different == 1) v[beginWord].push_back(wordList[i]);
        }

        for(int i = 0; i < wordList.size(); i++){
            for(int j = i + 1; j < wordList.size(); j++){
                int different = 0;
                for(int c = 0; c < wordList[i].size(); c++){
                    if(wordList[i][c] != wordList[j][c]) different++;
                    if(different >= 2) break;
                }
                if(different == 1){
                    v[wordList[i]].push_back(wordList[j]);
                    v[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        unordered_set<string> st;
        st.insert(beginWord);
        int ans = dfs(v, 1, wordList, beginWord, endWord, beginWord, st);
        return ans == 1e9 ? 0 : ans;
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> v;

        for(int i = 0; i < wordList.size(); i++){
            int different = 0;
            
            for(int j = 0; j < beginWord.size(); j++){
                if(beginWord[j] != wordList[i][j]) different++;
                if(different >= 2) break;
            }
            if(different == 1) v[beginWord].push_back(wordList[i]);
        }

        for(int i = 0; i < wordList.size(); i++){
            for(int j = i + 1; j < wordList.size(); j++){
                int different = 0;
                for(int c = 0; c < wordList[i].size(); c++){
                    if(wordList[i][c] != wordList[j][c]) different++;
                    if(different >= 2) break;
                }
                if(different == 1){
                    v[wordList[i]].push_back(wordList[j]);
                    v[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        unordered_set<string> st;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        

        while(!q.empty()){
            string s = q.front().first;
            int i = q.front().second;
            st.insert(s);
            q.pop();
            for(auto& x : v[s]){
                if(st.find(x) != st.end()) continue;
                if(x == endWord) return i + 1;
                q.push({x, i + 1});
            }
        }
        return 0;
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
