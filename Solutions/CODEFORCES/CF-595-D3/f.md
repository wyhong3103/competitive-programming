```

DP state

dp[i][j] = maximal weight of the subset of nodes selected in subtree of i, such that the distance of the closest node to i is of distance j

Of course, if j == 0, then we're including the root node!

DP transition

Situation 1, including root node

If we are to include root node, we can choose for each children, vi,

dp[i][0] = \sum_{vi = 0}^{sz(node)} max of dp[vi][j] (j > k)

This works because of the optimal substructure! dp[vi][j] is also optimized!


Situation 2, just taking the max of children node (pretty unnecessary i guess)

dp[i][j] = max(dp[i][j], dp[vi][j-1])



Situation 3, not including root i, but still going to take all children!

Notice that, if we are to include root i, we basically cannot take any children node that has j <= k, that is not the optimal answer!

Now, try to picture this, if we are to include node that is j <= k, what's going to happen?? How are we going to guarantee that every node has distance > k?


Now let j be the shortest distance of a children, and let l be the children that has the shortest distance node, that means we can only choose all siblings z such that it's shortest distance node take is >= max(k-j+1, j), dp[z][o >= max((k-j)+1, j) ] (basically when z is as a root, the shortest node it takes is o)

This will cover every situtation where we have to select multiple children without including the root node.

Implementation is a little hard to put in word, look at code might aid you in understanding this.

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

vi adj[205];
ll dp[205][205];

void dfs(int node, int prev, vll& a, ll k){
    for(auto& i : adj[node]){
        if (i == prev) continue;
        dfs(i, node, a, k);
    }

    dp[node][0] = a[node];
    for(auto& i : adj[node]){
        if (i == prev) continue;
        ll mx = 0;
        for(int j{k}; j <= 200; j++){
            mx = max(mx, dp[i][j]);
        }
        dp[node][0] += mx;
    }


    for(int j{}; j <= 200; j++){
        for(auto& i : adj[node]){
            if (i == prev) continue;
            dp[node][j] = max(dp[node][j], dp[i][j-1]);
        }
    }

    for(int j{1}; j <= 200; j++){
        //length of the shortest while not rooting!
        for(auto& i : adj[node]){
            if (i == prev) continue;
            ll total = dp[i][j-1];
            for(auto& l : adj[node]){
                if (l == prev || i == l) continue;
                ll mx = 0;
                for(int z{max((k-j)+1, (ll)j)}; z <= 200 ; z++){
                    mx = max(mx, dp[l][z-1]);
                }
                total += mx;
            }
            dp[node][j] = max(dp[node][j], total);
        }
    }
}
 
void solve(){
    int n, k;
    cin >> n >> k;

    vll a(n);
    for(auto& i : a) cin >> i;

    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    dfs(0, -1, a, k);

    ll mx = 0;
    for(int i{}; i <= 200; i++){
        mx = max(mx, dp[0][i]) ;
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