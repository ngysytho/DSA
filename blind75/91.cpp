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
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        if(s[0] == '0') return 0;

        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                if(s[i - 1] > '2' || s[i-1] == '0') return 0;
                else dp[i + 1] = dp[i - 1];
            }else{
                if(s[i - 1] == '1'  || s[i - 1] == '2' && s[i] <= '6'){
                    dp[i + 1] = dp[i] + dp[i - 1];
                }else dp[i + 1] = dp[i];
            }
        }//123459
        return dp[n];
    }
};


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        if(s[0] == '0') return 0;

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                if(s[i - 1] > '2' || s[i - 1] == '0')
                    return 0;
                else
                    dp[i + 1] = dp[i - 1];
            }
            else{
                if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')){
                    
                    dp[i + 1] = dp[i] + dp[i - 1];
                }
                else{
                    dp[i + 1] = dp[i];
                }
            }
        }

        return dp[n];
    }
};


class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }

private:
    int dfs(string s, int i, unordered_map<int, int>& dp) {
        if (dp.count(i)) {
            return dp[i];
        }
        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(s, i + 1, dp);
        if (i + 1 < s.size() && (s[i] == '1' ||
            s[i] == '2' && s[i + 1] < '7')) {
            res += dfs(s, i + 2, dp);
        }
        dp[i] = res;
        return res;
    }
};


class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < s.size() && (s[i] == '1' ||
                    s[i] == '2' && s[i + 1] < '7')) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
