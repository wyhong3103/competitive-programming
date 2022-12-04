```

we can only travel from i to j, if there is an edge connects from i to j

AND

1. if di < dj
We can travel anytime we want!

2. if di >= dj
We can only travel once!

It makes sense to stop at dj, if we used the second operation, since going anywhere after that would only get us bigger length!

DP state

dp[i] = shortest distance we can have at i after travelling!

DP transition

dp[i] = min(dp[i], dp[j]), for every j such that dist[j] > dist[i], and j is a direct neighbour of i

dp[i] = min(dp[i], dist[j]), for every j such that dist[j] <= dist[i], and j is a direct neighbour of i
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


int dfs(int cur, vector<vi>& adj, vi& dp, vi& dist){
    if (dp[cur] != -1) return dp[cur];
    dp[cur] = dist[cur];

    for(auto& i : adj[cur]){
        if (dist[i] > dist[cur]){
            dp[cur] = min(dp[cur], dfs(i, adj, dp, dist));
        }
    }

    for(auto& i : adj[cur]){
        if (dist[i] < dist[cur]){
            dp[cur] = min(dp[cur], dist[i]);
        }
    }

    return dp[cur];
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n);
    vector<vi> adj_undir(n);

    for(int i{}; i < m; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
    }

    vi dist(n);
    queue<int> q;
    vector<bool> vis(n);
    q.push(0);
    vis[0] = 1;
    //get shortest distance
    while (!q.empty()){
        int cur = q.front();q.pop();
        for(auto& i : adj[cur]){
            if (!vis[i]){
                vis[i] = 1;
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }

    vi dp(n, -1);
    dp[0] = 0;
    for(int i{}; i < n; i++){
        dfs(i, adj, dp, dist);
    } 

    for(auto& i : dp) cout << i << ' ';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

```