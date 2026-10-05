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

    vector<vector<int>> ans;


    void dfs(vector<int>& nums, vector<int> v, int n, int i, vector<int> ans1){
        if(i == n){
            ans.push_back(ans1);
            return;
        }

        for(int j = 0; j < n; j++){
            if(v[j]){
                continue;
            }else{
                vector<int> v1 = v;
                v1[j] = 1;
                vector<int> ans2 = ans1;

                ans2.push_back(nums[j]);

                dfs(nums, v1, n, i + 1, ans2);

            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> v(n, 0);
        vector<int> ans1;
        dfs(nums, v, n, 0, ans1);
        return ans;
    }
};

class Solution {
public:

    vector<vector<int>> ans;

    void dfs(vector<int>& nums, vector<int>& visited, vector<int>& res){
        if(res.size() == nums.size()){
            ans.push_back(res);
            return;
        }
// 1->2->3,
        for(int j = 0; j < nums.size(); j++){
            if(visited[j]) continue;

            res.push_back(nums[j]);
            visited[j] = 1;

            dfs(nums, visited, res);
            visited[j] = 0;
            res.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
        vector<int> res;

        dfs(nums,visited, res);

        return ans;
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
