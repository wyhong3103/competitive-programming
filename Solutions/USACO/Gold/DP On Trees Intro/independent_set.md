```

We can root the tree at an arbitary node.

DP state 

dp[i][j] = total number of ways to paint the subtrees of i if i is j (j == 0 ? white : black)

DP Transition

The current node can only be black if all it's children is white.

Or else

Let vj...vn be children of i

dp[i][0] = product of (dp[vj][0] + dp[vj][1])

Basically total number of ways to paint all the subtrees.
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

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
vi adj[MX];
ll dp[MX][2];

void dfs(int node, int prev){
    // we can paint black if none of the children is black
    // else white
    dp[node][0] = 1;
    dp[node][1] = 1;

    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node);
        }
    }

    for(auto& i : adj[node]){
        if (i != prev){
            dp[node][1] = (dp[node][1] * dp[i][0]) % MOD;
            dp[node][0] = (dp[node][0] * (dp[i][0] + dp[i][1])) % MOD;
        }
    }
}

void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n-1; i++){
        int f,t ;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }
    dfs(0, -1);

    cout << (dp[0][0] + dp[0][1]) % MOD;

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