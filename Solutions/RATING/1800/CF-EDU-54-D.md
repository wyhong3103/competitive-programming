```

n vertices and m edges

an undirected weighted graph no self loop/multiple edges

we only want k edges remain

a vertex is good iff the shortest dist from 1 to current vertex still has the same shortest dist after removing m-k edges.

we definitely want to start from the edge that connects to 1

we would never take an edge that wasn't the shortest path.

Proof

If we were to took the edge that connects node x, such that the total sum of weight atm wasn't the shortest path to x, that would mean every other node connects from x wasn't going to be the shortest path as well! (i.e it's a waste)

We can greedily pick edge that connects to a node that is the shortest path. There won't be any tradeoff, the idea is every edge gives you one more good vertex, it just doesn't matter which edge you pick, as long as it connects to one new good vertex.

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


struct Edge{
    ll t, w, index;
};

const int MX = 3e5 + 5;
vector<Edge> adj[MX];
bool vis[MX];

void dfs(int node, int& k, vi& good, ll& cur,  vll& dist){
    if (!k || vis[node]) return;
    vis[node] = 1;

    for(auto& i : adj[node]){
        if (!vis[i.t] && cur+i.w == dist[i.t] && k){
            cur += i.w;
            k--;
            good.pb(i.index);
            dfs(i.t, k, good, cur, dist);
            cur -= i.w;
        }
    }
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    for(int i{}; i < m; i++){
        int f, t, w;
        cin >> f >> t >> w;
        f--;t--;
        adj[f].pb({t, w, i});
        adj[t].pb({f, w, i});
    } 

    vll dist(n, LONG_LONG_MAX);
    dist[0] = 0;

    //{dist, node}
    priority_queue<pll> pq;
    pq.push({0, 0});

    while (!pq.empty()){
        ll cur = pq.top().sec;pq.pop();
        if (vis[cur]) continue;

        vis[cur] = 1;
        
        for(auto& i : adj[cur]){
            if (dist[i.t] > dist[cur] + i.w){
                dist[i.t] = dist[cur] + i.w;
                pq.push({-dist[i.t], i.t});
            }
        }
    }

    vi good;
    ll cur = 0;
    memset(vis, 0, sizeof(vis));

    dfs(0, k, good, cur, dist);

    cout << sz(good) << '\n';
    for(auto& i : good) cout << i+1 << ' ';

}

int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```