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



//iterate from n->i and 1->i
//find t = min(max(a[n->i] && a[1->i]))
//the difference of sum += max(0, t - a[i])
// using prefix and suffix to store maximum number from 1->i and n -> i
// => t = min(max(prefix[i - 1], suffix[i + 1]))
// => sum = max(0, t - a[i])

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, 0), suffix(n, 0);

        prefix[0] = height[0];
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        suffix[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i--){
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        int ans = 0;

        for(int i = 1; i < n - 1; i++){
            int t = min(prefix[i - 1], suffix[i + 1]);
            //cout << t << " " << t - height[i] << endl;
            ans += max(0, t - height[i]);
        }

        return ans;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = height[0];
        int n = height.size();

        int rightMax = height[n - 1];

        int ans = 0;
        int left = 0, right = n - 1;
        while(left < right){
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                ans += (leftMax - height[left]);
            }
            else{
                right--;
                rightMax = max(rightMax, height[right]);
                ans += (rightMax - height[right]);
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
