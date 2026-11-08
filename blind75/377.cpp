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
    int ans = 0;
    void dfs(vector<int>& nums, int target, int sum){
        if(sum > target) return;
        if(target == sum){
            ans++;
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            dfs(nums, target, sum);
            //dfs(nums, target, nums[i]);
        }

        return;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dfs(nums, target, 0);
        return ans;
    }
};





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
