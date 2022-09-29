```
Dijktra's , but instead of only looking for the shortest path, we're looking for k shortest path, which basically mean

instead of 

dist[N]

it would be 

dist[N][K]

same goes to vis

dist[N][K] doesn't mean the K-th smallest distance to reach node N, it means one of the k shortest distance.

intiially all dist[N][K] will be set to INF, except for dist[0][0].

We will greedily assign distance, by prioritizing INF first. If every dist[N][i] , 0 <= i < k, has been filled, then we will select the largest among these to assign the new distance.

And lastly, sort the K distance to reach node N and print it in ascending order.
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


const int MXN = 1e5 + 5;
const int MXK = 10;
vector<pll> adj[MXN];
ll dist[MXN][MXK];
bool vis[MXN][MXK];

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;

    for(int i{}; i < m; i++){
        ll f, t, w;
        cin >> f >> t >> w;
        f--;t--;
        adj[f].pb({t, w});
    }

    for(int i{}; i < n; i++){
        for(int j{}; j < k; j++){
            dist[i][j] = LONG_LONG_MAX;
        }
    }


    dist[0][0] = 0;
    priority_queue<pair<ll, pi>> q;
    q.push({0, {0, 0}});

    while (!q.empty()){
        pll cur = q.top().sec; q.pop();
        if (vis[cur.fir][cur.sec]) continue;
        vis[cur.fir][cur.sec] = 1;

        for(auto& i : adj[cur.fir]){
            bool found = 0;
            for(int j{}; j < k; j++){
                if (dist[i.fir][j] == LONG_LONG_MAX){
                    dist[i.fir][j] = dist[cur.fir][cur.sec] + i.sec;
                    q.push({-dist[i.fir][j], {i.fir, j}});
                    found = 1;
                    break;
                }
            }
            if (!found){
            	//Find the largest among the K shortest distance found
                priority_queue<pll> bst;
                for(int j{}; j < k; j++){
                    if (dist[i.fir][j] > dist[cur.fir][cur.sec] + i.sec){
                        bst.push({dist[i.fir][j], j});
                    }
                }
                if (sz(bst)){
                    ll optimal = bst.top().sec;
                    dist[i.fir][optimal] = dist[cur.fir][cur.sec] + i.sec;
                    q.push({-dist[i.fir][optimal], {i.fir, optimal}});
                }
            }
        }
    }

    vll res;
    for(int i{}; i < k; i++){
        res.pb(dist[n-1][i]);
    }
    sort(all(res));
    for(auto& i :res) cout << i << ' ';
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