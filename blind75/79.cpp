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

    bool dfs(vector<vector<char>>& board, string& word, vector<vector<int>>& dir, int n, int m, int start){
        if(n < 0 || n >= board.size() || m < 0 || m >= board[0].size() || board[n][m] != word[start]) return false;
        if(start == word.size() - 1) return true;
        char temp = board[n][m];
        board[n][m] = '#';
        for(auto& x: dir){
            int newN = n + x[0];
            int newM = m + x[1];

            if(dfs(board, word, dir, newN, newM, start + 1)){
                board[n][m] = temp;
                return true;
            }
        }
        board[n][m] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> dir{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, dir, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
