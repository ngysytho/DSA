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

    void dfs(int u, vector<vector<int>>& adj, vector<int>& visited, vector<vector<string>>& accounts, set<string>& emailSet){
        visited[u] = 1;

        for(int i = 1; i < accounts[u].size(); i++){
            emailSet.insert(accounts[u][i]);
        }

        for(auto& x : adj[u]){
            if(!visited[x]){
                dfs(x, adj, visited, accounts, emailSet);
            }
        }
        return;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        unordered_map<int, set<string>> mp;
        int n = accounts.size();
        vector<int> visited(n, 0);
        
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                mp[i].insert(accounts[i][j]);
            }
        }
        

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = 1; k < accounts[i].size(); k++){
                    if(mp[j].find(accounts[i][k]) != mp[j].end()){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                        break;
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                set<string> emailSet;

                dfs(i, adj, visited, accounts, emailSet);

                vector<string> mergedAccount;
                mergedAccount.push_back(accounts[i][0]);
                mergedAccount.insert(mergedAccount.end(), emailSet.begin(), emailSet.end());

                ans.push_back(mergedAccount);
            }
        }
        return ans;
    }
};



class Solution {
public:

    
    unordered_map<string, vector<string>> adj;
    set<string> visited;


    void dfs(string s, vector<string>& component){
        component.push_back(s);

        visited.insert(s);

        for(auto& x : adj[s]){
            if(visited.find(x) == visited.end()){
                dfs(x, component);
            }
        }
        return;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        for(auto& account : accounts){
            string name = account[0];
            string firstGmail = account[1];

            for(int i = 1; i < account.size(); i++){
                string gmail = account[i];
                emailToName[gmail] = name;
                if(i > 1){
                    adj[firstGmail].push_back(account[i]);
                    adj[account[i]].push_back(firstGmail);
                }
            }
        }

        vector<vector<string>> ans;

        for(auto& [gmail, name] : emailToName){
            if(visited.find(gmail) == visited.end()){
                vector<string> component;

                dfs(gmail, component);

                sort(component.begin(), component.end());

                vector<string> merge;
                merge.push_back(name);

                merge.insert( merge.end(),component.begin(), component.end());

                ans.push_back(merge);

            }
        }


        return ans;
    }
};


class UnionSet{
    vector<int> parent;
    vector<int> rank;
public:
    UnionSet(int n){
        parent.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool find(int x1, int x2){
        int p1 = find(x1);
        int p2 = find(x2);

        if(p1 == p2) return false;

        p1 < p2 ? parent[p2] = p1 : parent[p1] = p2;

        return true;
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> gmailToAcc;
        int n =  accounts.size();

        UnionSet uf(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(gmailToAcc.count(accounts[i][j])){
                    uf.find(i, gmailToAcc[accounts[i][j]]);
                }else{
                    gmailToAcc[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, vector<string>> mp;

        for(auto& [gmail, id] : gmailToAcc){
            int leader = uf.find(id);
            mp[leader].push_back(gmail);
        }

        vector<vector<string>> ans;

        for(auto& [id, gmail] : mp){
            sort(gmail.begin(), gmail.end());

            vector<string> temp;

            temp.push_back(accounts[id][0]);

            temp.insert(temp.end(), gmail.begin(), gmail.end());

            ans.push_back(temp);
        }

        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
