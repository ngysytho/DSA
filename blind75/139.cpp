#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
private:
    bool wordBreak_burstForce(string s, unordered_set<string>& se){
        if(s.size() == 0) return true;
        for(int i = 0; i < s.size(); i++){
            if(se.count(s.substr(0, i + 1)) && wordBreak_burstForce(s.substr(i+1), se)) return true;
        }
        return false;
    }

    bool wordBreak_burstForce_2(string s, unordered_set<string>& se, int start){
        if(start == s.size()) return true;

        for(int i = start; i < s.size(); i++){
            if(se.count(s.substr(start, i - start + 1)) && wordBreak_burstForce_2(s, se, i + 1)){
                return true;
            }
        }
        return false;
    }

    bool wordBreak_branch(string s, unordered_set<string>& se, vector<int>& visited, int start) {
        if(start == s.size()) return true;

        if(visited[start] != -1) return visited[start];

        for(int i = start; i < s.size(); i++){
            if(se.count(s.substr(start, i - start + 1)) && wordBreak_branch(s, se, visited, i+1)){
                visited[start] = true;
                return true;
            }
        }
        return visited[start] = false;
    }

public:


    bool wordBreak_burstForce(string s, vector<string>& wordDict) {
        unordered_set<string> se(wordDict.begin(), wordDict.end());
        return wordBreak_burstForce(s, se);
    }

    bool wordBreak_burstForce_2(string s, vector<string>& wordDict) {
        unordered_set<string> se(wordDict.begin(), wordDict.end());
        return wordBreak_burstForce_2(s, se, 0);
    }

    bool wordBreak_branch(string s, vector<string>& wordDict) {
        unordered_set<string> se(wordDict.begin(), wordDict.end());
        vector<int> visited(s.size(), -1);
        return wordBreak_branch(s, se, visited, 0);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> se;
        for(string x : wordDict) se.insert(x);

        vector<int> dp(s.size() + 1, 0);

        dp[0] = true;

        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && se.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(){
    Solution sol;
    string s;
    cin >> s;
    int n; cin >> n;
    vector<string> v;
    for(int i = 1; i <= n; i++){
        string a;
        cin >> a;
        v.push_back(a);
    }

    cout << sol.wordBreak_burstForce(s, v);
}