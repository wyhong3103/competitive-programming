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

struct SumSegTree{
    ll size;
    vll val;
    
    ll NEUTRAL_ELEMENT = 0;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, 0LL);
    }
 
    ll merge(ll a, ll b){
        return a + b;
    }

    void buildHelper(vll& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x] = a[lx];
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper(a, (x*2)+1, lx, m);
        buildHelper(a, (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void build(vll& a){
        buildHelper(a, 0, 0, size);
    }
 
    void setHelper(int i, ll v, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = v;
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            setHelper(i, v, (x*2)+1, lx, m);
        }else{
            setHelper(i, v, (x*2)+2, m, rx);
        }
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void set(int i, int v){
        setHelper(i, v, 0, 0, size);
    }


    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    ll queryHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return merge(queryHelper(l, r, (x*2)+1, lx, m), queryHelper(l, r, (x*2)+2, m, rx));
    }
 
    ll query(int l, int r){
        return queryHelper(l, r, 0, 0, size);
    }
};


// Segment tree for min
struct MinSegTree{
    ll size;
    vector<pll> val;
    
    pll NEUTRAL_ELEMENT = {LONG_LONG_MAX, -1};

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.resize(2*size);
    }
 
    pll merge(pll a, pll b){
        if (a.fir == b.fir) return a;
        else if (a.fir > b.fir) return b;
        else return a;
    }

    void buildHelper(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x] = {a[lx], lx};
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper(a, (x*2)+1, lx, m);
        buildHelper(a, (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void build(vi& a){
        buildHelper(a, 0, 0, size);
    }
 
    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    pll queryHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return merge(queryHelper(l, r, (x*2)+1, lx, m), queryHelper(l, r, (x*2)+2, m, rx));
    }
 
    ll query(int l, int r){
        return queryHelper(l, r, 0, 0, size).sec;
    }
};


void dfs_lca(int node, int prev, vi& tour_lca, vi& depth, int& dep){
    tour_lca.pb(node);
    depth.pb(dep);
    for(auto& i : adj[node]){
        if (i == prev) continue;
        dep++;
        dfs_lca(i, node, tour_lca, depth, dep);
        dep--;
        tour_lca.pb(node);
        depth.pb(dep);
    }
}

void dfs_path(int node, int prev, vi& tour_path){
    tour_path.pb(node);
    for(auto& i : adj[node]){
        if (i != prev){
            dfs_path(i, node, tour_path);
        }
    }
    tour_path.pb(node);
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }
    
    vi tour_lca;
    vi tour_path;
    vi depth;
    int dep = 0;
    dfs_lca(0, -1, tour_lca, depth, dep);
    dfs_path(0, -1, tour_path);

    vi ids_lca(n);
    vector<pi> ids_path(n, {-1, -1});
    vll euler;

    for(int i{}; i < sz(tour_path); i++){
        if (ids_path[tour_path[i]].fir == -1){
            ids_path[tour_path[i]].fir = i;
            euler.pb(1);
        }
        else{
            ids_path[tour_path[i]].sec = i;
            euler.pb(-1);
        }
    }
    for(int i{}; i < sz(tour_lca); i++){
        if (ids_lca[tour_lca[i]] == -1) ids_lca[tour_lca[i]] = i;
        else ids_lca[tour_lca[i]] = i;
    }


    MinSegTree min_st;
    min_st.init(sz(depth)+1);
    min_st.build(depth);

    SumSegTree sum_st;
    sum_st.init(sz(euler)+1);
    sum_st.build(euler);

    while(q--){
        int u, v;
        cin >> u >> v;
        u--;v--;
        //find LCA
        int lca = tour_lca[min_st.query(min(ids_lca[u], ids_lca[v]), max(ids_lca[v], ids_lca[u])+1)];
        ll res = 0;
        if (lca != u && lca != v){
            res = sum_st.query(ids_path[lca].fir, ids_path[u].fir+1) + sum_st.query(ids_path[lca].fir, ids_path[v].fir+1) - 2;
        }else{
            res = sum_st.query(ids_path[lca].fir, ids_path[(lca == u ? v : u)].fir+1) - 1;
        }
        cout << res << '\n';
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