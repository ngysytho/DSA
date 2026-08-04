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


class Solution {
public:

    void dfs(vector<vector<int>>& matrix, vector<int>& ans, vector<vector<bool>>& visited, vector<vector<int>>& direc,int n, int m, int d){
        if(ans.size() == matrix.size() * matrix[0].size()) return;

        ans.push_back(matrix[n][m]);

        visited[n][m] = true;
        int newA = n + direc[d][0];
        int newB = m + direc[d][1];
        if(newA < 0 || newA >= matrix.size() || newB < 0 || newB >= matrix[0].size() || visited[newA][newB]){
            d = ( d + 1 ) % 4;
            newA = n + direc[d][0];
            newB = m + direc[d][1];
        }
        dfs(matrix, ans, visited, direc, newA, newB, d);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<vector<bool>> visited(11, vector<bool>(11, false));
        vector<vector<int>> direc = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};

        dfs(matrix, ans, visited, direc, 0, 0, 0);
        return ans;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0},{0, -1}, {-1, 0}};
        vector<int> steps = { (int)matrix[0].size(), (int)matrix.size() - 1};

        int r = 0, c = -1, d = 0;
        while (steps[d % 2]) {
            for (int i = 0; i < steps[d % 2]; i++) {
                r += directions[d].first;
                c += directions[d].second;
                res.push_back(matrix[r][c]);
            }
            steps[d % 2]--;
            d = (d + 1) % 4;
        }
        return res;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

