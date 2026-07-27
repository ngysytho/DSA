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

    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();
        vector<int> v;
        unordered_map<int, int> mp;
        
        backtracking2(candidates, v, n, target, 0);
        return ans;

    }

    void backtracking2(vector<int>& cand, vector<int>&v, int& n, int target, int i){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0 || i >= n){
            return;
        }
        v.push_back(cand[i]);
        backtracking2(cand, v, n, target - cand[i], i);
        v.pop_back();
        backtracking2(cand, v, n, target, i + 1);
    }

    void backtracking(vector<int>& cand, vector<int>& v, int& n,  int target, int start){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(target < 0){
            return;
        };

        for(int i = start; i < n; i++){
            v.push_back(cand[i]);
            backtracking(cand, v, n, target - cand[i], i);
            v.pop_back();
        }
    }
};

class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);

        dp[0].push_back({});

        for (int num : candidates) {
            for (int sum = num; sum <= target; sum++) {
                for (const vector<int>& combination : dp[sum - num]) {
                    vector<int> newCombination = combination;
                    newCombination.push_back(num);
                    dp[sum].push_back(newCombination);
                }
            }
        }

        return dp[target];
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
