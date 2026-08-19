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
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> check;
        int n = s.size(), m = t.size();

        for(auto& x : t) mp[x]++;
        int l = 0, r = 0;
        int ansl = 0, ansr = INT_MAX - 2;
        int need = mp.size();
        int have = 0;


        while(r < n){
            if(mp.count(s[r])){
                check[s[r]]++;
                if(check[s[r]] == mp[s[r]]) have++;
            }

            while(have == need){
                if(r - l + 1 < ansr - ansl + 1){
                    ansl = l;
                    ansr = r;
                }

                if(mp.count(s[l])){
                    if(check[s[l]] == mp[s[l]]) have--;
                    check[s[l]]--;

                }
                l++;
            }
            r++;
        }



        if(ansr == INT_MAX - 2) return "";
        else return s.substr(ansl, ansr - ansl + 1);
    }
};


class Solution {
public:
    string minWindow(string s, string t) {
        //if(s.size()<t.size()) return "";
        vector<int> mp(128,0);
        for(auto ch:t){
            mp[ch]++;
        }
        int counter=t.size(), begin=0, end=0, head=0, d=INT_MAX;
        while(end<s.size()){
            if(mp[s[end++]]-->0) counter--;
            while(counter==0){
                if(end - begin < d) {
                    d = end - begin;
                    head = begin;
                }
                if(mp[s[begin++]]++==0) counter++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
