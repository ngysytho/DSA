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

class node{
public:
    node* v[26];
    bool end;

    node(){
        for(int i = 0; i < 26; i++) v[i] = nullptr;
        end = false;
    }
};


class WordDictionary {
public:
    node* root;
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* cur = root;
        for(auto& x : word){
            int i = x - 'a';
            if(cur->v[i] == nullptr){
                cur->v[i] = new node();
            }
            cur = cur->v[i];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        return check(root, word, 0);
    }

private:
    bool check(node*& root, string& word, int i){
        if(i == word.size()) return root->end;

        if(word[i] == '.'){
            for(auto& x : root->v){
                if(x != nullptr && check(x, word, i + 1)){
                    return true;
                }
            }
            return false;
        }

        if(root->v[word[i] - 'a']){
            return check(root->v[word[i] - 'a'], word, i + 1);
        }else{
            return false;
        }
    }
};


class WordDictionary {
public:

    unordered_map<int, vector<string>> mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
        bool ans = false;
        if(mp[word.size()].size() == 0) return false;
        for(auto& x : mp[word.size()]){
            bool check = true;
            for(int i = 0; i < word.size(); i++){
                if(word[i] == '.') continue;
                if(word[i] == x[i]) continue;
                check = false;
                break;
            }
            if(check) ans = check;
        }
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
