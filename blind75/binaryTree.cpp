#include <iostream>
#include <vector>
#include <queue>
#include <optional>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

// Build tree from level-order array.
// Example: {1, 2, 3, nullopt, 4}
TreeNode* buildTree(const vector<optional<int>>& arr) {
    if (arr.empty() || !arr[0].has_value()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[0].value());

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Create left child
        if (i < arr.size() && arr[i].has_value()) {
            current->left = new TreeNode(arr[i].value());
            q.push(current->left);
        }

        i++;

        // Create right child
        if (i < arr.size() && arr[i].has_value()) {
            current->right = new TreeNode(arr[i].value());
            q.push(current->right);
        }

        i++;
    }

    return root;
}

// Root -> Left -> Right
void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Left -> Root -> Right
void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Left -> Right -> Root
void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// BFS level-order traversal
void levelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->val << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

// Return tree height
int treeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Count total nodes
int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1
        + countNodes(root->left)
        + countNodes(root->right);
}

// Search for a value
bool searchValue(TreeNode* root, int target) {
    if (root == nullptr) {
        return false;
    }

    if (root->val == target) {
        return true;
    }

    return searchValue(root->left, target)
        || searchValue(root->right, target);
}

// Return -1 if the subtree is not balanced.
// Otherwise, return its height.
int checkHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = checkHeight(root->left);

    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkHeight(root->right);

    if (rightHeight == -1) {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    TreeNode* deserialize(const string& data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(TreeNode* root, ostringstream& out) {
        if (root == nullptr) {
            out << "# ";
            return;
        }

        out << root->val << " ";

        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string val;

        if (!(in >> val)) {
            return nullptr;
        }

        if (val == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = deserializeHelper(in);
        root->right = deserializeHelper(in);

        return root;
    }
};

// Free dynamically allocated memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main() {
    vector<optional<int>> arr = {
        1,
        2,
        3,
        4,
        5,
        nullopt,
        6
    };

    TreeNode* root = buildTree(arr);

    cout << "Preorder: ";
    preorder(root);
    cout << '\n';

    cout << "Inorder: ";
    inorder(root);
    cout << '\n';

    cout << "Postorder: ";
    postorder(root);
    cout << '\n';

    cout << "Level order: ";
    levelOrder(root);
    cout << '\n';

    cout << "Height: " << treeHeight(root) << '\n';

    cout << "Total nodes: " << countNodes(root) << '\n';

    int target = 5;

    cout << "Search " << target << ": "
         << (searchValue(root, target) ? "Found" : "Not found")
         << '\n';

    cout << "Balanced: "
         << (isBalanced(root) ? "Yes" : "No")
         << '\n';

    Codec codec;

    string serializedData = codec.serialize(root);

    cout << "Serialized tree: "
         << serializedData
         << '\n';

    TreeNode* newRoot = codec.deserialize(serializedData);

    cout << "Deserialized preorder: ";
    preorder(newRoot);
    cout << '\n';

    deleteTree(root);
    deleteTree(newRoot);

    return 0;
}