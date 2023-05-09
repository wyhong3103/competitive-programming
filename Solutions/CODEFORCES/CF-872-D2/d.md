```

Ans is 1 for k = 1 / 3

Or else

It's the sum of nodes (edges + 1) from every node i every node j, to count this, we can count the sum of distances from all nodes i to nodes j + total ways to choose diff i and j

TO count the total sum of all distances from node i to node j, we can do a DFS, and then for every children of the current subtree, let the number of nodes in the children subtree be x, the total time the edge between current node and this children will be used is x * (n-x), as we can select the nodes from both end, and we will have to go through this edge

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
 
 
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
 
ll fact[MX];
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}
 
void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i ) %MOD;
    }
}
 
ll ncr(ll n, ll r){
    ll num = (fact[n] * modpow(fact[n-r], MOD-2)) % MOD;;
    ll denom = fact[r];
    return (num * modpow(denom, MOD-2)) % MOD;
}
ll n, k;
 
ll dfs(int node, int prev, ll& total, auto& adj){
    ll cnt = 1;  
    for(auto& i : adj[node]){
        if (i != prev){
           ll ret = dfs(i, node, total, adj);
           cnt += ret;
           total = (total + ((ret) * (n-ret)) % MOD) % MOD;
        }
    }
    return cnt;
}
 
void solve(){
    cin >> n >> k;
 
    vector<vi> adj(n);
    vector<pi> edges; 
    for(int i{}; i < n-1; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        edges.pb({f,t});
        adj[f].pb(t);
        adj[t].pb(f);
    }
 
    if (k % 2){
        cout << 1 << '\n';
        return;
    }
    
    ll total = 0;
    dfs(0, -1, total, adj);
 
    cout << (((total + ncr(n,2)) % MOD) * modpow(ncr(n, 2), MOD-2)) % MOD;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    gen_fact();
    while(t--){
        solve();
    }
    return 0;
}
```