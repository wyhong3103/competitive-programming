```

Let's try to solve for subtrees first.

state

dp[i] = number of ways subtrees can be painted s.t i-th node is painted black

transition

dp[i] = product(dp[c]+1) for every children c of i

+ 1 because we need to consider the state where its white

Solve for all roots

It's pretty simple what we need to do to get the answer for all roots.

With the parent as a children subtree answer, p,

The new p we pass to children c is simply, p * dp[i] / dp[c]

But here comes the problem, we're not dealing with a prime modulo, but a modulo m that could be an integer.

So the idea is to simply, compute the prefix and suffix of product, and then dp[i] / dp[c] is simply prefix[a] * suffix[b], a and b is the previos node in the adjacency list & next node in the adjacency list s.t a & b is not the parent.


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
vi adj[MX];
ll dp[MX];
ll pref[MX];
ll suf[MX];
ll ans[MX];
ll n;
ll m;

void dfs(int node, int prev){
    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node);
        }
    }

    ll cur = 1;
    for(int i{}; i < sz(adj[node]); i++){
        if (adj[node][i] == prev) continue;
        pref[adj[node][i]] = (cur * (dp[adj[node][i]] + 1)) % m;
        cur = pref[adj[node][i]];
    }

    cur = 1;
    for(int i{sz(adj[node])-1}; i >= 0; i--){
        if (adj[node][i] == prev) continue;
        suf[adj[node][i]] = (cur * (dp[adj[node][i]] + 1)) % m;
        cur = suf[adj[node][i]];
    }

    dp[node] = cur;
}

void dfs2(int node, int prev, ll p){
    p++;
    ans[node] = (p * dp[node]) % m;

    for(int i{}; i < sz(adj[node]); i++){
        if (adj[node][i] == prev) continue;

        ll l = 1;
        ll r = 1;
        
        for(int j{i-1}; j >= 0; j--){
            if (adj[node][j] != prev){
                l = pref[adj[node][j]];
                break;
            }
        }

        for(int j{i+1}; j < sz(adj[node]); j++){
            if (adj[node][j] != prev){
                r = suf[adj[node][j]];
                break;
            }
        }

        dfs2(adj[node][i], node, (((l * r) % m) * p ) % m);
    }
}

void solve(){
    cin >> n >> m;

    for(int i{}; i < n-1; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    dfs(0, -1);
    dfs2(0, -1, 0);
    for(int i{}; i < n; i++) cout << ans[i] << '\n';
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