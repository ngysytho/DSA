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


class SegTree{
public:
    vector<int> tree;
    int n;

    SegTree(int N){
        n = N;
        while(n & ( n - 1)){
            n++;
        }
        tree.resize(n * 2);
    }

    void update(int i, int val){
        tree[n + i] = val;
        int j = (n + i) >> 1;

        while(j >= 1){
            tree[j] = max(tree[j << 1], tree[j << 1 | 1]);
            j >>= 1;
        }
    }

    int query(int l, int r){
        if(l > r) return 0;
        int res = INT_MIN;
        l += n;
        r += n + 1;
        while(l < r){
            if(l & 1){
                res = max(res, tree[l]);
                l++;
            }
            if(r & 1){
                r--;
                res = max(res, tree[r]);
            }
            l >>=1;
            r >>= 1;
        }
        return res;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dummy = nums;
        sort(dummy.begin(), dummy.end());
        
        dummy.erase(unique(dummy.begin(), dummy.end()), dummy.end());

        vector<int> v(nums.size() + 5, 0);

        for(int i = 0; i < nums.size(); i++){
            v[i] = lower_bound(dummy.begin(), dummy.end(), nums[i]) - dummy.begin();
        }
        int n = dummy.size();
        SegTree segTree(n);

        int LIS =0;
        for(int num : v){
            int curLis = segTree.query(0, num - 1) + 1;
            segTree.update(num, curLis);
            LIS = max(LIS, curLis);
        }
        return LIS;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}



class FenWickTree{
public:
    int n;
    vector<int> bit;
    FenWickTree(int N){
        n = N;
        bit.resize(n + 5, 0);
    }

    void update(int i, int val){
        i++;
        while(i <= n){
            bit[i] = max(bit[i], val);
            i += i & -i;
        }
    }

    int query(int i){
        i++;
        int res = 0;
        while(i >= 0){
            res= max(res, bit[i]);
            i -= i & -i;
        }
        return res;
    }

};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sortedArr = nums;

        sort(sortedArr.begin(), sortedArr.end());

        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()),sortedArr.end());
        FenWickTree fenwick(sortedArr.size());

        int ans = 1;

        for(int x : nums){
            int rank = lower_bound(sortedArr.begin(), sortedArr.end(),x ) - sortedArr.begin();

            int bestB = rank == 0 ? 0 : fenwick.query(rank - 1);

            int curans = bestB + 1;

            fenwick.update(rank, curans);
            ans = max(ans, curans);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            if(dp.back() < nums[i]){
                dp.push_back(nums[i]);
                continue;
            }

            int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[idx] = nums[i];
        }
        return dp.size();


    }
};
