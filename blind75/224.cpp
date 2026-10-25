
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
#include <stack> // FIX

using namespace std;

#define ll long long

class Solution {
public:
    // s = "(1+(4+5+2)-3)+(6+8)"
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        vector<int> visited(n, 0);
        int ans = 0;
        int negative = 1;

        vector<int> value(n, 0);
        vector<int> sign(n, 1);
        vector<int> closeAt(n, -1);

        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            visited[i] = 1;

            if(s[i] == ' ') continue;

            if(s[i] == '-'){
                negative = -1;
                continue;
            }

            if(s[i] == '+'){
                negative = 1;
                continue;
            }

            int temp = 0;

            if(s[i] == '('){
                st.push(i);
                sign[i] = negative;
                negative = 1;

            }else if(s[i] == ')'){

                int x = st.top();
                st.pop(); 

                closeAt[x] = i;

                int d = 0;
                int negative1 = 1; 
                for(int j = x + 1; j < i; j++){

                    if(s[j] == ' ') continue;

                    if(s[j] == '-'){
                        negative1 = -1;
                        continue;
                    }

                    if(s[j] == '+'){
                        negative1 = 1;
                        continue;
                    }

                    if(s[j] == '('){
                        d += value[j] * negative1;
                        negative1 = 1;
                        j = closeAt[j];
                        continue;
                    }

                    int temp1 = 0;

                    while(j < i && s[j] >= '0' && s[j] <= '9'){
                        visited[j] = 1;
                        temp1 = temp1 * 10 + (s[j] - '0');
                        j++;
                    }

                    d += temp1 * negative1;
                    negative1 = 1;
                    j--; 
                }

                value[x] = d; 

                if(st.empty()){
                    ans += d * sign[x];
                }

                negative = 1;
                continue;
            }

            while(i < n && s[i] >= '0' && s[i] <= '9'){
                visited[i] = 1;
                temp = temp * 10 + (s[i] - '0');
                i++;
            }

            if(st.empty()){
                ans = ans + temp * negative;
            }

            negative = 1;
            i--;
        }

        return ans;
    }
};

// -(1+2)


//"(1-(4+5+2)-3)+(6+8)"
//save state before ( and after compute ) done it will relase state before ( and compute
//if has " " will continue

#define ll long long
class Solution {
public:

    int calculate(string s) {
        stack<pair<ll, ll>> st;
        ll ans = 0;
        ll negative = 1;

        for(int i = 0; i < s.size(); i++){
            //cout << i << " " << s[i] << endl;
            if(s[i] == ' ') continue;

            if(s[i] == '-'){
                negative = -1;
                continue;
            }
            if(s[i] == '+'){
                negative = 1;
                continue;
            }

            if(s[i] == '('){
                st.push({ans, negative});
                ans = 0;
                negative = 1;
                continue;
            }

            if(s[i] == ')'){
                pair<ll, ll> preAns = st.top();
                st.pop();
                if(preAns.second == 1) ans += preAns.first;
                else ans = preAns.first - ans;
                continue;
            }

            ll temp = 0;

            while(s[i] >= '0' && s[i] <= '9' && i < s.size()){
                temp = temp*10 + (s[i] - '0');
                i++;
            }
            i--;

            ans += temp*negative;

        }
        if(!st.empty()){
            while(!st.empty()){
                pair<ll, ll> pii = st.top();
                if(pii.second == 1) ans += pii.first;
                else ans = pii.first - ans;
                st.pop();
            }
        }
        return ans;
    }
};
