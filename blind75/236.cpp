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

    TreeNode(int val): val(val), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    TreeNode* ans;
    TreeNode* ans1;

    int dfs(TreeNode* root, TreeNode*& p, TreeNode*& q, int visit){
        if(!root) return 0;
        if(root == p){
            ans1 = p;
            return 1;
        }
        if(root == q){
            ans1 = q;
            return 1;
        }

        int df = dfs(root->left, p, q, 0);
        int dr = dfs(root->right, p, q, 0);

        if(df&dr){
            ans = root;
            return 0;
        }

        return df + dr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q, 0);
        return ans != nullptr ? ans : ans1;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
