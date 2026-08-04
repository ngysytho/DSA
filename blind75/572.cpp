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
public:


    void dfs(TreeNode* root, vector<int>& v){
        if(root == nullptr) return;

        v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> v;
        vector<int> v1;

        dfs(root, v);
        dfs(subRoot, v);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
