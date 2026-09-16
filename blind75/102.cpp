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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
};

class Solution {
public:
    vector<vector<int>> ans = vector<vector<int>>(2002);


    void dfs(TreeNode* root, int level){
        if(!root) return;

        ans[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);

        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        vector<vector<int>> ans1;

        for(auto& x : ans){
            if(!x.empty()) ans1.push_back(x);
        }
        return ans1;
    }
};


class Solution {
public:
    vector<vector<int>> ans;


    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(ans.size() == level) ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);

        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
