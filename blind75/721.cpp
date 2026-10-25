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
    unordered_map<string, vector<string>> adj;
    unordered_set<string> visited;

    void dfs(const string& email, vector<string>& component) {
        visited.insert(email);
        component.push_back(email);

        for (const string& neighbor : adj[email]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, component);
            }
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        // 1. Build the graph in O(N * K) time
        for (const auto& account : accounts) {
            const string& name = account[0];
            const string& firstEmail = account[1];

            for (int i = 1; i < account.size(); i++) {
                const string& email = account[i];
                emailToName[email] = name;

                // Connect the first email with all other emails in the account
                if (i > 1) {
                    adj[firstEmail].push_back(email);
                    adj[email].push_back(firstEmail);
                }
            }
        }

        // 2. Traverse connected components via DFS
        vector<vector<string>> mergedAccounts;

        for (const auto& [email, name] : emailToName) {
            if (visited.find(email) == visited.end()) {
                vector<string> component;
                dfs(email, component);

                // 3. Sort emails alphabetically
                sort(component.begin(), component.end());

                // 4. Prepend the account name
                vector<string> merged;
                merged.push_back(name);
                merged.insert(merged.end(), component.begin(), component.end());

                mergedAccounts.push_back(merged);
            }
        }

        return mergedAccounts;
    }
};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
