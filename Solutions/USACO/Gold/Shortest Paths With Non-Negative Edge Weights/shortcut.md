```

For each field i, count how many cows will cross path with the field as its shortest path to the barn.

Final answer is simply, for all i, max(t*cnt[i] - dist[i]*cnt[i])

Use node 1 as the source to search for the shortest path using dijkstra's, store the parent of every node along the shortest path. Reverse the direction of the path, eventually it will became a tree, and do a DFS to accumulate the count of subtree (i.e number of cows that will corss path with the field as its shortest barn to the barn).

The tricky part in here is to make sure the cow take the lexicographically smallest path. So the parameter in priority queue should be {-dist[i], -i}. (Default priority queue prioritize bigger element, negating the element makes the smallest the biggest).

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

const int MX = 1e4 + 5;
vector<pll> adj[MX];
//{dist, amount}
ll dist[MX];
ll p[MX];
ll cnt[MX];
bool vis[MX];

ll dfs(int node, vector<vi>& adj1){
    for(auto& i : adj1[node]){
        cnt[node] += dfs(i, adj1);
    }
    return cnt[node];
}


void solve(){
    ll n, m, t;
    cin >> n >> m >> t;

    for(int i{}; i < n; i++){
        cin >> cnt[i];
        dist[i] = LONG_LONG_MAX;
    }

    for(int i{}; i < m; i++){
        ll f, t, x;
        cin >> f >> t >> x;
        f--;t--;
        adj[f].pb({t, x});
        adj[t].pb({f, x});
    }

    priority_queue<pll> q;
    q.push({0, 0});
    dist[0] = 0;
    while (!q.empty()){
        ll cur = q.top().sec; q.pop();
        cur = -cur;
        if (vis[cur]) continue;
        vis[cur] = 1;
        for(auto& i : adj[cur]){
            if (dist[i.fir] == dist[cur] + i.sec){
                p[i.fir] = min(cur, p[i.fir]);
                q.push({-dist[i.fir], -i.fir});
            }
            else if (dist[i.fir] > dist[cur] + i.sec){
                dist[i.fir] = dist[cur] + i.sec;
                p[i.fir] = cur;
                q.push({-dist[i.fir], -i.fir});
            }
        }
    }

    vector<vi> adj1(n);
    for(int i{1}; i < n; i++){
        adj1[p[i]].pb(i);
    }

    memset(vis, 0, sizeof(vis));
    dfs(0, adj1);
    
    ll mx = 0;
    for(int i{}; i < n; i++){
        mx = max((dist[i]*cnt[i])-(t*cnt[i]), mx);
    } 
    cout << mx;
}

 
int main(){
    setio("shortcut");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```