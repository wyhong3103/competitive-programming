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
ll dist[MX];
bool vis[MX];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        ll f, t, w;
        cin >> f >> t >> w;
        f--;t--;
        adj[f].pb({t,w});
    }    
    
    priority_queue<pll> q;
    q.push({0, 0});
    for(int i{}; i < n; i++) dist[i] = LONG_LONG_MAX;
    dist[0] = 0;

    while (!q.empty()){
        pi cur = q.top(); q.pop();

        if (vis[cur.sec]) continue;
        vis[cur.sec] = 1;
        for(auto& i : adj[cur.sec]){
            if (dist[i.fir] > dist[cur.sec] + i.sec){
                dist[i.fir] = dist[cur.sec]+i.sec;
                q.push({-(dist[cur.sec]+i.sec), i.fir});
            }
        }
    }

    for(int i{}; i < n; i++) cout << dist[i] << ' ';
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