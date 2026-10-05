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


class Interval {
public:
    int start, end;
    Interval(int start, int end) {
            this->start = start;
            this->end = end;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
        //     return a.end < b.end;
        // });
        map<int, int> mp;

        for(auto pi : intervals){
            mp[pi.start]++;
            mp[pi.end]--;
        }

        int pre = 0;
        int ans = 0;

        for(pair<int, int> pi : mp){
            pre += pi.second;
            ans = max(ans, pre);
        }
        return ans;

        
    }
};



class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){
            return x.start < y.start;
        });

        priority_queue<int, vector<int>, greater<int>> p;

        for(auto& x : intervals){
            if(!p.empty() && p.top() <= x.start){
                p.pop();
            }
            p.push(x.end);
        }

        return p.size();
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
