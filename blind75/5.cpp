#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

class Solution{
    public:
        string longestPalindrome(string s){
            if(s.size() <= 1) return s;

            vector<int> v(128, -1);
            int left = 0, right = 0;
            int maxs = -1;

            for(int i = 0; i < s.size(); i++){
                if(v[s[i]] != -1){
                    if(maxs < i - v[s[i]] + 1){
                        maxs = i - v[s[i]] + 1;
                        right = i;
                        left = v[s[i]];
                    }
                }
                else{
                    v[s[i]] = i;
                }
            }
            return s.substr(left, right - left + 1);
        }
};
vector<int> v;

int main(){
    Solution sol;
    string s;
    cin >> s;
    cout << sol.longestPalindrome(s);
}