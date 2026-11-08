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
#include <list>

using namespace std;

#define ll long long

struct interval{
    int startTime;
    int endTime;
    int profit;
};


class Solution {
public:

    vector<interval> intervals;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        for(int i = 0; i < n; i++){
            interval interval;
            interval.startTime = startTime[i];
            interval.endTime = endTime[i];
            interval.profit = profit[i];
            intervals.push_back(interval);

        }

        sort(intervals.begin(), intervals.end(), [](interval a, interval b){
            if(a.endTime == b.endTime) return a.startTime < b.startTime;
            return a.endTime < b.endTime;
        });
        int d = intervals[n - 1].endTime;
        vector<int> dp(d + 2, 0);
        
        dp[intervals[0].endTime] = intervals[0].profit;
        for(int i = 1; i < intervals[0].endTime; i++) dp[i] = max(dp[i], dp[i - 1]);


        for(int i = 1; i < n; i++){
            for(int j = intervals[i - 1].endTime + 1; j <= intervals[i].endTime; j++){
                dp[j] = max(dp[j], dp[j - 1]);
            }

            dp[intervals[i].endTime] = max(dp[intervals[i].endTime], dp[intervals[i].startTime] + intervals[i].profit);
        }


        int ans = -1;

        for(auto& x : dp) ans = max(ans, x);

        return ans;
    }
};


class Solution {
public:
    vector<int> cache;
    vector<vector<int>> intervals;
    int n;

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();

        cache.assign(n, -1);

        for(int i = 0; i < n; i++){
            intervals.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(intervals.begin(), intervals.end());

        return dfs(0);

    }

    int dfs(int i){
        if(i  >= n) return 0;

        if(cache[i] != -1) return cache[i];

        int res = dfs(i + 1);

        int j = n;

        int left = i + 1, right = n;

        while(left < right){
            int mid = left + (right - left)/2;

            if(intervals[i][1] > intervals[mid][0]){
                right = mid;
                j = mid;
            }else left = mid + 1;
        }

        return cache[i] = max(res, intervals[i][2] + dfs(j));
    }
};



class Solution {
public:

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        vector<int> dp(n + 1, 0);
        vector<vector<int>> intervals;
        for(int i = 0; i < n; i++){
            intervals.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(intervals.begin(), intervals.end());


        for(int i = n - 1; i >= 0; i--){
            int tempRes = dp[i + 1];

            int j = n;

            int left = i + 1, right = n;

            while(left < right){
                int mid = left + (right - left)/2;
                if(intervals[i][1] <= intervals[mid][0]){
                    j = mid;
                    right = mid;
                }else left = mid + 1;
            }

            int take = intervals[i][2] + dp[j];

            dp[i] = max(tempRes, take);
        }

        return dp[0];
    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 2, 0);

        dp[0] = 1;
        for(int i = 0; i <= target; i++){
            for(auto& num : nums){
                if(i - num >= 0){
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
