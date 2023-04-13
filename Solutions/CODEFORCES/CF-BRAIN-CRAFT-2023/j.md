```

We can reverse the edges and do SCC.

Then DP on SCCs to get the max each color can get.

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
 
void dfs(int node, vi& order, vector<vi>& adj, vector<bool>& vis){
    if (vis[node]) return;
    vis[node] = 1;
    for(auto& i :adj[node]){
        dfs(i, order, adj, vis);
    }
    order.pb(node);
}
 
void dfs2(int node, vi& comp, vector<vi>& adj_i, vector<bool>& vis){
    if (vis[node]) return;
    vis[node] = 1;
    comp.pb(node);
    for(auto& i :adj_i[node]){
        dfs2(i, comp, adj_i, vis);
    }
}
 
ll solve(){
    int n, m, k;
    cin >> n >> m >> k;
 
    //color of i-th ball
    vi c(n);
    for(auto& i : c){
        cin >> i;
        i--;
    }
 
    //price of color i
    vll p(n);
    for(auto& i : p) cin >> i;
    
    vector<vi> adj(n);
    vector<vi> adj_i(n);
 
    while(m--){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[t].pb(f);
        adj_i[f].pb(t);
    }
 
    vector<bool> vis(n);
    vi order;
    for(int i{}; i < n; i++){
        dfs(i, order, adj, vis);
    }
 
    reverse(all(order));
 
    fill(all(vis), 0);
 
    //creating components
    //assigning roots to all components
    //setting max value of all componets
    vi top;
    vi root(n);
    vll value(n);
    for(auto& i : order){
        if (vis[i]) continue;
        vi comp;
        dfs2(i, comp,adj_i, vis);
        top.pb(i);
        for(auto& j : comp){
            root[j] = i;
            value[i] = max(value[i], p[j]);
        }
    } 
 
    //forming SCC GRAPH DAG
    vector<vi> adj_scc(n);
    for(int i{}; i < n; i++){
        for(auto& j : adj[i]){
            if (root[i] != root[j]){
                adj_scc[root[i]].pb(root[j]);
            }
        }
    }
 
 
    vll dp(n);
    for(int i{}; i < n; i++) dp[root[i]] = value[root[i]];
        
    for(auto& i : top){
        for(auto& j : adj_scc[i]){
            dp[j] = max(dp[j], dp[i]);
        }
    }
 
    vll new_price;
    for(auto& i : c){
        new_price.pb(dp[root[i]]);
    }
 
    sort(all(new_price), greater<ll>());
    ll sm = 0;
    for(int i{}; i < k; i++){
        sm += new_price[i];
    }
    return sm;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >>t;
    while(t--){
        cout << solve();
        if (t) cout << '\n';
    }
    return 0;
}
```