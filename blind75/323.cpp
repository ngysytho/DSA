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

    void dfs(int edge, vector<vector<int>>& edges, vector<int>& visited){
        if(visited[edge]) return;
        visited[edge] = 1;
        
        for(auto x : edges[edge]){
            dfs(x, edges, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n + 2, 0);
        vector<vector<int>> v(n + 2);

        for(auto& x : edges){
            v[x[1]].push_back(x[0]);
            v[x[0]].push_back(x[1]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] != 0){
                continue;
            }
            else{
                ans++;
                dfs(i, v, visited);
            }
            
        }
        return ans;

    }
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        for (int node = 0; node < n; ++node) {
            if (!visit[node]) {
                bfs(adj, visit, node);
                res++;
            }
        }
        return res;
    }

private:
    void bfs(vector<vector<int>>& adj, vector<bool>& visit, int node) {
        queue<int> q;
        q.push(node);
        visit[node] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nei : adj[cur]) {
                if (!visit[nei]) {
                    visit[nei] = true;
                    q.push(nei);
                }
            }
        }
    }
};



class DSU{
public:
    int n;

    vector<int> parent;
    DSU(int a){
        n = a;
        parent.resize(n + 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int a){
        if(parent[a] == a) return a;
        
        parent[a] = find(parent[a]);
        return parent[a];
    }

    bool unite(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return false;
        if(pa < pb) swap(pa, pb);

        parent[pa] = pb;
        return true;
    }
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ans = 0;
        for(auto x : edges){
            if(dsu.unite(x[0], x[1])){
                ans++;
            }
        }
        return n - ans;
    }
};





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
