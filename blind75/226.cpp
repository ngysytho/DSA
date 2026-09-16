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
    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}

    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};


class Solution {
public:

    void check(TreeNode*& root){
        if(root == nullptr) return;
        
        TreeNode* curleft = root->left;
        TreeNode* curright = root->right;

        root->left = curright;
        root->right = curleft;

        check(root->right);
        check(root->left);
    }


    TreeNode* invertTree(TreeNode* root) {
        TreeNode* curr = root;

        check(curr);

        return curr;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode* cur = q.front();
            swap(cur->left, cur->right);
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return root;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
