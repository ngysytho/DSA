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
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i <= n; i++){
            int cnt = 0;

            int c = i;
            while(c){
                if(c&1) cnt++;
                c/=2;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        ans[0] = 0;
        if(n == 0) return ans;

        for(int i = 1; i <= n; i++){
            if(i & 1){
                ans[i] = ans[i/2] + 1;
            }else{
                ans[i] = ans[i/2];
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
