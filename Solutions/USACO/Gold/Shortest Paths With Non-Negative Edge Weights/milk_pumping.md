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

const int MX = 1e3 + 5;
vector<vll> adj[MX];
//{min cost, max flow rate}
ll dist[MX];
bool vis[MX];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        ll f, t, w, r;
        cin >> f >> t >> w >> r;
        f--;t--;
        adj[f].pb({t, w, r});
        adj[t].pb({f, w, r});
    }    
    
    ll mx = 0;
    for(int i{1}; i <= 1000; i++){
        //bruteforce the min flow rate
        for(int j{}; j < n; j++) dist[j] = INT_MAX;
        memset(vis, 0, sizeof(vis));
        dist[0] = 0;

        priority_queue<pll> q;
        q.push({0, 0});

        while (!q.empty()){
            pll cur = q.top(); q.pop();
            if (vis[cur.sec]) continue;
            vis[cur.sec] = 1;
            for(auto& j : adj[cur.sec]){

                if (j[2] < i) continue;

                if (dist[cur.sec] + j[1] < dist[j[0]]){
                    dist[j[0]] = dist[cur.sec] + j[1];
                    q.push({-dist[j[0]], j[0]});
                }
            }
        }
        if (dist[n-1] != INT_MAX){
            mx = max(((ll)1e6 * i)/dist[n-1], mx);
        }
    }
    cout << mx;
}
 
int main(){
    setio("pump");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```