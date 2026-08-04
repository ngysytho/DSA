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

using namespace std;

#define ll long long


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    void treeToString(string& x, TreeNode* root1){
        if(root1 == nullptr) return;
        
        x += to_string(root1->val);

        if(!root1->left && !root1->right) return;
        x.push_back('(');
        treeToString(x, root1->left);
        x.push_back(')');

        if(root1->right){
            x.push_back('(');
            treeToString(x, root1->right);
            x.push_back(')');
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string s;
        treeToString(s, root);
        return s;
    }

    TreeNode* preOrder(int &i, string& s){
        if(s[i] == ')') return nullptr;
        if(s.size() == 0) return nullptr;

        int sign = 1;

        if (s[i] == '-') {
            sign = -1;
            i++;
        }

        int val = 0;
        while(i < s.size() && s[i] != '(' && s[i] != ')'){
            int digit = s[i] -'0';
            i++;
            val = val*10 + digit;
        }
        val *= sign;

        TreeNode* note = new TreeNode(val);

        if(i < s.size() && s[i] == '('){
            i++;
            note->left = preOrder(i, s);
            i++;
        }

        if(i < s.size() && s[i] == '('){
            i++;
            note->right = preOrder(i, s);
            i++;
        }
        return note;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return preOrder(i, data);

    }
};

Codec ser, deser;
TreeNode* root = new TreeNode(0);
TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
