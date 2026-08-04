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
    int characterReplacement(string s, int k) {
        vector<vector<int>> v(26, vector<int>(s.size() + 2, 0));
        for(int i = 0; i < s.size(); i++){
            v[s[i] - 'A'][i + 1] += 1;
        }
        for(int i = 0; i <26; i++){
            for(int j = 1; j <= s.size(); j++){
                v[i][j] += v[i][j - 1];
            }
        }
        int ans = 1;
        for(int i = 0; i < 26; i++){
            int curr = 1;
            int k1 = k;
            int l = 0;
            for(int j = 0; j < s.size(); j++){
                curr = v[i][j + 1] - v[i][l];
                k1 = k - ((j - l + 1) - curr);
                while(k1 < 0){
                    l++;
                    curr = v[i][j + 1] -v[i][l];
                    k1 = k - ((j - l + 1) - curr);
                }
                ans = max(ans, j - l + 1);
            }
        }
        return ans;
    }


    int characterReplacement(string s, int k) {
        
    }

};

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> v(s.begin(), s.end());

        int ans = 1;

        for(auto x : v){
            int count = 0;
            int l = 0;
            for(int i = 0; i < s.size(); i++){
                if(x == s[i]) count++;

                while((i - l + 1) - count > k){
                    if(s[l] == x) count--;
                    l++;
                }
                ans = max(ans, i - l + 1);
            }
        }
        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
