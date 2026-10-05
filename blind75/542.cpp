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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp = mat;

        vector<vector<int>> dir{{0,1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = dp.size();
        int m = dp[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int d = INT_MAX;
                if(dp[i][j] == 0) continue;
                for(auto& x : dir){
                    int newI = i + x[0];
                    int newJ = j + x[1];

                    if(newI >= 0 && newI < n && newJ >= 0 && newJ < m){
                        d = min(d, dp[i][j] + dp[newI][newJ]);
                    }
                }
                dp[i][j] = d;
            }
        }
        return dp;
    }
};


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n =mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e6));

        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                if(mat[i][j] == 0) dp[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(i < n - 1) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                if(j < m - 1) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }
        }

        return dp;
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
