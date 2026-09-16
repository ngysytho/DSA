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
    int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size();
        int m = text2.size();
        int res = 0;
        unordered_map<char, int> mp;
        for(auto& x : text1) mp[x]++;

        for(int x = 0; x < m; x++){
            int res1 = 0;
            unordered_map<char,int> mp1 = mp;
            for(int i = 0, j = x; i < n && j < m;){
                
                if(mp1[text2[j]]){
                    res1++;
                    while(text2[j] != text1[i]){
                        mp1[text1[i]]--;
                        i++;
                    }
                    mp1[text1[i]]--;
                    i++;
                    j++;
                }else{
                    j++;
                }
            }
            res = max(res, res1);
        }
        
        return res;
    }
};



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        dp[n][m] = 0;

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
                }else{
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};




class Solution {
public:
    vector<vector<int>> memo;

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        memo.assign(m, vector<int>(n, -1));
        return dfs(text1, text2, 0, 0);
    }

    int dfs(string& text1, string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + dfs(text1, text2, i + 1, j + 1);
        } else {
            memo[i][j] = max(dfs(text1, text2, i + 1, j),
                            dfs(text1, text2, i, j + 1));
        }
        return memo[i][j];
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
