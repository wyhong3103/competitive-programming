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

const int MX = 2e5 + 5;
vi adj[MX];

void dfs_lca(int node, int prev, vi& tour, vi& depth, int& dep){
    tour.pb(node);
    depth.pb(dep);
    for(auto& i : adj[node]){
        if (i != prev){
            dep++;
            dfs_lca(i, node, tour, depth, dep);
            dep--;
            tour.pb(node);
            depth.pb(dep);
        }
    }
}


void processSparse(int n, vi& a, vector<vector<pi>>& sparse){
    for(int i{}; i <= __lg(n); i++){
        for(int j{}; j <= n-(1 << i); j++){
            if (!i){
                sparse[i].pb({a[j], j});
            }else{
                int w = i-1;
                if (sparse[w][j] > sparse[w][j+(1<<w)]){
                    sparse[i].pb(sparse[w][j+(1 << w)]);
                }else{
                    sparse[i].pb(sparse[w][j]);
                }
            }
        } 
    }
}

int getLCA(int u, int v, vi& tour, vector<vector<pi>>& sparse, vi& ids){
    int l = min(ids[u], ids[v]), r = max(ids[v], ids[u]);
    int w = (__lg(r-l+1));
    return tour[(min(sparse[w][l], sparse[w][r-(1 << w)+1])).sec];
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i{1}; i <= n-1; i++){
        int p;
        cin >> p;
        p--;
        adj[p].pb(i);
    }

    vi tour;
    vi depth;
    int dep = 0;
    dfs_lca(0, -1, tour, depth, dep);

    vector<vector<pi>> sparse(__lg(sz(depth))+1);
    
    processSparse(sz(depth), depth, sparse);

    vi ids(n);
    for(int i{}; i < sz(tour); i++){
        ids[tour[i]] = i;
    }
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