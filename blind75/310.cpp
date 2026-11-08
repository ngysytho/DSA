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


class Solution {
public:

    vector<int> heightTree;

    void dfs(int n, vector<vector<int>>& adj, vector<int>& visited, int i, int height){
        if(visited[i]) return;

        visited[i] = 1;

        for(auto& x : adj[i]){
            dfs(n, adj, visited,x, height + 1);
        }
        heightTree[i] = max(heightTree[i], height);
        return;
    }


    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        heightTree.assign(n, 0);
        vector<pair<int, int>> pii;
        vector<int> ans;

        for(auto& x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> visited(n, 0);

        for(int i = 0; i < n; i++){
            visited.assign(n, 0);

            dfs(n, adj, visited, i, 0);
        }

        for(int i = 0; i < heightTree.size(); i++){
            pii.push_back({i, heightTree[i]});
        }

        sort(pii.begin(), pii.end(),[](pair<int, int>& a, pair<int, int>& b){
            return a.second < b.second;
        });


        int d = pii[0].second;

        for(auto& x : pii){
            if(x.second == d){
                ans.push_back(x.first);
            }else break;
        }

        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> adj;

    int dfs(int node, int parent){
        int height = 0;

        for(auto& x : adj[node]){
            if(x == parent) continue;

            height = max(height, 1 + dfs(x, node));
        }

        return height;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vector<int> ans;

        for(auto& x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int minHeight = n;

        for(int i = 0; i < n; i++){
            int heightRoot = dfs(i, -1);

            if(minHeight  == heightRoot){
                ans.push_back(i);
            }else if(heightRoot < minHeight){
                ans = {i};
                minHeight = heightRoot;
            }
        }
        return ans;

    }
};




class Solution {
public:
// Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
//Output: [3,4]
    vector<vector<int>> adj;
    vector<vector<int>> dp;


    void dfs(int node, int parent){
        for(auto& nei : adj[node]){
            if(nei == parent) continue;

            dfs(nei, node);

            int curHeight = 1 + dp[nei][0];

            if(curHeight > dp[node][0]){
                dp[node][1] = dp[node][0];
                dp[node][0] = curHeight;
            }else if(curHeight > dp[node][1]){
                dp[node][1] = curHeight;
            }
        }
    }

    void dfs1(int node, int parent, int topHeight){
        if(topHeight > dp[node][0]){
            dp[node][1] = dp[node][0];
            dp[node][0] = topHeight;
        }else if(topHeight > dp[node][1]) dp[node][1]= topHeight;

        for(auto& nei : adj[node]){
            if(nei == parent) continue;

            int child = 1 + (dp[node][0] == dp[nei][0] + 1 ? dp[node][1] : dp[node][0]);
            dfs1(nei, node, child);
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        dp.assign(n, vector<int>(2, 0));
        vector<int> ans;
        int minHeight = n;

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }


        dfs(0, -1);
        dfs1(0, -1, 0);

        for(int i = 0; i < n; i++) minHeight = min(minHeight, dp[i][0]);

        for(int i = 0; i < n; i++){
            if(minHeight == dp[i][0]) ans.push_back(i);
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> centroids;
    int nodeB;

    pair<int, int> dfs(int node, int parent){
        int farthestNode = node, maxHeight = 0;

        for(int neighbor : adj[node]){
            if(neighbor == parent) continue;
            auto res = dfs(neighbor, node);

            if(res.second + 1 > maxHeight){
                maxHeight = res.second + 1;
                farthestNode = res.first;
            }
        }

        return {farthestNode, maxHeight};
    }

    bool findCentroids(int node, int parent){
        if(node == nodeB){
            centroids.push_back(node);
            return true;
        }

        for(int neighbor : adj[node]){
            if(neighbor == parent) continue;

            if(findCentroids(neighbor, node)){
                centroids.push_back(node);
                return true;
            }
        }

        return false;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int nodeA = dfs(0, -1).first;
        nodeB = dfs(nodeA, -1).first;

        findCentroids(nodeA, -1);

        int N = centroids.size();

        return N % 2 == 0 ? vector<int>{centroids[N / 2], centroids[N / 2 - 1]} : vector<int>{centroids[N/2]};

    }
};



class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent;

    pair<int, int> dfs(int node, int par) {
        int farthestNode = node, maxHeight = 0;

        for (int neighbor : adj[node]) {
            if (neighbor == par) continue;

            parent[neighbor] = node;
            auto res = dfs(neighbor, node);

            if (res.second + 1 > maxHeight) {
                maxHeight = res.second + 1;
                farthestNode = res.first;
            }
        }

        return {farthestNode, maxHeight};
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        adj.resize(n);
        parent.assign(n, -1);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int nodeA = dfs(0, -1).first;

        parent.assign(n, -1);

        int nodeB = dfs(nodeA, -1).first;

        vector<int> path;
        int curr = nodeB;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }

        int N = path.size();
        if (N % 2 == 0) {
            return {path[N / 2 - 1], path[N / 2]};
        } else {
            return {path[N / 2]};
        }
    }
};


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        vector<int> degree(n, 0);

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            degree[i] = adj[i].size();
            if(degree[i] == 1) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){

            if(n <= 2){
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }
                return ans;
            }
            
            int size = q.size();

            for(int i = 0; i < size; i++){
                n--;
                int node = q.front();
                q.pop();
                for(int& nei : adj[node]){
                    degree[nei]--;

                    if(degree[nei] == 1) q.push(nei);
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
