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

class Solution {
public:
    set<string> se, prefixSe, ans;
    int maxLen = 0;
    vector<vector<int>> v{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(int i, int j, int& n, int& m, vector<vector<char>>& board, string s){
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') return;

        char temp = board[i][j];
        board[i][j] = '#';
        s += temp;

        if(prefixSe.find(s) == prefixSe.end()){
            board[i][j] = temp;
            return;
        }

        if(se.find(s) != se.end()) ans.insert(s);

        if(s.size() >= maxLen){
            board[i][j] = temp;
            return;
        }

        for(auto& x : v){
            int newI = i + x[0];
            int newJ = j + x[1];

            dfs(newI, newJ, n, m, board, s);
        }

        board[i][j] = temp;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        

        for(auto& x : words){
            se.insert(x);
            maxLen = max((int)x.size(), maxLen);

            string s = "";
            for(auto& x1 : x){
                s += x1;
                prefixSe.insert(s);
            }
        }

        int n = board.size(), m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(i, j, n, m, board, "");
            }
        }

        vector<string> ans1;

        for(auto& x : ans) ans1.push_back(x);
        return ans1;
    }
};


class Solution {
public:
    unordered_map<string, bool> mp;
    vector<vector<int>> v{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>>& board, string s, int i, int j, int& n, int& m){
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') return;
        s += board[i][j];
        mp[s] = true;

        char temp = board[i][j];
        board[i][j] = '#';
        for(auto& x : v){
            int newI = i + x[0];
            int newJ = j + x[1];
            dfs(board, s, newI, newJ, n, m);
        }

        board[i][j] = temp;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(board, "", i, j, n, m);
            }
        }

        vector<string> ans;
        for(auto& x : words){
            if(mp[x]) ans.push_back(x);
        }

        return ans;
    }
};

class Node{
public:
    vector<Node*> v;
    int wordIdx;
    int refs;

    Node(){
        v.resize(26, nullptr);
        wordIdx = -1;
        refs = 0;
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void add(string& s, int idx){
        Node* cur = root;
        cur->refs++;

        for(auto& x : s){
            int i = x - 'a';

            if(cur->v[i] == nullptr){
                cur->v[i] = new Node();
            }

            cur = cur->v[i];
            cur->refs++;
        }

        cur->wordIdx = idx;
    }
};

class Solution {
public:
    vector<string> ans;
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(int i, int j, int& n, int& m, vector<vector<char>>& board, Node* root, vector<string>& words){
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') return 0;

        char ch = board[i][j];
        int a = ch - 'a';

        if(root->v[a] == nullptr) return 0;

        Node* parent = root;
        root = root->v[a];

        int found = 0;

        if(root->wordIdx != -1){
            ans.push_back(words[root->wordIdx]);
            root->wordIdx = -1;
            found++;
        }

        board[i][j] = '#';

        for(auto& x : dir){
            int newI = i + x[0];
            int newJ = j + x[1];

            found += dfs(newI, newJ, n, m, board, root, words);
        }

        board[i][j] = ch;

        root->refs -= found;

        if(root->refs == 0){
            parent->v[a] = nullptr;
        }

        return found;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        Trie root1;

        for(int i = 0; i < words.size(); i++){
            root1.add(words[i], i);
        }

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(root1.root->refs == 0) return ans;

                int c = board[i][j] - 'a';

                if(root1.root->v[c] != nullptr){
                    int found = dfs(i, j, n, m, board, root1.root, words);
                    root1.root->refs -= found;
                }
            }
        }

        return ans;
    }
};



class Node{
public:
    vector<Node*> v;
    int wordIdx;
    int childCount;

    Node(){
        v.resize(26, nullptr);
        wordIdx = -1;
        childCount = 0;
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void add(string& s, int idx){
        Node* cur = root;

        for(auto& x : s){
            int i = x - 'a';

            if(cur->v[i] == nullptr){
                cur->v[i] = new Node();
                cur->childCount++;
            }

            cur = cur->v[i];
        }

        cur->wordIdx = idx;
    }
};

class Solution {
public:
    vector<string> ans;
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int i, int j, int& n, int& m, vector<vector<char>>& board, Node* root, vector<string>& words){
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#') return;

        char ch = board[i][j];
        int a = ch - 'a';

        if(root->v[a] == nullptr) return;

        Node* parent = root;
        root = root->v[a];

        if(root->wordIdx != -1){
            ans.push_back(words[root->wordIdx]);
            root->wordIdx = -1;
        }

        board[i][j] = '#';

        for(auto& x : dir){
            int newI = i + x[0];
            int newJ = j + x[1];

            dfs(newI, newJ, n, m, board, root, words);
        }

        board[i][j] = ch;

        if(root->childCount == 0 && root->wordIdx == -1){
            parent->v[a] = nullptr;
            parent->childCount--;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        Trie root1;

        int n = board.size();
        int m = board[0].size();

        vector<int> boardFreq(26, 0);

        for(auto& row : board){
            for(auto& x : row){
                boardFreq[x - 'a']++;
            }
        }

        for(int i = 0; i < words.size(); i++){
            vector<int> wordFreq(26, 0);
            bool possible = true;

            for(auto& x : words[i]){
                int c = x - 'a';
                wordFreq[c]++;

                if(wordFreq[c] > boardFreq[c]){
                    possible = false;
                    break;
                }
            }

            if(possible){
                root1.add(words[i], i);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int c = board[i][j] - 'a';

                if(root1.root->v[c] != nullptr){
                    dfs(i, j, n, m, board, root1.root, words);
                }
            }
        }

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
