```

We can do euler tour to store in and out for each nodes.

The subtree of node i is simply the range from in to out.

To get the maximal node in the subtree, we can do range query in the range.

If the rooted node is in the subtree, answer is maximal outside of that subtree range.

How to know the range? We can do binary lifting to find direct child of that node.

Cancerous Implementation

SegTree + Binary Lifting + Euler Tour

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

int n;

struct SegTree{
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
        return max(a, b);
    }

    void build(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x] = a[lx];
            }
            return;
        }
 
        int m = (lx+rx)/2;
        build(a, (x*2)+1, lx, m);
        build(a, (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void build(vi& a){
        build(a, 0, 0, size);
    }
 
    void set(int i, ll v, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = v;
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            set(i, v, (x*2)+1, lx, m);
        }else{
            set(i, v, (x*2)+2, m, rx);
        }
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }


    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    ll query(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return merge(query(l, r, (x*2)+1, lx, m), query(l, r, (x*2)+2, m, rx));
    }
 
    ll query(int l, int r){
        return query(l, r, 0, 0, size);
    }
};

void dfs(int node, int prev, vector<pi>& p, vi& tour, vll& a, int curdep, vi& dep, auto& up, vector<vi>& adj){
    if (prev != -1) up[node][0] = prev;
    dep[node] = curdep;

    p[node].fir = sz(tour);
    tour.pb(a[node]);
    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node, p, tour, a, curdep+1, dep, up, adj);
        }
    }
    p[node].sec = sz(tour);
    tour.pb(a[node]);
}

int lift(int node, int k, auto& up){
    for(int i{}; i < __lg(n)+1; i++){
        if (k & (1 << i)) node = up[node][i];
    } 
    return node;
}

int getmx(int u, int v, SegTree& st, vector<pi>& p, auto& up, vi& dep, int toursz){
    if (u == v){
        return st.query(0, toursz);
    }
    if (dep[v] > dep[u]){
        int child = lift(v, dep[v]-dep[u]-1,up);
        if (up[child][0] == u){
            return max(st.query(0, p[child].fir), st.query(p[child].sec+1, toursz));
        }
    }
    return st.query(p[u].fir, p[u].sec+1);
}

void solve(){
    cin >> n;

    vll a(n);
    for(auto& i : a) cin >> i;
    
    vector<vi> adj(n);
    for(int i{}; i < n-1; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    vector<pi> p(n);
    vi tour;

    vector<vi> up(n, vi(__lg(n) +1, -1));
    vi dep(n);

    dfs(0, -1, p, tour, a,0, dep, up, adj);

    SegTree st;
    st.init(sz(tour)+1);
    st.build(tour);

    //preprocess
    for(int i{1}; i < __lg(n)+1; i++){
        for(int j{1}; j < n; j++){
            if (up[j][i-1] != -1) up[j][i] = up[up[j][i-1]][i-1];
        }        
    }

    int q;
    cin >> q;
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1){
            u--;
            st.set(p[u].fir, v);
            st.set(p[u].sec, v);
        }else{
            u--;v--;
            cout << getmx(v, u, st, p, up, dep, sz(tour)) << '\n';
        }
    }     
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}

```