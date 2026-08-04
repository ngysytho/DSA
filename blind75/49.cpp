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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for(auto x : strs){
            vector<int> count(26, 0);

            for(auto x1 : x) count[x1 - 'a']++;
            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++){
                key = key + ',' + to_string(count[i]);
            }
            ans[key].push_back(x);
        }

        vector<vector<string>> ans1;
        for(auto x : ans) ans1.push_back(x.second);
        return ans1;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
