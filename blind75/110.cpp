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
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* right, TreeNode* left): val(x), right(right), left(left){}

};

class Solution {
public:

    int dfs(TreeNode* root){
        if(!root) return 0;

        int depthLeft = dfs(root->left);
        if(depthLeft == -1) return -1;
        //[1,2,2,3,3,null,null,4,4]

        int depthRight = dfs(root -> right);
        if(depthRight == -1) return -1;

        if(abs(depthLeft - depthRight) > 1) return -1;
        

        return max(depthLeft, depthRight) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return dfs(root) <= -1 ? false : true;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
