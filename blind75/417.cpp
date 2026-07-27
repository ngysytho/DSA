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

using namespace std;

#define ll long long
const int MaxN = 1 + 1e3, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};


class Solution {
public:
    const int MaxN = 1 + 1e3, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    map<pair<int,int>, bool> pacific;
    map<pair<int,int>, bool> atlantic;
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
        vector<vector<int>> ans;
        n = heights.size();
        m = heights[0].size();

        for(int i = 0; i < m; i++){
            bfs(0, i, false, heights);
            bfs(n - 1, i, true, heights);
        }

        for(int i = 0; i < n; i++){
            bfs(i, 0, false, heights);
            bfs(i, m - 1, true, heights);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[{i, j}] == true && atlantic[{i,j}]){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
    void bfs(int a, int b,bool k, vector<vector<int>>& v){
        if(k == false){
            if(pacific[{a, b}]) return;
            pacific[{a, b}] = true;
        }
        else{
            if(atlantic[{a, b}]) return;
            atlantic[{a, b}] = true;
        }
        for(int i = 0; i < 4; i++){
            int newA = a + dx[i];
            int newB = b + dy[i];
            if(a + dx[i] >= 0 && a + dx[i] < n && b + dy[i] >= 0 && b + dy[i] < m && v[a + dx[i]][b + dy[i]] >= v[a][b]){
                bfs(newA, newB,k, v);
            }
        }
    }

    int n, m;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> pacificAtlantic_bitwise(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> reach(n, vector<int>(m, 0));
        vector<vector<int>> directions ={{-1, 0}, {1, 0},{0, 1}, {0, -1}};
        queue<tuple<int, int, int>> q;

        auto addCell = [&](int r, int c, int ocean){
            if((reach[r][c] & ocean) == 0){
                reach[r][c] |= ocean;
                q.push({r, c, ocean});
            }
        };

        for(int c = 0; c < m; c++){
            addCell(0, c, 1);
            addCell(n - 1, c, 2);
        }
        for(int r = 0; r < n; r++){
            addCell(r, 0, 1);
            addCell(r, m - 1, 2);
        }

        while(!q.empty()){
            auto[r, c, ocean] = q.front();
            q.pop();

            for(int i = 0; i < directions.size(); i++){
                int newR = r + directions[i][0];
                int newC = c + directions[i][1];

                if (newR >= 0 && newR < n && newC >= 0 && newC < m && heights[newR][newC] >= heights[r][c] && (reach[newR][newC] & ocean) == 0
                ) {
                    reach[newR][newC] |= ocean;
                    q.push({newR, newC, ocean});
                }
            }
        }
        vector<vector<int>> ans;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (reach[r][c] == 3) {
                    ans.push_back({r, c});
                }
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
