#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

#define ll long long

using namespace std;

int dx[]={1,0,0,0};
int dy[]={0,0,1,0};


int a[1001][1001];
bool visited[1001][1001];
ll n, m, k, cnt;



void dfs(int i, int j){
    if(i == n && j == m){
        cnt++;
        return;
    }
    visited[i][j] = true;
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1&& i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 0 && !visited[i1][j1]) dfs(i1,j1);
    }
     visited[i][j] = false;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int b, c;
        cin >> b>> c;
        a[b][c] = 1;
    }
    dfs(1,1);
    cout << cnt;
}
