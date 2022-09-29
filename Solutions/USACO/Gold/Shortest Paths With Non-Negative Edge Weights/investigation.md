```

We are to find the


shortest path

number of shortest path

min dist (such that each weight = 1) in shortest path

max dist (such that each weight = 1) in shortest path

We could do DAG DP, process it in dijktra's order.

Because it guarantee us the optimal path in everything.

let dp[i] = number of ways to reach i-th node in shortest path 
let mn[i] = minimal path weighted 1 to reach i-th node in shortest path  
let mx[i] = maximal path weighted 1 to reach i-th node in shortest path 

If at any point, we found a shorter distance to a node, we replace everything. If we found the equal distance to a node, we do

dp[i] += dp[j] % MOD
mn[i] = min(mn[i], mn[j]+1)
mx[i] = max(mx[i], mx[j]+1)

This will guarantee us the answer because we process the node in the shortest possible path.

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



const int MOD = 1e9 + 7;
const int MX = 1e5 + 5;

vector<pll> adj[MX];
ll dist[MX];
bool vis[MX];
ll mn[MX];
ll mx[MX];
ll dp[MX];


void solve(){
    int n, m;
    cin >> n >> m;
    
    for(int i{}; i < m; i++){
        ll f, t, w;
        cin >> f >> t >> w;
        f--;t--;
        adj[f].pb({t, w});
    }

    for(int i{}; i < n; i++){
        dist[i] = LONG_LONG_MAX;
        mn[i] = LONG_LONG_MAX;
    }

    dist[0] = 0;
    mn[0] = 0;
    mx[0] = 0;
    dp[0] = 1;
    priority_queue<pll> q;
    q.push({0, 0});
    
    while (!q.empty()){
        ll cur = q.top().sec; q.pop();

        if (vis[cur]) continue;
        
        vis[cur] = 1;

        for(auto& i : adj[cur]){
            if (dist[i.fir] == dist[cur]+i.sec){
                mn[i.fir] = min(mn[i.fir], mn[cur]+1);
                mx[i.fir] = max(mx[i.fir], mx[cur]+1);
                dp[i.fir] = (dp[i.fir] + dp[cur]) % MOD;
                q.push({-dist[i.fir], i.fir});
            }
            else if (dist[i.fir] > dist[cur]+i.sec){
                dist[i.fir] = dist[cur]+i.sec; 
                mn[i.fir] = mn[cur]+1;
                mx[i.fir] = mx[cur]+1;
                dp[i.fir] = dp[cur];
                q.push({-dist[i.fir], i.fir});
            }
        }
    }

    cout << dist[n-1] << ' ' << dp[n-1] << ' ' << mn[n-1] << ' ' << mx[n-1];

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