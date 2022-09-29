```
Instead of doing a dfs counting nodes in the original graph, we could simply check if the number of edges is equal to n-1. (that's the number of edges a tree has)

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
int ranking[MX];
int parent[MX];
bool vis[MX];
vi adj[MX];

int dsu_get(int a){
    return parent[a] = (parent[a] == a ? a : dsu_get(parent[a]));
}

bool dsu_union(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);

    if (a == b) return false;
    
    if (ranking[a] == ranking[b]) ranking[a]++;

    if (ranking[a] > ranking[b]){
        parent[a] = b;
        ranking[b]++;
    }else{
        parent[b] = a;
        ranking[a]++;
    }

    return true;
}

struct Edge{
    int f, t;
    ll w;

    bool operator<(const Edge& y) const {
        return y.w > w;
    }
};

void dfs(int node, int& cnt){
    if (vis[node]) return;
    cnt++;
    vis[node] = 1;
    for(auto& i : adj[node]){
        dfs(i, cnt);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<Edge> a(m);
    for(auto& i : a){
        cin >> i.f >> i.t >> i.w;
        i.f--;i.t--;
        adj[i.f].pb(i.t);
        adj[i.t].pb(i.f);
    }
    sort(all(a));

    for(int i{}; i < n; i++) parent[i] = i;
    
    ll sm = 0;
    for(auto& i : a){
        if (dsu_get(i.f) != dsu_get(i.t)){
            dsu_union(i.f, i.t);
            sm += i.w;
        }
    }

    int cnt = 0;
    dfs(0, cnt);
    if (cnt != n) {
        cout << "IMPOSSIBLE";
    }else{
        cout << sm;
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