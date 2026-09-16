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

    int ans(vector<int>& nums, int i, int n, vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] =  max(ans(nums, i + 1, n,dp), ans(nums, i + 2, n, dp) + nums[i]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(ans(nums, 1, n, dp1),ans(nums, 0, n - 1, dp2));
    }
};
