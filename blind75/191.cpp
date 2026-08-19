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
    int hammingWeight(int n) {
        bitset<128> b(n);
        return b.count();
        popcount((unsigned)n);
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while(n > 0){
            if(n&1) ans++;
            n>>=1;
        }
        return ans;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
