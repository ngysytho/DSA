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

    void dfs(vector<vector<int>>& image, int orgin, int sr, int sc, int color){
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != orgin) return;

        image[sr][sc] = color;

        dfs(image, orgin, sr - 1, sc, color);
        dfs(image, orgin, sr + 1, sc, color);
        dfs(image, orgin, sr, sc + 1, color);
        dfs(image, orgin, sr, sc - 1, color);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origin = image[sr][sc];
        dfs(image, origin, sr, sc, color);
        return image;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
