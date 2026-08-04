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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //[[1,3],[2,6],[8,10],[15,18]] Output: [[1,6],[8,10],[15,18]]
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>> ans;

        int i = 0;
        for(; i < intervals.size(); i++){
            int second = intervals[i][1];
            int first = intervals[i][0];
            while(i + 1 < intervals.size() && second >= intervals[i + 1][0]){
                second = max(second, intervals[i + 1][1]);
                i++;
            }
            ans.push_back({first, second});
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for(const auto& interval : intervals){
            mp[interval[0]]++;
            mp[interval[1]]--;
        }
        vector<int> interval;
        vector<vector<int>> ans;
        int have = 0;
        for(auto pair : mp){
            if(interval.empty()){
                interval.push_back(pair.first);
            }
            have += pair.second;

            if(have == 0){
                interval.push_back(pair.first);
                ans.push_back({interval});
                have = 0;
                interval.clear();
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int imax = INT_MIN;
        for(const auto& i : intervals){
            imax = max(imax, i[0]);
        }
        
        vector<int> a(imax + 2, 0);
        for(const auto& i : intervals){
            a[i[0]] = max(a[i[0]], i[1] + 1);
        }

        int have = -1, interval = -1;
        vector<vector<int>> ans;
        for(int i = 0; i <= imax; i++){
            if(a[i] != 0){
                if(interval == -1) interval = i;
                have = max(have, a[i] - 1);
            }

            if(have == i){
                ans.push_back({interval, have});
                have = -1;
                interval = -1;
            }
        }

        if(interval != -1) ans.push_back({interval, have});
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


