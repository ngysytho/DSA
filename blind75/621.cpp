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
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        vector<int> v(128);

        for(int i = 0; i < size; i++){
            int j = tasks[i] - 'A';
            v[j]++;
        }
        sort(v.begin(), v.end(), greater<int>());

        vector<int> v1;
        for(int i = 0; i < 128; i++){
            if(v[i] != 0) v1.push_back(v[i]);
        }

        int n2 = v1.size();

        int ans = 0;
        int left = 0;
        int right = 0;
        int j = n;
        int check = 0;

        while(v1[0] != 0){
            right = 0;
            if(j >= 0 && j != n) ans += (j + 1);
            j = n;
            // 4 3 2 1 0
            while(j >= 0){
                if(right >= n2 || v1[right] == 0) break;

                v1[right]--;
                right++;
                ans++;
                j--;
            }
            sort(v1.begin(), v1.end(), greater<int>());
        }
        return ans;
    }
};


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);

        for(auto& x : tasks) v[x - 'A']++;

        sort(v.begin(), v.end());

        int maxM = 0;

        for(int i = 25; i >= 0; i--) if(v[i] == v[25]) maxM++;

        int ans = ((v[25] - 1) * (n + 1)) + maxM;
        return tasks.size() < ans ? ans : tasks.size();
    }
};



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int, int>> q;
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
