#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>


using namespace std;

class Solution{
    public:
        int countSubstrings(string s){
            int n = s.size();
            if(n <= 1) return 1;

            auto checksubstr = [&](int left, int right){
                while(left < right){
                    if(s[left] == s[right]){
                        left++;
                        right--;
                    }
                    else{
                        return false;
                    }
                }
                return true;
            };

            long long ans = 0;

            for(int i = 0; i < n; i++){
                for(int j = i ; j < n; j++){
                    if(checksubstr(i, j)) ans++;
                }
            }
            return ans;
        }

        int countSubstrings_n2(string s){
            int n = s.size();
            if(n <= 1) return 1;

            auto middleExpand = [&](int left, int right){
                int ans1 = 0;
                while(left >= 0 && right < n && s[left] == s[right]){
                    ans1++;
                    left--;
                    right++;
                }
                return ans1;
            };

            int ans = 0;
            for(int i = 0; i < n; i++){
                ans += middleExpand(i, i);
                ans += middleExpand(i, i + 1);
            }
            return ans;
        }
};
vector<int> v;

int main(){
    Solution sol;
    string s;
    cin >> s;
    cout << sol.countSubstrings_n2(s);
}