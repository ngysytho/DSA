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

using namespace std;

#define ll long long

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> v(nums.size() + 2, 0);

        int ans = nums[0];
        for(int i = 1; i <= nums.size(); i++){
            v[i] = v[i] + v[i - 1];
        }

        for(int i = 1; i <= nums.size(); i++){
            for(int j = i; j <= nums.size(); j++){
                ans = max(ans, v[j] - v[i - 1]);
            }
        }
        return ans;
    }
};



class Solution {
private:
    int dfs(int i, vector<int>& nums, bool flag){
        if(i == nums.size()) return flag ? 0 : INT_MIN;
        if(flag) return max(0, nums[i] + dfs(i + 1, nums, true));
        return max(dfs(i + 1, nums, false), nums[i] + dfs(i + 1, nums, true));
    }
public:
    int maxSubArray(vector<int>& nums) {
        return dfs(0, nums, false);
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> v(nums.size(), vector<int>(2, INT_MIN));
        return dfs(nums, 0, false, v);
    }
private:
    int dfs(vector<int>& nums, int i, bool flag, vector<vector<int>>& v){
        if(i == nums.size()) return flag ? 0 : INT_MIN;
        int f = flag ? 1 : 0;
        if(v[i][f] != INT_MIN) return v[i][f];
        if(flag){
            v[i][f] = max(0, nums[i]+ dfs(nums, i + 1, true, v));
        }else{
            v[i][f] = max(dfs(nums, i + 1, false, v), nums[i] + dfs(nums, i + 1, true, v));
        }
        return v[i][f];
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> v(nums);
        for(int i = nums.size() - 2; i >= 0; i--){
            v[i] = max(nums[i], v[i + 1] + nums[i]);

        }
        return *max_element(v.begin(), v.end());
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curr = nums[0];

        for(int i = 1; i < nums.size(); i++){
            curr = max(nums[i], curr + nums[i]);
            res= max(res, curr);
        }
        return res;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, -1));
        dp[nums.size()][1] = 0;
        dp[nums.size()][0] =  INT_MIN;
        for(int i = nums.size() - 1; i >= 0; i--){
            dp[i][1] = max(nums[i], dp[i + 1][1] + nums[i]);
            dp[i][0] = max(dp[i + 1][0], dp[i][1]);
        }
        return dp[0][0];
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
