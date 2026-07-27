#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>


using namespace std;

#define ll long long

class Solution {
public:
    bool isValid_wrong(string s) {
        //([})()[]{}
        int n = s.size();
        if(n % 2 != 0) return false;
        int i = 0;
        int left = 0, right = 0;
        while(i < n){
            if(s[i] == '{' && s[i+1] == '}' || s[i] == '[' && s[i+1] == ']' || s[i] == '(' && s[i+1] == ')'){
                i += 2;
            }
            else{
                left = i;
                while(s[i] != s[i + 1]){
                    i += 2;
                    if(i >= n) break;
                }
                right = i - 1;

                while(left < right){
                    
                    if(s[left] == '{' && s[right] == '}' || s[left] == '[' && s[right] == ']' || s[left] == '(' && s[right] == ')'){
                        cout << left << " " << right << endl;
                        left++;
                        right--;
                    }
                    else{
                        cout << s[left] << " " << s[right] << endl;
                        cout << left << " " << right << " wrong" << endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValid(string s){
        stack<char> q;
        
        for(char x : s){
            if(x == '(' || x == '{' || x == '[') q.push(x);
            else{
                if(q.empty()) return false;
                char c = q.top();
                if(x == ')' && c == '('|| x == '}' && c == '{'|| x == ']' && c == '[') q.pop();
                else return false;
            }
        }
        return q.empty();
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    Solution sol;
    cout << sol.isValid(s);
}
