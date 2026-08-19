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
//coins = [1,2,5], amount = 11

class Solution {
public:

    void dfs(vector<int>& coins, long long sum, int& amount,int start, long long& ans, int count){
        if (sum == amount) {
            ans = min(ans, (long long)count);
            return;
        }

        if (sum > amount) return;
        if (count >= ans) return; 
        for(int i = start; i < coins.size(); i++){
            sum += coins[i];
            dfs(coins, sum, amount, i, ans, count + 1);
            sum-=coins[i];
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        long long ans = INT_MAX;
        dfs(coins, 0, amount, 0, ans, 0);
        return ans == INT_MAX? -1: ans;
    }
};


class Solution {
public:

    unordered_map<int, int> mp;
    int dfs(vector<int>& coins, int amount){
        if(amount == 0) return 0;

        int res = INT_MAX;
        if(mp.count(amount)) return mp[amount];
        for(auto& x : coins){
            if(amount - x >= 0){
                int result = dfs(coins, amount - x);
                if(result != INT_MAX){
                    res = min(res, result + 1);
                }
            }
        }
        mp[amount] = res;
        return res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins, amount);
        return res == INT_MAX ? -1 : res;
    }
};



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 3, INT_MAX - 2);
        dp[amount] = 0;
        //if(amount == 0) return -1;

        for(int i = amount; i >= 0; i--){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0){
                    dp[i - coins[j]] = min(dp[i - coins[j]], dp[i] + 1);
                }
            }
        }
        return dp[0] != (INT_MAX - 2) ? dp[0] : -1;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
