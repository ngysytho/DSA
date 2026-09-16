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

class Node{
public:
    Node* children[26];
    bool end;

    Node(){
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        end = false;
    }
};

class Trie {
public:

    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;

        for(auto& x : word){
            int i = x - 'a';
            if(cur->children[i] == nullptr){
                cur->children[i] = new Node();
            }

            cur = cur->children[i];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(auto& x : word){
            int i = x - 'a';
            if(cur->children[i] == nullptr) return false;
            cur = cur->children[i];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(auto& x : prefix){
            int i = x - 'a';
            if(cur->children[i] == nullptr) return false;
            cur = cur->children[i];
        }
        return true;
    }
};

struct node{
    bool end = false;
    bool have = false;
};

class Trie {
public:
    unordered_map<string, node> mp;
    Trie() {
        
    }
    
    void insert(string word) {
        string s = "";
        for(auto& x : word){
            s += x;
            mp[s].have = true;
        }
        mp[word].end = true;
    }
    
    bool search(string word) {
        if(mp[word].end ) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        if(mp[prefix].have) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
