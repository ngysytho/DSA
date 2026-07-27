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

using namespace std;

#define ll long long
class Solution {
public:
    int maxProduct_wrong(vector<int>& nums) {
        int ans = -1e9;

        vector<int> mp(nums.size());
        mp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            mp[i] = mp[i-1]* nums[i];
        }
        int left = 0, right = nums.size() - 1;
        ans = max(ans, mp[right]);
        while(left < right){
            if(left == 0){
                if(mp[right] / nums[right] < mp[right] / nums[left]){
                    right--;
                }else{
                    left++;
                }
            }else{
                if((mp[right] - mp[left - 1]) / nums[right] < (mp[right] - mp[left - 1]) / nums[left]){
                    right--;
                }else{
                    left++;
                }
            }
        }
    }

    int maxProduct_twopoint(vector<int>& nums) {
        //[2, -3, 0, -2, 4]
        vector<vector<int>> v;
        int ans = INT_MIN;
        vector<int> curr;
        for(auto x : nums){
            ans = max(ans, x);
            if(x == 0){
                v.push_back(curr);
                curr.clear();
            }else{
                curr.push_back(x);
            }
        }
        if(!curr.empty()) v.push_back(curr);
        for(auto x : v){
            int neg = 0;
            int prod = 1;
            for(auto x1 : x){
                if(x1 < 0) neg++;
            }
            int need = (neg % 2 == 0) ? neg : neg-1;
            neg = 0;

            for(int i = 0, j = 0; i < x.size(); i++){
                prod *= x[i];
                if(x[i] < 0){
                    neg++;
                    while(neg > need){
                        prod /= x[j];
                        if(x[j] < 0) neg--;
                        j++;
                    }
                }
                if(j <= i ) ans = max(ans, prod);
            }
        }
        return ans;
    }

    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i = 0; i < nums.size() - 1; i++){
            int curr = nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                curr *= nums[j];
                ans = max(ans, curr);
            }
        }
        if(nums.size() == 1) return nums[0];
        return ans;
    }

    int maxProduct_dp(vector<int>& nums) {
        int ans = nums[0];
        int prefix = 0, suffix = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            prefix = nums[i] * (prefix == 0 ? 1 : prefix);
            suffix = nums[n - 1 - i] * (suffix == 0? 1 : suffix);
            ans = max(max(ans, prefix), suffix);
        }
        return ans;

    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;

    int n; cin>> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    Solution sol;
    cout << sol.maxProduct(v);
}
