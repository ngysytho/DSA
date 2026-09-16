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
};

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;

        if(!p || !q) return false;
        if(p->val != q->val) return false;

        return isSameTree(p -> right, q -> right) && isSameTree(p->left, q->left);

        return true;
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> a, b;

        a.push(p);
        b.push(q);

        while(!a.empty() || !b.empty()){
            TreeNode* c = a.front();
            TreeNode* d = b.front();
            a.pop();
            b.pop();
            if(c->val != d->val) return false;

            if(c->left) a.push(c->left);
            if(c->right) a.push(c->right);
            if(d->left) b.push(d->left);
            if(d->right) b.push(d->right);

            if(a.size() != b.size()) return false;
        }

        return true;
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            for (int i = q1.size(); i > 0; i--) {
                TreeNode* nodeP = q1.front(); q1.pop();
                TreeNode* nodeQ = q2.front(); q2.pop();

                if (!nodeP && !nodeQ) continue;
                if (!nodeP || !nodeQ || nodeP->val != nodeQ->val)
                    return false;

                q1.push(nodeP->left);
                q1.push(nodeP->right);
                q2.push(nodeQ->left);
                q2.push(nodeQ->right);
            }
        }

        return true;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
