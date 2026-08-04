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


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> pi;
        for(auto x: intervals){
            pi.push_back({x[0], x[1]});
        }

        sort(pi.begin(), pi.end(), [&](const pair<int,int>& a,const pair<int,int>& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });

        int ans = 0;
        int n = pi.size();
        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i++){
            int it = lower_bound(pi.begin() + i + 1, pi.end(), pi[i].second, [](const pair<int,int> a,int b){
                return a.first < b;
            }) - pi.begin();

            dp[i] = max(dp[i + 1], 1 + dp[it]);

        }
        return n - dp[0];
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> pi;
        for(auto x: intervals){
            pi.push_back({x[0], x[1]});
        }

        sort(pi.begin(), pi.end(), [&](const pair<int,int>& a,const pair<int,int>& b) {
            return a.second < b.second;
        });
        int end = 0, ans = 0;
        for(int i = 0; i < pi.size(); i++){
            if(pi[i].first >= end){
                ans++;
                end = pi[i].second;
            }
        }
        return pi.size() - ans;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
