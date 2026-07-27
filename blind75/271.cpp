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
    string encode(vector<string>& strs) {
        string res;
        for (const string& s : strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};



class Solution {
public:

    vector<pair<int, int>> trace;
    string encode(vector<string>& strs) {
        string s = "";
        for(auto x : strs){
            trace.push_back({s.size(), x.size()});
            s += x;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s.size() == 0) return ans;

        for(auto pairr : trace){
            ans.push_back(s.substr(pairr.first, pairr.second));
        }
        return ans;
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
