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


//segment tree
class MinIdx_Segtree {
public:
    int n;
    const int INF = 1e9;
    vector<int> A;
    vector<int> tree;
    MinIdx_Segtree(int N, vector<int>& a) {
        this->n = N;
        this->A = a;
        while (__builtin_popcount(n) != 1) {
            A.push_back(INF);
            n++;
        }
        tree.resize(2 * n);
        build();
    }

    void build() {
        for (int i = 0; i < n; i++) {
            tree[n + i] = i;
        }
        for (int j = n - 1; j >= 1; j--) {
            int a = tree[j<<1];
            int b = tree[(j<<1) + 1];
            if(A[a]<=A[b])tree[j]=a;
            else tree[j] = b;
        }
    }

    void update(int i, int val) {
        A[i] = val;
        for (int j = (n + i) >> 1; j >= 1; j >>= 1) {
            int a = tree[j<<1];
            int b = tree[(j<<1) + 1];
            if(A[a]<=A[b])tree[j]=a;
            else tree[j] = b;
        }
    }

    int query(int ql, int qh) {
        return query(1, 0, n - 1, ql, qh);
    }

    int query(int node, int l, int h, int ql, int qh) {
        if (ql > h || qh < l) return INF;
        if (l >= ql && h <= qh) return tree[node];
        int a = query(node << 1, l, (l + h) >> 1, ql, qh);
        int b = query((node << 1) + 1, ((l + h) >> 1) + 1, h, ql, qh);
        if(a==INF)return b;
        if(b==INF)return a;
        return A[a]<=A[b]?a:b;
    }
};

class Solution {
public:
    int getMaxArea(vector<int>& heights, int l, int r, MinIdx_Segtree& st) {
        if (l > r) return 0;
        if (l == r) return heights[l];

        int minIdx = st.query(l, r);
        return max(max(getMaxArea(heights, l, minIdx - 1, st), getMaxArea(heights, minIdx + 1, r, st)), (r - l + 1) * heights[minIdx]);
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        MinIdx_Segtree st(n, heights);
        return getMaxArea(heights, 0, n - 1, st);
    }
};



class SegmentTree {
public:
    vector<int> tree;
    vector<int> A;
    int n;

    SegmentTree(vector<int>& a) {
        A = a;
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int node, int l, int r) {
        // Base case: leaf
        if (l == r) {
            tree[node] = l;  // lưu index
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        int leftIdx = tree[node * 2];
        int rightIdx = tree[node * 2 + 1];

        if (A[leftIdx] <= A[rightIdx])
            tree[node] = leftIdx;
        else
            tree[node] = rightIdx;
    }

    int query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }

    int query(int node, int l, int r, int ql, int qr) {
        // Không giao nhau
        if (qr < l || ql > r)
            return -1;

        // Nằm hoàn toàn trong query
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        int left = query(node * 2, l, mid, ql, qr);
        int right = query(node * 2 + 1, mid + 1, r, ql, qr);

        if (left == -1) return right;
        if (right == -1) return left;

        return A[left] <= A[right] ? left : right;
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
