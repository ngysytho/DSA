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


class MedianFinder {
    vector<int> data;

public:
    MedianFinder() {}

    void addNum(int num) {
        data.push_back(num);
    }

    double findMedian() {
        sort(data.begin(), data.end());
        int n = data.size();
        if (n & 1) {
            return data[n / 2];
        } else {
            return (data[n / 2] + data[n / 2 - 1]) / 2.0;
        }
    }
};


class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        l.push(num);
        r.push(l.top());
        l.pop();
        
        if(r.size() > l.size()){
            l.push(r.top());
            r.pop();
        }
    }
    
    double findMedian() {
        return l.size() > r.size() ? l.top() : (l.top() + r.top())/2.00;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
