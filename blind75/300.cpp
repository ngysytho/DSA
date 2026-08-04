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

private:

    vector<int> momo_dp2;
    int dfs(vector<int>& nums, int i, int j){
        if(i == nums.size()){
            return 0;
        }

        int Lis = dfs(nums, i + 1, j);
        if(j == -1 || nums[j] < nums[i]){
            Lis = max(Lis, 1 + dfs(nums, i + 1, i));
        }
        return Lis;

    }

    int dfs_dp2(vector<int>& nums, int i){
        if(momo_dp2[i] != -1) return momo_dp2[i];

        int lis = 1;
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] < nums[j]){
                lis = max(lis, 1 + dfs_dp2(nums, j));
            }
        }
        return momo_dp2[i] = lis;
    }

public:



    int lengthOfLIS_recursion(vector<int>& nums) {
        return dfs(nums, 0, -1);
    }

    int lengthOfLIS_dp2(vector<int>& nums) {
        momo_dp2.assign(nums.size(), -1);
        int maxLis = 1;

        for(int i = 0; i < nums.size(); i++){
            maxLis = max(maxLis, dfs_dp2(nums, i));
        }
        return maxLis;
    }

    int lengthOfLIS_dp1(vector<int>& nums) {
        vector<int> dp(nums.size() + 5, 1);
        int ans = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
