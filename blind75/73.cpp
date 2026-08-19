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
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0) visited[i][j] = 1;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0 && visited[i][j]){
                    for(auto x : dir){
                        int newI = i + x[0];
                        int newJ = j + x[1];

                        while(newJ >= 0 && newJ < m && newI >= 0 && newI < n){
                            matrix[newI][newJ] = 0;
                            newI += x[0];
                            newJ += x[1];
                        }
                    }
                }
            }
        }
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroR = false;
        bool zeroC = false;

        int n = matrix.size(), m = matrix[0].size();

        for(int j = 0; j < m; j++){
            if(matrix[0][j] == 0){
                zeroR = true;
            }
        }

        for(int i = 0; i < n; i++){
            if(matrix[i][0] == 0){
                zeroC = true;
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    if(i > 0){
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                    else zeroR = true;
                }
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(zeroR){
            for(int i = 0; i < m; i++){
                matrix[0][i] = 0;
            }
        }

        if(zeroC){
            for(int j = 0; j < n; j++){
                matrix[j][0] = 0;
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
