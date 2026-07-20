#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>


using namespace std;


class Solution {
public:


    int maxArea_false(vector<int>& height) {
        int n = height.size();
        long long ans = -1;
        vector<pair<int,int>> p;
        for(int i = 0; i < n; i++){
            p.push_back({height[i], i});
        }

        sort(p.begin(), p.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        });

        for(int i = 0; i < n; i++){
            auto it = upper_bound(p.begin(), p.end(), make_pair(p[i].first, 999999999));
            //if(it == p.end()) continue;
            ans = max(ans, 1ll*p[i].first * abs(p[i].second - it->second));
        }

        return ans;

    }

    int maxArea_1(vector<int>& height) {
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        int n = height.size();
        long long ans = -1;

        vector<pair<int,int>> p;
        for(int i = 0; i < n; i++){
            p.push_back({height[i], i});
        }

        //sort(p.begin(), p.end(), cmp);

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                ans = max(ans, 1ll*p[i].first * (abs(p[i].second - p[j].second)));
            }
        }

        return ans;

    }

    int maxArea(vector<int>& height) {
        long long left = 0, right = height.size() - 1, ans = -1;
        while(left < right){
            ans = max(ans, (right - left) * (min(height[left], height[right])));
            
            if(height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }

};

int main(){
    int n; cin >> n;

    vector<int> v(n,0);
    for(int i = 0; i < n; i++) cin >> v[i];
    Solution sol;
    cout << sol.maxArea(v);
}