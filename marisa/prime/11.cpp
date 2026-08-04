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

int isPrime[1000005];// 0 1

int main(){
    freopen("cntprime1.inp", "r", stdin);
    freopen("cntprime1.out", "w", stdout);
    for(int i =2;i <= 1000000;i++){
        isPrime[i]=1;
    }
    isPrime[0]=0;
    isPrime[1]=0;
    
    for(int i = 2; i <= 1000000; i++){
        if(isPrime[i] == 0) continue;
        int j = i;
        int m = j;
        while(m <= 1000000){
            m += j;
            if(m > 1000000) break;
            isPrime[m] = 0;
        }
    }

    for(int i = 1; i <= 1000000; i++) isPrime[i] = isPrime[i] + isPrime[i - 1];

    int k;
    cin>>k;
    while (k>0){
        int a,b;
        cin>>a>>b;
        
        cout << isPrime[b] - isPrime[a - 1] << endl;
        k--;
    }
}
