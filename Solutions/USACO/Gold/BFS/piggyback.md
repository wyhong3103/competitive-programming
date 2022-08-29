```

We can simply bruteforce on it. 

Let answer = shortest path from bessie and elsie to the end (without piggyback) with the corresponding energy.

For every node, if it's reachable by both bessie and elsie, find the shortest path from their initial location to that node with the corresponding amount of energy needed. Then, find the shortest path from that node to the end node with the corresponding amount of energy, the answer is the minium of them all.

We only need three distance array, bessie's, elsie's, ending's.
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

const int MX = 4e4;
vi adj[MX];

void bfs(int start, vi& dist){
    queue<int> q;
    q.push(start);
        
    while (!q.empty()){
        int cur = q.front(); q.pop();
        for(auto& i : adj[cur]){
            if (dist[i] == -1){
                dist[i] = dist[cur]+1;
                q.push(i);
            }
        }
    }
}

void solve(){
    ll b, e, p, n, m;
    cin >> b >> e >> p >> n >> m;

    for(int i{}; i < m; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }
    
    vi dist_b(n);
    vi dist_e(n);
    vi dist_n(n);
    fill(all(dist_b), -1);
    dist_b[0] = 0;
    fill(all(dist_e), -1);
    dist_e[1] = 0;
    fill(all(dist_n), -1);
    dist_n[n-1] = 0;
    bfs(0, dist_b);
    bfs(1, dist_e);
    bfs(n-1, dist_n);

    ll ans = (dist_b[n-1] * b) + (dist_e[n-1] * e);

    for(int i{}; i < n; i++){
        if (dist_b[i] != -1 && dist_e[i] != -1){
            ans = min(ans, (dist_b[i] * b) + (dist_e[i] * e) + (dist_n[i] * p));
        }
    }

    cout << ans;
}
    

int main(){
    setio("piggyback");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```