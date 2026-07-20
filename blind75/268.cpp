#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>


using namespace std;


class Solution {
public:
    int missingNumber_1(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] != 1){
                return nums[i - 1] + 1;
            }
        }
        if(nums[0] != 0) return 0; 
        return nums[n - 1] + 1;
    }

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        n;
        int m = (n*(n + 1))/2;
        int sum = 0;

        for(auto x : nums) sum += x;
        return m - sum;
    }

    int missingNumber_xo(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 1; i <= n; i++){
            ans ^= i;
        }

        for(auto x : nums) ans ^= x;
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i++){
        int x; cin>>x;
        v.push_back(x);
    }
    Solution sol;
    cout << sol.missingNumber_xo(v);
}