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
    int longestValidParentheses(string s) {
        queue<char> q;
        //"()(()"
        //"(()())"
        int ans = 0;
        int preAns = 0;
        int preCount = 0;
        for(auto& x : s){
            if(x == '(') q.push(x);
            else{
                if(q.size() == 1){
                    q.pop();
                    preAns += preCount;
                    preCount = 0;
                }else if(q.size() > 1){
                    preCount++;
                    q.pop();
                }else{
                    preCount = 0;
                    preAns = 0;
                }
            }
            cout << preAns << " " << preCount << endl;
            
            ans = max(ans, preAns);
        }

        return ans*2 >= preCount*2 ? ans*2 : preCount*2;
    }
};



class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;

        st.push(-1);

        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};



class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int ans = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ')'){
                if(s[i] == '('){
                    dp[i] = 2;
                    if(i >= 2) dp[i] += dp[i - 2];
                }
                else{
                    int j = i - dp[i - 1] - 1;

                    if(j >= 0 && s[j] == '('){
                        dp[i] = dp[i - 1] + 2;
                        if(j >= 1){
                            dp[i] += dp[j - 1];
                        }
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
