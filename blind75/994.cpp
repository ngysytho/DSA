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
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<int>> dir{{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        bool check = false;
        while(!q.empty()){
            if(check) ans++;
            check = false;
            queue<pair<int, int>> q1;

            while(!q.empty()){
                pair<int, int> pi = q.front();
                q.pop();
                for(auto& x : dir){
                    int newI = pi.first + x[0];
                    int newJ = pi.second + x[1];

                    if(newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == 1){
                        q1.push({newI, newJ});
                        grid[newI][newJ] = 2;
                        check = true;
                    }
                }
            }
            q = q1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        if(check == true) ans++;
        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

}
