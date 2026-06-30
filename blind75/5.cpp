#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>


using namespace std;

class Solution{
    public:
        // string longestPalindrome1(string s){
        //     if(s.size() <= 1) return s;

        //     vector<int> v(128, -1);
        //     int left = 0, right = 0;
        //     int maxs = -1;

        //     for(int i = 0; i < s.size(); i++){
        //         if(v[s[i]] != -1){
        //             if(maxs < i - v[s[i]] + 1){
        //                 maxs = i - v[s[i]] + 1;
        //                 right = i;
        //                 left = v[s[i]];
        //             }
        //         }
        //         else{
        //             v[s[i]] = i;
        //         }
        //     }
        //     return s.substr(left, right - left + 1);
        // }


        bool check(string s){
            string a = s;
            reverse(a.begin(), a.end());
            if(a == s) return true;
            else return false;
        }
// abcccde
        string longestPalindrome1(string s){
            int n = s.size();
            if(n <= 1) return s;
            int l = 0, r = 0, ans = 0;
            for(int i = 0; i < n - 1; i++){
                for(int j = i + 1; j < n; j++){
                    //string a = s.substr(i, j - i + 1);
                    if(checkans1(s, j, i) && j - i + 1 > ans){
                        ans = j - i + 1;
                        l = i, r = j;
                        //cout << l << " " << r << endl;
                    }
                }
            }
            return s.substr(l, r - l + 1);
        }

        bool checkans1(string s, int right, int left){
            int l = left, r = right;
            while(l < r){
                if(s[l] == s[r]){
                    l++, r--;
                }
                else{
                    return false;
                }
            }
            return true;
        }

        bool checkans(string s, int mid){
            for(int i = 0; i + mid < s.size() ; i++){
                int check = 0;
                int l = i, r = l + mid;
                while(l < r){
                    if(s[l] == s[r]){
                        l++; r--;
                    }
                    else{
                        check = 1;
                        break;
                    }
                }
                if(check == 0){
                    ll = i;
                    return true;
                }
            }
            return false;
        }
        int ll = 0;
        string longestPalindrome(string s){
            int n = s.size();
            if(n <= 1) return s;
            int la = 0, ra = 0, ans = 0;
            int left = 0, r = 1000;
            while(left < r){
                int mid = (left + r + 1) / 2;
                if(mid  > n || r > n - 1){
                    r = mid;
                    continue;
                }
                if(checkans(s, mid)){
                    if(ans < mid){
                        ans = mid;
                    }
                    //cout << left << " " << r << " " << mid << " true" << endl;
                    left = mid;
                    
                }else{
                    cout << left << " " << r << " " << mid << " false" << endl;
                    r = mid - 1;
                }
                if( r == left) break;
            }
            cout << ll << endl;
            return s.substr(ll, ans + 1);
        }

        string longestPalindrome_2n(string s){
            if(s.size() <= 1) return s;

            auto checkmiddle = [&](int left, int right){
                while(left >= 0 && right < s.size() && s[left] == s[right]){
                    left--;
                    right++;
                }

                return s.substr(left + 1, right - left - 1);
            };

            string ans = s.substr(0, 1);
            for(int i = 0; i < s.size() - 1; i++){
                string odd = checkmiddle(i, i);
                string even = checkmiddle(i, i + 1);
                //cout << odd << " " << even << '\n';
                if(ans.size() < odd.size()) ans = odd;
                if(ans.size() < even.size()) ans = even;

            }
            return ans;
        }


        string longestPalindrome_dp(string s){
            if(s.size() <= 1) return s;

            vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

            int left = 0, right = 0, maxstring = 1;

            for(int i = 0; i < s.size(); i++){
                dp[i][i] = true;
                for(int j = 0; j < i; j++){
                    if(s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])){
                        dp[j][i] = true;
                        if(i - j + 1 > maxstring){
                            maxstring = i - j + 1;
                            left = j;
                            right = i;
                        }
                    }
                }
            }
            
            return s.substr(left, right - left + 1);
        }

        string longestPalindrome_0n(string s){
            if(s.size() <= 1) return s;

            string t = "#";

            for(char x : s){
                t += x;
                t += '#';
            }

            int n = t.size();
            vector<int> dp(n, 0);
            
            int centre = 0;
            int right = 0;

            int bestCentre = 0;
            int bestLen = 0;

            for(int i = 0; i < n; i++){
                int mirror = 2*centre - i;
                
                if(i < right){
                    dp[i] = min(right - i, dp[mirror]);
                }

                while(i - dp[i] - 1 >= 0 && i + dp[i] + 1 < n && t[i - dp[i] - 1] == t[i + dp[i] + 1]){
                    dp[i]++;
                }

                if(i + dp[i] > right){
                    centre = i;
                    right = i + dp[i];
                }

                if(dp[i] > bestLen){
                    bestLen = dp[i];
                    bestCentre = i;
                }
            }
            int start = (bestCentre - bestLen) / 2;
            return s.substr(start, bestLen);
        }
};
vector<int> v;

int main(){
    Solution sol;
    string s;
    cin >> s;
    cout << sol.longestPalindrome_0n(s);
}