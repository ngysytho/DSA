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

using namespace std;

#define ll long long


class Solution {
public:
// Input: m = 3, n = 7
// Output: 28

    int uniquePaths(int m, int n) {
        if(n == 1 && m == 1) return 1;
        vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
        dp[0][0] = 0;
        dp[1][1] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(dp[i - 1][j] + dp[i][j - 1] == 0 && (i != 1 || j != 1)){
                    dp[i][j]++;
                }else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                
            }
        }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
                
        //         cout << dp[i][j] <<" ";
                
        //     }
        //     cout << endl;
        // }
        return dp[n][m];
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        return dfs(m, n, 1, 1);
    }

    int dfs(int m, int n, int i, int j){
        if(i >= m || j >= n) return 0;
        if(i == m && j == n) return 1;
        return dfs(m, n, i + 1, j) + dfs(m, n, i, j + 1);
    }
};


class Solution {
public:
    vector<vector<int>> v;
    int uniquePaths(int m, int n) {
        v.resize(n + 2, vector<int>(m + 2, -1));
        dfs(n, m, 1, 1, v);
        return v[0][0];
    }

    int dfs(int& n, int& m, int i, int j, vector<vector<int>>& v){
        if(i > n || j > m) return;
        if(i == n && j == m) return 1;

        if(v[i][j] != -1) return v[i][j];
        v[i][j] = dfs(n, m, i + 1, j, v) + dfs(n, m, i, j + 1, v);
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n + 1, 1);

        for(int i = 1; i <= m; i++){
            vector<int> newRow(n + 1, 1);
            for(int j = 2; j <= n; j++){
                newRow[j] = row[j] + newRow[j - 1];
            }
            row = newRow;
        }
        return row[n];

    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 1);

        for(int i = 2; i <= m; i++){
            for(int j = 2; j <= n; j++){
                dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        int t = m + n - 2;

        if(n > m) swap(n, m);

        int j = 1;
        long long ans = 1;
        for(int i = m; i <= t; i++){
            ans *= i;
            ans /= j;
            j++;
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
