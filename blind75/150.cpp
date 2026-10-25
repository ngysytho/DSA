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

using namespace std;

#define ll long long


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> q;

        for(auto& x : tokens){
            if(x == "-"){
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                int ans = b - a;
                q.push(ans);
            }else if(x == "+"){
                int a =q.top();
                q.pop();
                int b = q.top();
                q.pop();
                int ans = a + b;
                q.push(ans);
            }else if(x == "*"){
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                int ans = a * b;
                q.push(ans);
            }else if(x == "/"){
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();
                int ans = b / a;
                q.push(ans);
            }else{
                int num = 0;
                int d = 1;
                for(auto& x1 : x){
                    if(x1 == '-'){
                        d = -1;
                        continue;
                    }
                    num = num * 10 + (x1 - '0');
                }
                num *= d;
                q.push(num);
            }
        }
        return q.top();
    }
};


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto& x : tokens){
            if(x == "-" || x == "+" || x == "*" || x == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                if(x == "-") st.push(b - a);
                else if(x == "+") st.push(b + a);
                else if( x == "*") st.push(b * a);
                else st.push(b / a);
            }else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
