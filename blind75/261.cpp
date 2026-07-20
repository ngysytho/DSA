#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;




class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);

        for(const vector<int>& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        if(hasCycle(0, -1, adj, visited)) return false;

        for(auto x : visited){
            if(!x) return false;
        }
        return true;
    }

    bool hasCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        
        for(int nei : adj[node]){
            if(nei == parent){
                continue;
            }

            if(visited[nei]) return true;

            if(hasCycle(nei, node, adj, visited)) return true;
        }
        return false;
    }

    bool validTree_bfs(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);

        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        queue<pair<int,int>> q;

        q.push({0, -1});

        visited[0] = true;

        while(!q.empty()){
            pair<int, int> cur = q.front();

            q.pop();

            int node = cur.first;
            int parent = cur.second;

            for(int x : adj[node]){
                if(x == parent) continue;

                if(visited[x]) return false;

                visited[x] = true;
                q.push({x, node});
            }
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }

        return true;

    }

    bool validTree_dsu(int n, vector<vector<int>>& edges){
        if(edges.size() != n - 1) return false;

        DSU DSU(n);

        for(auto& e : edges){
            if(!DSU.unite(e[0], e[1])){
                return false;
            }

        }
        return DSU.components == 1;
    }

};


class DSU{
public:
    vector<int> parent;
    vector<int> size;
    int components;

    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        components = n;

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;

        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;

        if(size[pa] < size[pb]){
            swap(pa, pb);
        }

        parent[pb] = pa;
        size[pa] += size[pb];
        components--;
        return true;
    }
};

int main(){

}