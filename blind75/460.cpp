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
#include<list>

using namespace std;

#define ll long long



class LFUCache {
public:
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> cache;
    int n;

    LFUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        int freq = 0;

        for(auto& x : mp) {
            auto it = find(x.second.begin(), x.second.end(), key);

            if(it != x.second.end()) {
                freq = x.first;

                x.second.erase(it);
                break;
            }
        }

        mp[freq + 1].push_back(key);

        if(mp[freq].empty())
            mp.erase(freq);

        return cache[key];
    }

    void put(int key, int value) {
        if(n == 0) return;

        if(cache.find(key) != cache.end()) {
            cache[key] = value;
            get(key);
            return;
        }
        if(cache.size() >= n) {
            int Min = INT_MAX;

            for(auto& x : mp) {
                if(!x.second.empty())
                    Min = min(Min, x.first);
            }

            int removeKey = mp[Min].front();

            mp[Min].erase(mp[Min].begin());
            cache.erase(removeKey);

            if(mp[Min].empty())
                mp.erase(Min);
        }

        mp[1].push_back(key);
        cache[key] = value;
    }
};


struct Node{
    int freq;
    int key;
    int val;

    Node* next;
    Node* prev;

    Node(int key, int val, int freq): key(key), val(val), freq(freq),  next(nullptr), prev(nullptr){}

};



class LFUCache {
private:
    unordered_map<int, pair<Node*, Node*>> mp;
    unordered_map<int, Node*> cache;
    int n;
    int freq;

    void insert(Node* node, int level){
        Node* prev = mp[level].second -> prev;
        prev->next = node;
        node->prev = prev;
        node->next = mp[level].second;

        mp[level].second->prev = node;
    }


    void remove(Node* node, int level){
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    


public:

    LFUCache(int capacity) {
        n = capacity;
        mp.clear();
        cache.clear();
        freq = 0;
    }
    

    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            int level = node->freq;
            remove(node, node->freq);
            if(level + 1 > freq){
                Node* left = new Node(0, 0, level+ 1);
                Node* right = new Node(0, 0, level + 1);
                freq++;
                left->next = right;
                right->prev = left;
                mp[level + 1] = {left, right};
            }
            node->freq++;
            insert(node, node->freq);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(n == 0) return;
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            int level = node->freq;

            if(level + 1 > freq){
                Node* left = new Node(0, 0, level+ 1);
                Node* right = new Node(0, 0, level + 1);
                freq++;
                left->next = right;
                right->prev = left;
                mp[level + 1] = {left, right};
            }

            remove(node, node->freq);
            node->freq++;
            node->val = value;
            insert(node, node->freq);
            return;
        }

        if(cache.size() >= n){
            for(int i = 1; i <= freq; i++){
                if(mp[i].first->next != mp[i].second){
                    Node* node = mp[i].first->next;
                    remove(node, i);
                    cache.erase(node->key);
                    delete node;
                    break;
                }
            }
        }

        if(freq == 0){
            Node* left = new Node(0, 0, 1);
            Node* right = new Node(0, 0, 1);

            left->next = right;
            right->prev = left;

            mp[1] = {left, right};

            freq = 1;
        }

        Node* node = new Node(key, value, 1);
        cache[key] = node;
        insert(node, node->freq);
        return;
    }
};



struct Node{
    int freq;
    int key;
    int val;

    Node* next;
    Node* prev;

    Node(int key, int val, int freq)
        : key(key), val(val), freq(freq),
          next(nullptr), prev(nullptr) {}
};

class LFUCache {
private:
    // freq -> {left sentinel, right sentinel}
    unordered_map<int, pair<Node*, Node*>> mp;

    // key -> node
    unordered_map<int, Node*> cache;

    int n;
    int freq;       
    int minFreq;   


    void insert(Node* node, int level){
        Node* prev = mp[level].second->prev;

        prev->next = node;
        node->prev = prev;

        node->next = mp[level].second;
        mp[level].second->prev = node;
    }


    void remove(Node* node, int level){
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }


    void createLevel(int level){
        Node* left = new Node(0, 0, level);
        Node* right = new Node(0, 0, level);

        left->next = right;
        right->prev = left;

        mp[level] = {left, right};
    }


public:

    LFUCache(int capacity) {
        n = capacity;

        cache.clear();
        mp.clear();

        freq = 0;
        minFreq = 0;
    }


    int get(int key) {

        if(cache.find(key) == cache.end()) return -1;

        Node* node = cache[key];
        int level = node->freq;

        remove(node, level);
        if(level == minFreq &&
            mp[level].first->next == mp[level].second){
            minFreq++;
        }
        if(level + 1 > freq){
            createLevel(level + 1);
            freq++;
        }
        node->freq++;
        insert(node, node->freq);
        return node->val;
    }


    void put(int key, int value) {

        if(n == 0) return;

        if(cache.find(key) != cache.end()){

            Node* node = cache[key];
            int level = node->freq;

            remove(node, level);

            if(level == minFreq &&
                mp[level].first->next == mp[level].second){

                minFreq++;
            }
            if(level + 1 > freq){
                createLevel(level + 1);
                freq++;
            }
            node->freq++;
            node->val = value;
            insert(node, node->freq);
            return;
        }

        if(cache.size() >= n){
            Node* lru = mp[minFreq].first->next;
            remove(lru, minFreq);
            cache.erase(lru->key);
            delete lru;
        }

        if(freq == 0){
            createLevel(1);
            freq = 1;
        }
        Node* node = new Node(key, value, 1);
        cache[key] = node;
        insert(node, 1);
        minFreq = 1;
    }
};


class LFUCache {
public:
    struct Infor{
        int val;
        int freq;
        list<int>::iterator it;
    };

    unordered_map<int, Infor> cache;
    unordered_map<int, list<int>> freqList;

    int cap;
    int minFreq;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;

        int f = cache[key].freq;
        freqList[f].erase(cache[key].it);

        if(f == minFreq && freqList[f].empty()) minFreq++;
        cache[key].freq++;

        freqList[f+1].push_back(key);
        cache[key].it = prev(freqList[f+1].end());

        return cache[key].val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;

        if(cache.find(key) != cache.end()){
            cache[key].val = value;
            get(key);
            return;
        }

        if(cache.size() >= cap){
            int removeKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            cache.erase(removeKey);
        }

        freqList[1].push_back(key);
        cache[key] = {value, 1, prev(freqList[1].end())};
        minFreq = 1;
    }
};





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
