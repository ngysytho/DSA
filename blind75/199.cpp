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

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, TreeNode* left, TreeNode* right): val(val), left(left), right(right) {}
};


class Solution {
public:
    unordered_map<int, int> visited;

    void dfs(vector<int>& ans, TreeNode* root, int depth){
        if(!root) return;

        if(!visited[depth]){
            ans.push_back(root->val);
            visited[depth] = 1;
        }

        dfs(ans, root->right, depth + 1);
        dfs(ans, root->left, depth + 1);

        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root, 0);

        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
