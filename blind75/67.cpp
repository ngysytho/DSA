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
// 1010
// 1011
// 1 0 1 0 1
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int cur = 0;

        string ans = "";

        while(i >= 0 || j >= 0 || cur > 0){
            int c = 0, d = 0;
            if(i >= 0){
                if(a[i] == '0') c = 0;
                else c = 1;
            }
            if(j >= 0){
                if(b[j] == '0') d = 0;
                else d = 1;
            }

            int m = c + d + cur;
            

            //cout << m << " " << i << " " << j << " " << cur << endl;

            ans.push_back((m % 2) + '0');

            cur = m /2;

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
