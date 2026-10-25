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
#include <list>

using namespace std;

#define ll long long



class MinStack {
public:
    stack<long long> st;
    map<long long, long long> mp;
    long long IMax;
    MinStack() {
        mp.clear();
        IMax = 1e10;
    }
    
    void push(int value) {
        st.push(value);
        mp[value] = value;
    }
    
    void pop() {
        mp[st.top()] = IMax;
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        for(auto& x : mp){
            if(x.first == x.second){
                return x.first;
            }
        }
    }
};


class MinStack {
public:
    vector<int> st;
    vector<int> Min;
    MinStack() {
        st.clear();
        Min.clear();
    }
    
    void push(int value) {
        st.push_back(value);

        if(Min.empty() || Min.back() >= value){
            Min.push_back(value);
        }else{
            Min.push_back(Min.back());
        }
    }
    
    void pop() {
        st.pop_back();
        Min.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return Min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
