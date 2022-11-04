```

DP state

dp[i][0/1] = maximum matching if dp[i] is the root (solving for its subtree) and it's / not an endpoint of another matching

DP transition

For dp[i][0] we could get the max of any dp[children of i] either and endpoint or not an endpoint

For dp[i][1] we could also get the same, but if we've decided to add a non-endpoint node, we could add an edge between this node and that node! Which would increment dp[i][1] by 1. (We can only add an edge if we're considering at least one non-end point node for all children)

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
int dp[MX][2];

vi adj[MX];

void dfs(int node, int prev){
    bool found = 0;
    for(auto& i : adj[node]){
        if (i == prev) continue;
        dfs(i, node);
        dp[node][0] += max(dp[i][1], dp[i][0]);
        if (dp[i][0] >= dp[i][1]){
            dp[node][1] += dp[i][0];
            found = 1;
        }else{
            dp[node][1] += dp[i][1];
        }
    }
    if (found) dp[node][1]++;
}

void solve(){
    int n;
    cin >> n;
    for(int i{}; i < n-1; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) ;
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