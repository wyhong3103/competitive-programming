```

path starts in one node and ends in another node.

every segment can only be visited excatly once, so it's basically a simple path between two nodes

each subtree, we could either let the current root be LCA (find 2 of the max child) , or we keep on extending upward

must ends in different intersection, path length gotta be at least 1

DP state

dp[i][0] = maximal blocked way for subtree i, if i is a LCA of two of the children

dp[i][1] = maximal blocked way for subtree i, if i is a single branched that is waiting to connect it's parent

DP transition

dp[i][0] = max((number of adjacent nodes (including parent)) - 1 + 1 of the max(dp[vi][1]), number of adjcent nodes (including parent) - 2 + 2 of the max(dp[vi][1])

dp[i][1] = max(dp[i][1], number of adjcent nodes not including parent - 1 + dp[vi][1])

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
int dp[MX][2];

void dfs(int node, int prev){
    for(auto& i : adj[node]){
        if (i == prev) continue;
        dfs(i, node);
    }

    if (prev != -1) dp[node][1] = sz(adj[node])-1;

    //let current root be the top node
    set<pi, greater<pi>> bst;
    for(auto& i : adj[node]){
        if (i == prev) continue;
        dp[node][1] = max(dp[node][1], (int)(sz(adj[node])-2)  + (dp[i][1]));
        bst.insert({dp[i][1], i});
    }
    
    //let current root be lca
    if (sz(bst) >= 1){
        auto it = bst.begin(); 
        dp[node][0] = (int)(sz(adj[node])-1) + ((*it).fir);
    }
    if (sz(bst) >= 2){
        auto it = bst.begin(); 
        auto it2 = (++bst.begin()); 
        dp[node][0] = max(dp[node][0], (int)(sz(adj[node])-2) + (*it).fir + (*it2).fir);
    }
}

void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    dfs(0, -1);

    int mx = 0;
    for(int i{}; i < n; i++){
        mx = max({mx, dp[i][0], dp[i][1]});
    }
    cout << mx;
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