```

I have overcomplicated this problem at first!! Went to use a set to store the path which is unnecessary!

The idea is simply do a dfs to search for every single path, until count exceed 1e6.

To avoid visiting nodes that already been visited on that path just mark it.

The reason why the above work is that, imagine we starting from node 1, and then do dfs on the first neighbour, by the time we finish that neighbour, we will do the next neighbour, which will be a completely different path from the first one, even if we did visit several common nodes, as we come from different node.

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MX = 2e5 + 5;
vi adj[MX];
bool vis[MX];
int cnt;
 
void dfs(int node){
    if (cnt >= 1e6) return;
 
    vis[node] = 1;
    cnt++;
 
    for(auto& i : adj[node]){
        if (!vis[i]){
            dfs(i);
        }
        if (cnt >= 1e6) return;
    }
 
    vis[node] = 0;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    for(int i{}; i < m; i++){
        int f,t ;
        cin >> f >>t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }
    
    dfs(0);
 
    cout << cnt;
 
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