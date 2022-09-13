```

We just need to make sure that we process the nodes in order.

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

const int MX = 1e5;
vector<pi> adj[MX];
bool vis[MX];

void dfs(int node, deque<int>& order){
    vis[node] = 1;
    for(auto& i : adj[node]){
        if (!vis[i.fir]){
            dfs(i.fir, order);
        }
    }
    order.push_front(node);
}

void solve(){
    ll n, m, c;
    cin >> n >> m >> c;
    
    vll res(n);
    for(auto& i : res) cin >> i;
    
    for(int i{}; i < c; i++){
        int f, t, x;
        cin >> f >> t >> x;
        f--;t--;
        adj[f].pb({t,x});
    }
    
    deque<int> order;
    for(int i{}; i < n; i++){
        if (!vis[i]){
            dfs(i, order);
        }
    }
    
    for(auto& i : order){
        for(auto& j : adj[i]){
            res[j.fir] = max(res[j.fir], res[i]+j.sec);
        }
    }
    for(auto& i : res) cout << i << '\n';

}   
 
int main(){
    setio("timeline");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```