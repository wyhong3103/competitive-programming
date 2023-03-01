```

The number of points basically only depends on the first vertex we choose to paint black.

The reason is, if we've chosen a node to be painted black, coloring any adjacent neighbours of it in any order would have the same exact number of gains, bc when we're to paint child i (we eventually have to paint it), we will be getting point i regardless.

We can solve for all roots, but before that how do we calculate point i as if i is a root of the subtree?

pretty simple,


dp[i] = sum(dp[children of i]) + sz[i] 

this is pretty obvious

Now comes the tricky part, how do we compute for all roots?

ans[i] = p + dp[i] - sz[i] + n

p is the answer for the subtree of parents (parent as a child of i). 

dp[i] is the original number, subtracting sz[i] basically equivalent to the number of points we gain by painting i-th node (with its subtree). Because this would be the first node to be painted, so we would + n, cus the component size of the first node is basically the tree.

How do we compute p?

if i is the actual root of the tree, and we're to pass to children c, 

p = dp[node]-dp[c]-sz[c]

We basically subtract the subtree that has c as a root, and then subtract the size of c, bc we only want the subtree with the root as a child of c.

For the rest of the node,

we need to use the p we receive from parent, and then

p = p + dp[i]-dp[c]-sz[i]+(n-sz[c])

visualize it helps.

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

const int MX = 2e5 + 5;
vi adj[MX];
ll dp[MX];
int sz[MX];
int n;

void dfs(int node, int prev){
    sz[node] = 1;
    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node);
            dp[node] += dp[i];
            sz[node] += sz[i];
        }
    }
    dp[node] += sz[node];
}

void dfs2(int node, int prev, ll p, ll& mx){
    if (prev != -1) mx = max(mx, p + (dp[node] - sz[node] + n));
    for(auto& i : adj[node]){
        if (i != prev){
            if (prev == -1) dfs2(i, node, dp[node]-dp[i]-sz[i], mx);
            else dfs2(i, node, p + (dp[node]-dp[i]-sz[node]+(n-sz[i])), mx);
        }
    }
}

void solve(){
    cin >> n;

    for(int i{}; i < n-1; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    dfs(0, -1);
    ll mx = 0;
    dfs2(0, -1, -1, mx);

    cout << max(mx, dp[0]);
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