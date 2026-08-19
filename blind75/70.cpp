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
    int climbStairs(int n) {
        vector<int> dp(n + 3, 0);

        dp[0] = 0;
        //0 1 2 3 4
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] += dp[i - 1];
            dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};


class Solution {
public:
    int dfs(int i, int& n, vector<int>& cache){
        if(i >= n) return i == n;

        if(cache[i] != -1) return cache[i];
        return cache[i] = dfs(i + 1, n, cache) + dfs(i + 2, n, cache);
    }

    int climbStairs(int n) {
        vector<int> cache(n + 1, -1);

        return dfs(0, n, cache);
    }
};


class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1;

        for(int i = 0; i < n - 1; i++){
            int temp = one;
            one += two;
            two = temp;
        }
        return one;
    }
};


class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        vector<vector<int>> M = {{1, 1}, {1, 0}};
        vector<vector<int>> result = matrixPow(M, n);

        return result[0][0];
    }

private:
    vector<vector<int>> matrixMult(vector<vector<int>>& A,vector<vector<int>>& B) {
        return {
            {
                A[0][0] * B[0][0] + A[0][1] * B[1][0],
                A[0][0] * B[0][1] + A[0][1] * B[1][1]
            },
            {
                A[1][0] * B[0][0] + A[1][1] * B[1][0],
                A[1][0] * B[0][1] + A[1][1] * B[1][1]
            }
        };
    }

    vector<vector<int>> matrixPow(vector<vector<int>>& M, int p) {
        vector<vector<int>> result = {{1, 0}, {0, 1}};
        vector<vector<int>> base = M;

        while (p > 0) {
            if (p % 2 == 1) {
                result = matrixMult(result, base);
            }

            base = matrixMult(base, base);
            p /= 2;
        }

        return result;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
