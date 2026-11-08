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


class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> se;
    TimeMap() {
        se.clear();
    }
    
    void set(string key, string value, int timestamp) {
        se[key].push_back({timestamp, value});
        sort(se[key].begin(), se[key].end());
    }
    
    string get(string key, int timestamp) {
        if (se.find(key) == se.end()) return "";

        int left = 0, right = se[key].size() - 1;

        // 1 6, 4 5
        string res = "";
        while(left <= right){
            int mid = left + (right - left)/2;

            if(se[key][mid].first > timestamp){
                right = mid - 1;
            }else{
                res = se[key][mid].second;
                left = mid + 1;
            }
        }

        return res;
    }
};


class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> se;
    TimeMap() {
        se.clear();
    }
    
    void set(string key, string value, int timestamp) {
        se[key].push_back({timestamp, value});
        //sort(se[key].begin(), se[key].end());
    }
    
    string get(string key, int timestamp) {
        if (se.find(key) == se.end()) return "";

        auto it = upper_bound( se[key].begin(), se[key].end(), timestamp,[](int a, pair<int, string> b){
            return a < b.first;
        }) - se[key].begin();

        return it == 0 ? "" : se[key][it-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
