```

Problem link : https://am.spoj.com/submit/BIRTHDAYTREE/

You're given a tree with n nodes and n - 1 edges and the weight of each edge. For every node you need to output the sum of all the weights when reaching all the other nodes. So for node 1 you independently count the sum of weights for reaching from 1 to node 2 and then add it to the sum for reaching 3 and so on. So you need to output that sum for every node. 

We can do dp on tree to solve this problem.

DP state

dp[i] = sum of distance of subtree i (i.e i as a root)
nodes[i] = number of nodes in subtree i
weight[i][j] = edge weight between i and j
p[i] = parent of i

DP transition

dp[i] = sum(dp[j] + (weight[i][j] * nodes[j])) for all j that is children of i

ans[i] = ans[p[i]] - dp[i] - (nodes[i] * weight[i][p[i]]) + dp[i] + ((n-nodes[i]) * weight[i][p[i]])

The idea of answer is, 

The sum to all the other nodes is just the same as it's parent i (not including subtree of i), and we could compute that with

ans[p[i]] - dp[i] - (nodes[i] * weight[i][p[i]])

dp[i] contribute to the last answer as the sum of distance in subtree i, and the edge between them got to be subtrated!

And then

+

dp[i] + ((n-nodes[i]) * weight[i][p[i]])

sum of distance of subtree i, and then the number of time we're going to use the edge between i and parent i, is just number of nodes in there, n - nodes[i]

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
vector<pll> adj[MX];

ll dp[MX];
ll ans[MX];
pi p[MX];
ll nodes[MX];
ll n;

int dfs(int node, int prev){
    nodes[node] = 1;

    for(auto& i : adj[node]){
        if (i.fir == prev) continue;
        p[i.fir] = {node, i.sec};
        nodes[node] += dfs(i.fir, node);
    }

    for(auto& i : adj[node]){
        if (i.fir == prev) continue;
        dp[node] += dp[i.fir] + (i.sec * nodes[i.fir]);
    }

    return nodes[node];
}

void dfs2(int node, int prev){
    if (node){
        ans[node]  = (ans[p[node].fir] - dp[node] - (nodes[node] * p[node].sec)) + dp[node] + ((n-nodes[node]) * p[node].sec);
    }
    
    for(auto& i : adj[node]){
        if (i.fir == prev) continue;
        dfs2(i.fir, node);
    }
}

void solve(){
    cin >> n;
    
    for(int i{}; i < n-1; i++){
        int f, t, w;
        cin >> f >> t >> w;
        f--;t--;
        adj[f].pb({t,w});
        adj[t].pb({f,w});
    }

    dfs(0, -1);

    ans[0] = dp[0];
    dfs2(0, -1);

    for(int i{}; i < n; i++){
        cout << ans[i] << '\n';
    }
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