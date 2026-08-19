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

using namespace std;

#define ll long long


class Solution {
public:

    int countbit(int n){
        if(n == 0) return 1;
        int count = 0;
        while(n > 0){
            n>>=1;
            count++;
        }
        return count;
    }

    int reverseBits(int n) {
        int c = 32;
        int ans = 0;
        while(c){
            ans <<= 1;
            ans |= (n&1);
            n >>=1;
            c--;
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
