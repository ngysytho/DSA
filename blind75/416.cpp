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
#include <list>

using namespace std;

#define ll long long


class Solution {
public:
    
    bool dfs(vector<int>& nums, int sum, int tempSum, int i){
        if(sum < tempSum)return 0;
        if(sum == tempSum) return true;

        for(int j = i; j < nums.size(); j++){
            tempSum += nums[j];
            if (dfs(nums, sum, tempSum, j + 1)) return true;
            tempSum -= nums[j];
        }

        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto& x : nums) sum += x;
        if(sum&1) return false;

        sum /= 2;

        return dfs(nums, sum, 0, 0);
    }
};



class Solution {
public:
    
    int memo[201][20002];


    bool dfs(int& sum, vector<int>& nums, int temp, int i){
        if(temp > sum || i >= nums.size()) return false;

        if(temp == sum) return true;

        if(memo[i][temp] != -1) return memo[i][temp];


        if(dfs(sum, nums, temp + nums[i], i + 1)){
            return memo[i][temp] = 1;
        }

        if(dfs(sum, nums, temp, i + 1)){
            return memo[i][temp] = 1;
        }

        return memo[i][temp] = 0;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto& x : nums) sum += x;
        if(sum&1) return false;

        sum /= 2;
        memset(memo, -1, sizeof(memo));

        return dfs(sum, nums, 0, 0);
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
