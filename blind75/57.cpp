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

using namespace std;

#define ll long long

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int n = intervals.size();

        if(n == 0){
            ans.push_back(newInterval);
            return ans;
        }
        int have = -1;
        int start = newInterval[0], last = newInterval[1];
        for(int i = 0; i < n; i++){
            if(have == -1 && last < intervals[i][0]){
                ans.push_back({start, last});
                have = 0;
            }

            if(have == -1 && last >= intervals[i][0] && start <= intervals[i][1]){
                last = max(last, intervals[i][1]);
                start = min(start, intervals[i][0]);
                have = 1;
            }

            if (have == 1 && last >= intervals[i][0]) {
                start = min(start, intervals[i][0]);
                last = max(last, intervals[i][1]);
            }

            if(have == 1 && last < intervals[i][0]){
                ans.push_back({start, last});
                have = 0;
            }
            if(have != 1) ans.push_back(intervals[i]);
        }
        if(have == 1) ans.push_back({start, last});
        if (have == -1) {
            ans.push_back(newInterval);
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }

        int n = intervals.size();
        int target = newInterval[0];
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        intervals.insert(intervals.begin() + left, newInterval);

        vector<vector<int>> res;
        for (const auto& interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
