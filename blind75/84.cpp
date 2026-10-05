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

//burst force
// l = i - 1, r = i + 1, l >= 0, r < n;
// if(heights[l] && heighs[r] < heighs[i]) break;
// ans = heighs[i], ans += heighs[r] + heighs[l]
// find how many numbers larger than nums[i] from i -> 0 and i -> n
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        for(int i = 0; i < heights.size(); i++){
            int l = i - 1;
            int r = i + 1;
            int res = heights[i];
            while(l >= 0 || r < n){
                if(ans >= heights[i] * n) break;
                if( l >= 0 && heights[l] < heights[i]){
                    l = -1;
                }
                if(r < n && heights[r] < heights[i]){
                    r = n;
                }

                if(r < n) res += heights[i];
                if(l >= 0) res += heights[i];
                r++;
                l--;
            }
            ans = max(ans, res);
        }

        return ans;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n, -1);
        vector<int> right(n, n);

        for(int i = 0; i < n; i++){
            int j = i - 1;

            while(j >= 0 && heights[i] <= heights[j]){
                j = left[j];
            }

            left[i] = j;
        }

        // for(auto& x : left) cout << x << " ";
        // cout << endl;

        for(int i = n - 1; i >= 0; i--){
            int j = i + 1;

            while(j < n && heights[i] <= heights[j]){
                j = right[j];
            }
            right[i] = j;
        }

        // for(auto& x : right) cout << x << " ";
        // cout << endl;

        int ans = 0;

        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            ans = max(ans, heights[i] * width);
        }


        return ans;
    }
};


class MinId_seg{
public:
    vector<int> tree;
    vector<int> A;
    int n;
    const int INF = 1e9;

    MinId_seg(vector<int>& a, int N){
        A = a;
        n = N;
        while(__builtin_popcount(n) != 1){
            A.push_back(INF);
            n++;
        }
        tree.resize(n * 2);
        build();
    }

    void build(){
        for(int i = 0; i < n; i++){
            tree[i + n] = i;
        }

        for(int j = n - 1; j >= 1; j--){
            int a = tree[j << 1];
            int b = tree[(j << 1 )+ 1];

            if(A[a] >= A[b]) tree[j] = b;
            else tree[j] = a;
        }
    }


    void update(int i, int val){
        A[i] = val;

        for(int j = (i + n) >> 1; j >= 1; j >>=1){
            int a = tree[j<<1];
            int b = tree[(j<<1) + 1];

            if(A[a] >= A[b]) tree[j] = b;
            else tree[j] = a;
        }
    }


    int query(int ql, int qr){
        return query(1, 0, n - 1, ql, qr);
    }


    int query(int node, int l, int r, int ql, int qr){
        if(ql > r || qr < l ) return INF;

        if(l >= ql && r <= qr) return tree[node];

        int a = query(node<<1, l, (l + r) / 2, ql, qr);
        int b = query((node<<1) + 1,( (l + r)>>1) + 1, r, ql, qr);
        if(a == INF) return b;
        if(b == INF) return a;

        return A[a] >= A[b] ? b : a;
    }
};


class Solution {
public:

    int getMax(vector<int>& nums, int l, int r, MinId_seg& st){
        if(l > r) return 0;
        if(l == r) return nums[l];

        int minId = st.query(l, r);

        return max(max(getMax(nums, l, minId - 1, st), getMax(nums, minId + 1, r, st)), nums[minId] * (r - l + 1));
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        MinId_seg st(heights, n);

        return getMax(heights, 0, n - 1, st);

    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //[2,1,5,6,2,3]
        int ans = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int j = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;

                ans = max(ans, heights[j] * width);
            }
            st.push(i);
        }

        return ans;
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
