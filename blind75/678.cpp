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

class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        int right = 0;
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                count++;
            }else if(s[i] == '(') left++;
            else{
                right++;
            }

            if(right > left + count) return false;
        }

        left = 0, right = 0, count = 0;

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '*'){
                count++;
            }else if(s[i] == '(') left++;
            else{
                right++;
            }

            if(left > right + count) return false;
        }

        return true;
    }
};



class Solution {
public:

    vector<vector<int>> memo =
        vector<vector<int>>(101, vector<int>(101, -1));

    bool dfs(string& s, int i, int balance){
        if(balance < 0) return false;

        if(i == s.size()){
            return balance == 0;
        }

        if(memo[i][balance] != -1){
            return memo[i][balance];
        }
        bool ans;
        if(s[i] == '(') ans = dfs(s, i + 1, balance + 1);
        if(s[i] == ')') ans =dfs(s, i + 1, balance - 1);

        if(s[i] == '*'){
            ans = dfs(s, i + 1, balance + 1) ||dfs(s, i + 1, balance - 1 )|| dfs(s, i + 1, balance);
        }
        return memo[i][balance] = ans;
    }
    bool checkValidString(string s) {
        return dfs(s,0, 0);
    }
};


//"(*))"
class Solution {
public:
    bool checkValidString(string s) {
        int high = 0;
        int low = 0;

        for(auto& x : s){
            if(x == '('){
                low++;
                high++;
            }else if(x == ')'){
                low--;
                high--;
            }else{
                high++;
                low--;
            }
            low = max(low, 0);
            if(high < 0) return false;
        }

        return low == 0;
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
