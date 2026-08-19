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



class DSU{
public:
    int n;
    vector<int> parent;
    
    DSU(int n1){
        n = n1;
        parent.resize(n);

        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int node){
        if(parent[node] != node){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool unionS(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return false;

        if(pa > pb) swap(pa, pb);

        parent[pa] = pb;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        DSU dsu(numCourses);

        for(auto& x : prerequisites){
            if(!dsu.unionS(x[0], x[1])) return false;
        }

        return true;
    }
};




class Solution {
public:


    bool dfs(int i, vector<vector<int>>& v, vector<int>& visited){
        if(visited[i] == 1) return false;
        if(visited[i] == 2) return true;

        visited[i] = 1;
        for(auto& x : v[i]){
            if(!dfs(x, v, visited)) return false;
        }

        visited[i] = 2;
        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses);
        vector<int> visited(numCourses, 0);

        for(auto& x : prerequisites){
            v[x[1]].push_back(x[0]);
        }

        for(auto& x : prerequisites){
            if(!dfs(x[1], v, visited)) return false;
        }

        return true;


    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> v(numCourses);

        for(auto& x : prerequisites){
            indegree[x[0]]++;
            v[x[1]].push_back(x[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int Nnode = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            Nnode++;
            for(auto x1 : v[x]){
                indegree[x1]--;
                if(indegree[x1] == 0){
                    q.push(x1);
                }
            }
        }
        
        return Nnode == numCourses;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
