#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>


using namespace std;

class Solution{
    public:

        int lengthOfLongestSubstring2(string s){
            int n = s.size();
            int right = 0, left = 0;
            if (n == 0) return 0;
            if(n == 1) return 1;

            int maxstring = 0;
            int ans = 1;
            unordered_map<char, int> mp;
            while (right < n && left < n){
                if(mp[s[left]] != 0){
                    mp.clear();
                    right++;
                    left = right;
                    ans = max(ans, maxstring);
                    maxstring = 0;
                }else{
                    mp[s[left]]++;
                    left++;
                    maxstring++;
                }
                ans = max(ans, maxstring);
            }
            return ans;
        }

        int lengthOfLongestSubstring1(string s){
            int n = s.size();
            if(n == 0) return 0;
            vector<int> vis(128, false);
            int res = 1;
            int left = 0;
            
            for(int right = 0; right < n; right++){
                while (vis[s[right]]){
                    vis[s[left]] = false;
                    left++;
                }
                
                vis[s[right]] = true;
                res = max(res, right - left + 1);
                //cout << left<< " " << right << endl;
            }
            return res;
        }

        int lengthOfLongestSubstring(string s){
            int n = s.size();

            vector<int> lastIndex(128, -1);
            int res = 0;
            int start = 0;

            for(int end = 0; end < n; end ++){
                start = max(start, lastIndex[s[end]] + 1);
                res = max(res, end - start + 1);
                lastIndex[s[end]] = end;
            }
            return res;
        }
};

int main(){
    Solution sol;
    string s;
    cin >> s;
    cout << sol.lengthOfLongestSubstring2(s);
}
