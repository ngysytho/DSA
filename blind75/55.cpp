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
    bool canJump(vector<int>& nums) {
        //[2,3,1,1,4]
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        if(nums[0] != 0) dp[0] = true;
        else return false;

        for(int i = 0; i < n; i++){
            if(dp[i]){
                for(int j = 1; j <= nums[i]; j++){
                    dp[i + j] = true;
                    if(j == n - 1) return true;
                }
            }
        }
        return dp[n - 1];
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        //[2,3,1,1,4]
        //0 1 2 3 4
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        
        

    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
