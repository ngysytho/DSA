#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define ll long long


class Solution {
public:
    vector<vector<int>> threeSum_wrong(vector<int>& nums) {
        set<vector<int>> ans1;
        unordered_map<int, int> mp;
        for(auto x : nums) mp[x]++;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                int ans3 = nums[i] + nums[j];
                if(ans3 > 0) break;
                if(mp[abs(ans3)] == true && (abs(ans3) > nums[j] && mp[abs(ans3)] >1 )){
                    ans1.insert({nums[i], nums[j], abs(ans3)});
                }
            }
        }
        vector<vector<int>> ans;
        for(auto x : ans1) ans.push_back(x);
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;

        for(int i = 0; i < nums.size() - 2; i++){
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    //ans1.insert({nums[i], nums[left], nums[right]});
                    output.push_back({nums[i], nums[left], nums[right]});
                    int tempIndex1 = left, tempIndex2 = right;
                    while(left < right && nums[left] ==  nums[tempIndex1]) left++;
                    while(left < right && nums[right] == nums[tempIndex2]) right--;
                }
                else if(sum < 0){
                    left++;
                }
                else right--;
                while(i + 1 < nums.size() && nums[i+1] == nums[i])i++;
            }
        }


        // vector<vector<int>> ans;
        // for(auto x : ans1) ans.push_back(x);
        return output;
    }
};

class Solution1 {
    struct Freq {
        uint64_t data[(100'001 + 15) / 16] = {};

        inline uint64_t get(uint x, uint sign) const {
            uint shift = ((x & 15) << 2) | (sign << 1);
            return (data[x >> 4] >> shift) & 3;
        }

        inline void add(uint x, uint sign) {
            uint i = x >> 4;
            uint shift = ((x & 15) << 2) | (sign << 1);
            auto v = 3 & ~(data[i] >> shift);
            data[i] += (uint64_t)(!!v) << shift;
        }
    };

public:
    vector<vector<int>> threeSum_1(vector<int>& nums) {
        Freq freq;
        vector<vector<int>> result;
        int minv = nums[0];
        int maxv = nums[0];
        for (int v : nums) {
            minv = min(minv, v);
            maxv = max(maxv, v);
            freq.add(abs(v), v < 0);
        }
        // case (0, 0, 0)
        if (freq.get(0, 0) > 2) {
            result.push_back({0, 0, 0});
        }
        // early exit
        if (minv >= 0 || maxv <= 0) {
            return result;
        }
        // normalize minv and shrink search space
        minv = min(-minv, maxv * 2);
        maxv = min(maxv, minv * 2);
        // collect unique negative and positive values
        vector<int> neg;
        neg.reserve(nums.size());
        for (int v = 1; v <= minv; v++) {
            if (freq.get(v, 1) > 0) {
                neg.push_back(v);
            }
        }
        vector<int> pos;
        pos.reserve(nums.size());
        for (int v = 1; v <= maxv; v++) {
            if (freq.get(v, 0) > 0) {
                pos.push_back(v);
            }
        }
        // case (-a, 0, +a)
        if (freq.get(0, 0) > 0) {
            for (int a : neg) {
                if (freq.get(a, 0) > 0) {
                    result.push_back({-a, 0, a});
                }
            }
        }
        uint nlen = neg.size(), plen = pos.size();
        for (uint i = 0; i < nlen && neg[i] * 2 <= maxv; i++) {
            int a = neg[i];
            // case (-a, -a, +2a)
            if (int c = 2 * a; freq.get(a, 1) > 1 && freq.get(c, 0) > 0) {
                result.push_back({-a, -a, c});
            }
            // case (-b, -a, +a+b)
            for (uint j = i + 1; j < nlen && neg[j] + a <= maxv; j++) {
                int b = neg[j];
                if (int c = a + b; freq.get(c, 0) > 0) {
                    result.push_back({-b, -a, c});
                }
            }
        }
        for (uint i = 0; i < plen && pos[i] * 2 <= minv; i++) {
            int a = pos[i];
            // case (-2a, +a, +a)
            if (int c = 2 * a; freq.get(a, 0) > 1 && freq.get(c, 1) > 0) {
                result.push_back({-c, a, a});
            }
            // case (-a-b, +a, +b)
            for (uint j = i + 1; j < plen && pos[j] + a <= minv; j++) {
                int b = pos[j];
                if (int c = a + b; freq.get(c, 1) > 0) {
                    result.push_back({-c, a, b});
                }
            }
        }
        return result;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> v(n + 1);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    Solution sol;
    vector<vector<int>> ans;
    ans = sol.threeSum(v);

    for(vector<int> x : ans){
        for(auto m : x){
            cout << m << " ";
        }
        cout << endl;
    }
}