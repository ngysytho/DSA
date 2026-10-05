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


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left1, TreeNode* right1): val(x), left(left1), right(right1){}

};

class Solution {
public:
    int ans1 = 0;
    int ans2 = 0;
    void dfs(TreeNode* root, int depth){
        if(!root) return;
        ans1 = max(ans1, depth);

        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
        return;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root ->left, 0);
        ans2 = ans1;
        ans1 = 0;
        dfs(root->right, 0);
        return ans2 + ans1;
    }
};

class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
