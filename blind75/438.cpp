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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.length(), k = p.length();
        if (n < k) return ans;

        const long long BASE = 100003;
        const long long MOD = 1000000007; // 10^9 + 7: Nhân với BASE tối đa ~ 10^14, không bao giờ tràn

        long long pw[26];
        pw[0] = 1;
        for (int i = 1; i < 26; i++) {
            pw[i] = (pw[i - 1] * BASE) % MOD;
        }

        long long hashP = 0;
        for (char c : p) {
            hashP = (hashP + pw[c - 'a']) % MOD;
        }

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = (pref[i] + pw[s[i] - 'a']) % MOD;
        }

        for (int i = 0; i <= n - k; i++) {
            long long currentHash = (pref[i + k] - pref[i] + MOD) % MOD;
            if (currentHash == hashP) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        if (n < k) return {};

        const long long BASE = 100003;
        const long long MOD = 1000000000000000009LL; // 10^18 + 9

        long long pw[26];
        pw[0] = 1;
        for (int i = 1; i < 26; i++) {
            // Ép sang __int128 khi nhân để không tràn long long
            pw[i] = ((__int128)pw[i - 1] * BASE) % MOD;
        }

        long long hashP = 0;
        for (char c : p) hashP = (hashP + pw[c - 'a']) % MOD;

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = (pref[i] + pw[s[i] - 'a']) % MOD;
        }

        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            long long cur = (pref[i + k] - pref[i] + MOD) % MOD;
            if (cur == hashP) ans.push_back(i);
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        if (n < k) return {};

        const long long B1 = 100003, M1 = 1000000007;
        const long long B2 = 100019, M2 = 1000000009;

        long long pw1[26], pw2[26];
        pw1[0] = pw2[0] = 1;
        for (int i = 1; i < 26; i++) {
            pw1[i] = (pw1[i - 1] * B1) % M1;
            pw2[i] = (pw2[i - 1] * B2) % M2;
        }

        long long hP1 = 0, hP2 = 0;
        for (char c : p) {
            hP1 = (hP1 + pw1[c - 'a']) % M1;
            hP2 = (hP2 + pw2[c - 'a']) % M2;
        }

        vector<long long> pref1(n + 1, 0), pref2(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref1[i + 1] = (pref1[i] + pw1[s[i] - 'a']) % M1;
            pref2[i + 1] = (pref2[i] + pw2[s[i] - 'a']) % M2;
        }

        vector<int> ans;
        for (int i = 0; i <= n - k; i++) {
            long long cur1 = (pref1[i + k] - pref1[i] + M1) % M1;
            long long cur2 = (pref2[i + k] - pref2[i] + M2) % M2;
            if (cur1 == hP1 && cur2 == hP2) {
                ans.push_back(i);
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
