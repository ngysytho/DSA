#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution{
    public:
        int longestConsecutive1(vector<int>& nums){
            int n = nums.size();
            if(n == 0) return 0;
            int ans = 1;
            int res = 1;
            set<int> se;
            for(int x : nums) se.insert(x);
            int index = 0;
            int firstnum = 0;
            for(int x : se){
                if(index = 0) firstnum = x;
                else if(x - firstnum == 1){
                    cout << x << " ";
                    res++;
                    index = 1;
                    firstnum = x;
                }
                else{
                    index = 1;
                    res = 1;
                    firstnum = x;
                }
                ans = max(ans, res);
            }
            return ans;
        }

        int longestConsecutive(vector<int>& nums){
            if(nums.size() <= 1){
                return nums.size();
            }

            
            sort(nums.begin(), nums.end());
            int lsg = nums[0];
            int res = 1;
            int c = 1;
            for(int i = 1; i < nums.size(); i++){
                if(nums[i] == lsg + 1){
                    c++;
                }
                else if(lsg == nums[i]){
                    continue;
                }
                else{
                    c = 1;
                }
                res = max(c, res);
                lsg = nums[i];
            }
            return res;
        }
};
vector<int> v;

int main(){
    Solution sol;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    cout << sol.longestConsecutive(v);
}