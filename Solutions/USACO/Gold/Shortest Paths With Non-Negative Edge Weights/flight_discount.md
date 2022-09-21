```
For each node, there's 2 different optimal distance (1 with coupon used, 1 without coupon used)

For each node, if the coupon is still available, we could use the coupon to transition to the next node, which would half the price.

As for the priority queue, we need to take the coupon into consideration as well. As it is part of the state of the node, and we need to prioritize state that has coupon.

dist[i][0]/vis[i][0] = state without coupon used, when the second dimension is 1, coupon is used, but it's different for the prirority queue, when the second dimenion is 1, that mean coupon is still available, vice versa.
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
ll dist[MX][2];
bool vis[MX][2];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        ll f, t, w;
        cin >> f >> t >> w;
        f--;t--;
        adj[f].pb({t,w});
    }    
    
    //{cost, coupon available, id}
    priority_queue<vll> q;
    q.push({0, 1, 0});
    for(int i{}; i < n; i++){
        dist[i][0] = LONG_LONG_MAX;
        dist[i][1] = LONG_LONG_MAX;
    }
    dist[0][0] = 0;

    while (!q.empty()){
        vll cur = q.top(); q.pop();

        if (vis[cur[2]][!cur[1]]) continue;
        vis[cur[2]][!cur[1]] = 1;
        for(auto& i : adj[cur[2]]){
            if (dist[i.fir][!cur[1]] > dist[cur[2]][!cur[1]] + i.sec){
                dist[i.fir][!cur[1]] = dist[cur[2]][!cur[1]] + i.sec;
                q.push({-(dist[cur[2]][!cur[1]]+i.sec), cur[1] , i.fir});
            }
            if (cur[1] && dist[i.fir][cur[1]] > dist[cur[2]][!cur[1]] + (i.sec/2)){
                dist[i.fir][cur[1]] = dist[cur[2]][!cur[1]] + (i.sec/2);
                q.push({-(dist[cur[2]][!cur[1]]+(i.sec/2)), !cur[1] , i.fir});
            }
        }
    }

    cout << dist[n-1][1];
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