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

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& dir, vector<vector<int>>& visited, int i, int j, int n, int m){
        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == '0') return;
        if (visited[i][j] != -1) return;

        visited[i][j] = 1;

        for(const auto x : dir){
            int newI = i + x[0];
            int newJ = j + x[1];

            if(newI < n && newJ < m && newI >= 0 && newJ >= 0 && grid[newI][newJ] == '1'){
                dfs(grid, dir, visited,newI, newJ, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> visited(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == -1 && grid[i][j] == '1'){
                    ans++;
                    dfs(grid, dir, visited, i, j, n, m);
                }else continue;
            }
        }
        return ans;
    }
};


class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0},
                            {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }

        return islands;
    }

    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        grid[r][c] = '0';
        q.push({r, c});

        while (!q.empty()) {
            auto node = q.front();q.pop();
            int row = node.first, col = node.second;
            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};



class DSU {
    vector<int> Parent, Size;
public:
    DSU(int n) {
        Parent.resize(n + 1);
        Size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int find(int node) {
        if (node != Parent[node]) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if (Size[pu] >= Size[pv]) {
            Size[pu] += Size[pv];
            Parent[pv] = pu;
        } else {
            Size[pv] += Size[pu];
            Parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        DSU dsu(ROWS * COLS);

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int islands = 0;

        auto index = [&](int r, int c) {
            return r * COLS + c;
        };

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    for (auto& d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];
                        if (nr >= 0 && nc >= 0 && nr < ROWS &&
                            nc < COLS && grid[nr][nc] == '1') {
                            if (dsu.unionBySize(index(r, c), index(nr, nc))) {
                                islands--;
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
