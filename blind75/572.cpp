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
        if(root == nullptr){
            v.push_back(10001);
            return;
        }

        v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }

    void dfs1(TreeNode* root, vector<vector<int>>& v, int nums){

        vector<int> v1;
        if(root == nullptr){
            return;
        };

        if(root->val == nums){
            vector<int> v1;
            dfs(root, v1);
            v.push_back(v1);
        }
        dfs1(root->left, v, nums);
        dfs1(root->right, v, nums);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<vector<int>> v;
        vector<int> v1;

        int nums = subRoot->val;
        dfs1(root, v, nums);
        dfs(subRoot, v1);
        //for(auto x1 : v1) cout << x1 << " ";
        //cout << endl;
        for(auto& x : v){
            if(x == v1) return true;
            //for(auto x1 : x) cout << x1 << " ";
            //cout << endl;
        }
        return false;
    }
};


class Solution {
public:


    bool check(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if (!root || !subRoot) {
            return false;
        }
        if(root->val == subRoot->val && root && subRoot){
            return check(root->left, subRoot->left) && check(root->right, subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;

        if(!root) return false;

        if(check(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};


class Solution {
public:

    string serialized(TreeNode* root){
        if(!root) return "#$";
        return '#' + to_string(root->val) + serialized(root->left) + serialized(root->right);
    }

    vector<int> zfun(string s){
        int n = s.size();
        vector<int> z(n, 0);

        int l = 0, r = 0;
        for(int i = 1; i < n; i++){
            if(i <= r){
                z[i] = min(r - i + 1, z[i - l]);
            }

            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

            if(i + z[i] - 1 > r){
                r = i + z[i] - 1;
                l = i;
            }
        }
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = serialized(root);
        string s2 = serialized(subRoot);

        string s = s2 + '|' + s1;

        vector<int> v = zfun(s);

        int n = s2.size();

        for(int i = n + 1; i < s.size(); i++){
            if(v[i] == n) return true;
        }
        return false;
    }
};



class Solution {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "$#";
        }
        return "$" + to_string(root->val) +
                serialize(root->left) + serialize(root->right);
    }

    vector<int> z_function(string s) {
        vector<int> z(s.length());
        int l = 0, r = 0, n = s.length();
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serialized_root = serialize(root);
        string serialized_subRoot = serialize(subRoot);
        string combined = serialized_subRoot + "|" + serialized_root;

        vector<int> z_values = z_function(combined);
        int sub_len = serialized_subRoot.length();

        for (int i = sub_len + 1; i < combined.length(); i++) {
            if (z_values[i] == sub_len) {
                return true;
            }
        }
        return false;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
