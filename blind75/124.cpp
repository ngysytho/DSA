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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {

int res = INT_MIN;

int getmax(TreeNode* root){
    if(!root) return 0;

    int left = getmax(root->left);
    int right = getmax(root->right);

    int path = max(root->val + left, root->val + right);

    return max(0, path);
}

void dfs(TreeNode* root){
    if(!root) return;

    int left = getmax(root->left);
    int right = getmax(root->right);
    res  = max(res, root-> val + left + right);
    dfs(root->left );
    dfs(root-> right);
    return;
}

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};


class Solution {
int dfs(TreeNode* root, int& res){
    if(!root) return 0;

    int leftMax = max(dfs(root->left, res), 0);
    int rightMax = max(dfs(root->right, res), 0);

    res = max(res, root->val + leftMax + rightMax);

    return root->val + max(leftMax, rightMax);
}

public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;

        dfs(root, res);

        return res;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
