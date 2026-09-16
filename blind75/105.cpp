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

};

class Solution {
public:

    void dfs(vector<int>& preorder, vector<int>& inorder, int left, int right, int mid,  TreeNode*& root, vector<int>& visited){

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.size() == 0 && inorder.size() ==0 ) return nullptr;
        TreeNode* root;

        root = new TreeNode(preorder[0]);

        int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());
        
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
