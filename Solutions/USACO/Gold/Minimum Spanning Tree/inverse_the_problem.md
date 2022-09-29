```

We're given a distance matrix (distance matrix != adjacency matrix).

We need to find whether the given matrix represents a positive weighted tree.

We can form the tree using MST algorithm by using all the distance on the matrix betwee node i and j as an edge. Since all the smallest edge that connects up nodes are the actual edges, because between any two adjacent nodes i and j, the shortest edge that connect them is their actual edge, also there is only one unique path to reach i to j in a tree. It is proven that all the actual edges will be selected through out the MST formation, 

The proof is, 

say we got node A, node B, node C

A -- B -- C

AC = x
AB = y
BC = z

x >= y, x >= z

y and z will be selected first because of their small weight, this will be the same for every nodes in the distance matrix.

By the time where we get to an edge that do not connect up adjacent edge, the edges between will already be selected, therefore proven that we don't need that edge.

And we will use Prim's Algorithm, to assign edges to node, and create an adjacency list.

Then, we can simply do a DFS on every node, and then check if the information matches up with the distance matrix.

Time complexity = O(N + M log M + N^2)
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

const int MX = 2005;
ll dist[MX][MX];
bool vis[MX];
vector<pll> adj[MX];


void dfs(int from, int node, ll cur_dist,bool& ok){
    if (dist[from][node] != cur_dist || ((from == node && cur_dist != 0) || (from != node && cur_dist == 0))) ok = 0;
    vis[node] = 1;
    for(auto& i : adj[node]){
        if (!vis[i.fir]){
            dfs(from, i.fir, cur_dist+i.sec, ok);
        }
    }
}


void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            cin >> dist[i][j];
        }
    }
    

    //{edge weight, {f, t}}
    priority_queue<pair<ll, pi>> q;
    q.push({0, {-1, 0}});
    while (!q.empty()){
        pair<ll, pi> cur = q.top(); q.pop();
        if (vis[cur.sec.sec]) continue;
        vis[cur.sec.sec] = 1;
        if (cur.sec.fir != -1){
            adj[cur.sec.fir].pb({cur.sec.sec, -cur.fir});
            adj[cur.sec.sec].pb({cur.sec.fir, -cur.fir});
        }

        for(int i{}; i < n; i++){
            if (i == cur.sec.sec || vis[i]) continue;
            q.push({-min(dist[cur.sec.sec][i], dist[i][cur.sec.sec]), {cur.sec.sec, i}});
        }
    }

    bool ok = 1;
    for(int i{}; i < n; i++){
        memset(vis, 0, sizeof(vis));
        dfs(i, i, 0, ok);
    }

    cout << (ok ? "YES" : "NO");
    
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