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
    struct N{
        long long len = 0, pre=0, suf = 0, zero = 0;  
    };

    vector<N> st;

    int n;

    N merge(N a, N b){
        if(!a.len) return b;
        if(!b.len) return a;

        N c;

        c.len = a.len + b.len;
        c.pre = (a.pre == a.len ? a.len + b.pre : a.pre);
        c.suf = (b.suf == b.len? b.len + a.suf : b.suf);
        c.zero = a.zero + b.zero + a.suf*b.pre;
        return c;
    }

    void update(int p, int l, int r, int x, int val){
        if(l == r){
            st[p] = {1, !val, !val, !val};
            return;
        }

        int m = (l + r) / 2;

        if(x <=m) update(p * 2, l, m, x, val);
        else update(p * 2 + 1, m + 1, r, x, val);

        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    N query(int p, int l, int r, int L, int R){
        if(R < l || r < L) return {};
        if(L <= l && r <= R) return st[p];

        int m = (l + r) / 2;
        return merge(query(p * 2, l, m, L, R), query(p*2 + 1, m + 1, r, L, R));
    }

    


    
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        st.resize(4*n);

        auto peak = [&](int i){
            return i > 0 && i + 1 < n && nums[i] > nums[i - 1] && nums[i] > nums[i + 1];  
        };

        for(int i = 0; i < n; i++) update(1, 0, n -1, i, peak(i));
        vector<long long> ans;

        for(auto &q : queries){
            if(q[0] == 1){
                int l = q[1] + 1, r = q[2] -1;

                if(l > r){
                    ans.push_back(0);
                    continue;
                }
                N x = query(1,0, n - 1, l, r);

                ans.push_back(x.len* (x.len + 1)/ 2 - x.zero);
            }else{
                int i = q[1];
                nums[i] = q[2];

                for(int j = i - 1; j <= i + 1; j++){
                    if(j >= 0 && j < n){
                        update(1, 0, n-1, j, peak(j));
                    }
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
