```

Compute the distance from 1 and from N for every node. Because of the fact that a node can travel at max by M each time, and this is a DAG.

So we can do DP, and to not include node k for each run, we simply need to find for each city j, 1 <= k-j <= M, for each city l that j can reach, s.t l > k, answer is simply dp[j] + dp2[l] + 1.

l > k, because for l < k, could be coming from k.

```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MX = 1e5 + 5;
int dp[MX];
int dp2[MX];
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<string> a(n);
    for(auto& i : a) cin >> i;
 
    for(int i{}; i < n; i++) dp[i] = INT_MAX;
    for(int i{}; i < n; i++) dp2[i] = INT_MAX;
 
    dp[0] = 0;
 
    for(int i{}; i < n; i++){
        if (dp[i] == INT_MAX) continue;
        for(int j{}; j < m; j++){
            if (a[i][j] == '1') dp[i+j+1] = min(dp[i+j+1], dp[i]+1);
        }
    }
 
    dp2[n-1] = 0;
    for(int i{n-2}; i >= 0; i--){
        for(int j{}; j < m; j++){
            if (a[i][j] == '1' && dp2[i+j+1] != INT_MAX) dp2[i] = min(dp2[i], dp2[i+j+1]+1);
        }
    }
 
    for(int i{1}; i < n-1; i++){
        int mn = INT_MAX;
        for(int j{}; j < m; j++){
            for(int k{}; k < m; k++){
                if (i-j-1 >= 0 && i-j+k > i && a[i-j-1][k] == '1' && dp[i-j-1] != INT_MAX && dp2[i-j+k] != INT_MAX) mn = min(dp[i-j-1]+dp2[i-j+k]+1, mn);
            }
        } 
        cout << (mn == INT_MAX ? -1 : mn) << ' ';
    }
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```