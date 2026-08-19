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
    int rob(vector<int>& nums) {
        //Input: nums = [2,1,1,2]
        // Output: 12

        int n = nums.size();
        vector<int> dp = nums;

        int res = -1;
        for(int i = 0; i < n; i++){
            int temp = dp[i];
            for(int j = 0; j < i - 1; j++){
                temp = max(dp[j] + dp[i], temp);
            }
            dp[i] = temp;
            res = max(res, dp[i]);
        }
        //for(auto x : dp) cout << x << " ";
        return res;
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;

        for(int i = 0; i < nums.size(); i++){
            if(i & 1){
                a += nums[i];
            }else b += nums[i];
        }
        return a > b ? a : b;
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        priority_queue<int> q;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        int tem1 = nums[0], tem2 = nums[1],res = 0;
        q.push(0);
        for(int i = 2; i < nums.size(); i++){
             //Input: nums = [2,1,1,2, 2, 2, 2, 2]
            q.push(tem1);
            int tem4 = tem2;
            tem1 = tem2;

            res = max(res, nums[i] + q.top());
            tem2 = res;
        }
        return res;
    }
};


class Solution {
public:

    int dfs(vector<int>& nums, vector<int>& memo, int i){
        if(i >= nums.size()) return 0;
        
        if(memo[i] != -1) return memo[i];

        memo[i] = max(dfs(nums, memo, i + 1), nums[i] + dfs(nums,memo, i + 2));
        return memo[i];
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size() + 2, -1);

        return dfs(nums, memo, 0);
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int a, b;
        if(nums.size() <= 1) return nums[0];
        a = nums[0];
        b = max(nums[0], nums[1]);

        int ans = b;

        for(int i = 2; i < nums.size(); i++){
            ans = max(b, a + nums[i]);
            a = b;
            b = ans;
        }
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
