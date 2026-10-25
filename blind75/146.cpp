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

class LRUCache {
public:
    int n;
    vector<int> v = vector<int>(10001, -1);
    unordered_map<int, int> mp;

    int j = 0;
    int sz = 0;

    LRUCache(int capacity) {
        n = capacity;
    }

    vector<pair<int,int>> sortt() {
        vector<pair<int,int>> temp(mp.begin(), mp.end());

        sort(temp.begin(), temp.end(),
            [](auto& a, auto& b) {
                return a.second < b.second;
            });

        return temp;
    }

    int get(int key) {
        if(v[key] == -1) {
            return -1;
        }

        mp[key] = j++;
        return v[key];
    }

    void put(int key, int value) {

        if(v[key] == -1) {

            if(sz >= n) {
                auto temp = sortt();

                int lruKey = temp[0].first;

                v[lruKey] = -1;
                mp.erase(lruKey);

                sz--;
            }

            v[key] = value;
            mp[key] = j++;
            sz++;
        }

        else {
            v[key] = value;
            mp[key] = j++;
        }
    }
};


struct Node{
    int key;
    int val;
    Node* pre;
    Node* next;

    Node(int key, int val): key(key), val(val), pre(nullptr), next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    int n;
    Node* Left;
    Node* Right;

    // null 8 7 6 9 null
    void insert(Node* node){
        Node* prev = Right->pre;
        prev -> next = node;
        node->pre = prev;
        node->next= Right;

        Right->pre = node;
    }

    void deleted(Node* node){
        Node* pre = node->pre;
        Node* next = node->next;
        pre->next = next;
        next->pre = pre;
    }
public:
    LRUCache(int capacity) {
        n = capacity;
        cache.clear();
        Left = new Node(0,0);
        Right = new Node(0,0);
        Left->next =  Right;
        Right->pre = Left;
    }

    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            deleted(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;

    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            deleted(cache[key]);
            delete(cache[key]);
        }

        Node* newNode = new Node(key, value);

        insert(newNode);
        cache[key] = newNode;

        if(cache.size() > n){
            Node* lru = Left->next;
            deleted(lru);
            cache.erase(lru->key);
            delete(lru);
        }
    }
};


class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
        } else if (cache.size() == capacity) {
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
