A better appraoch
```
Precompute LCAs.


Do a dfs from node 1 to node x, and store the nodes along the way from 1 to x on a stack, more specifically based on their milk type. Process all queries involving node x as one of the endpoint, do a LCA on node x and another endpoint of that query to retrieve the depth of LCA, and then check whether the top element on the stack of the color we want has deeper or equal depth. (Do not need to worry about whether it can reach one another, if element of color c exist on the path, it's either on the path from LCA to x, or LCA to another endpoint, so even though, we might not be able to get it during this point, we could still get it on the other endpoint)

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

const int MX = 2e5 + 5;
vi adj[MX];

void dfs(int node, int prev, vi& tour_lca, vi& depth, int& dep){
    tour_lca.pb(node);
    depth.pb(dep);
    for(auto& i : adj[node]){
        if (i != prev){
            dep++;
            dfs(i, node, tour_lca, depth, dep);
            dep--;
            tour_lca.pb(node);
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
    //get lca's depth
    return (min(sparse[w][l], sparse[w][r-(1 << w)+1])).fir;
}

struct Query{
    int t, c, id;
};

void dfs2(int node, int prev, vector<vector<Query>>& q, map<int,stack<int>>& milks, vi& colors, int& dep, vi& res, auto& tour, auto& sparse, auto& ids){
    dep++;
    milks[colors[node]].push(dep);

    for(auto& i : q[node]){
        res[i.id] |= (!milks[i.c].empty() && getLCA(node, i.t, tour, sparse, ids) <= milks[i.c].top());
    }

    for(auto& i : adj[node]){
        if (i != prev){
            dfs2(i, node, q, milks, colors, dep, res, tour, sparse, ids);
        }
    }

    milks[colors[node]].pop();
    dep--;
}

void solve(){
    int n, q;
    cin >> n >> q;

    vi a(n);
    for(auto& i : a) cin >> i;

    for(int i{1}; i <= n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    // get euler tour path for path query and lca
    vi tour_lca;
    vi depth;
    int dep = 0;
    dfs(0, -1, tour_lca, depth, dep);

    // precompute lca
    vector<vector<pi>> sparse(__lg(sz(depth))+1);
    
    processSparse(sz(depth), depth, sparse);

    vi ids_lca(n);
    for(int i{}; i < sz(tour_lca); i++){
        ids_lca[tour_lca[i]] = i;
    }

    vector<vector<Query>> queries(n);
    for(int i{}; i < q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        queries[a].pb({b, c, i});
        queries[b].pb({a, c, i});
    }

    map<int, stack<int>> milks;
    dep = -1;
    vi res(q);
    dfs2(0, -1, queries, milks, a, dep, res, tour_lca, sparse, ids_lca);
    for(auto& i : res) cout << i;
}
 
int main(){
    setio("milkvisits");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
 

```
Initial Approach
```

Flatten the tree with path trick & lca.

We can precompute LCA with sparse table in O(n log n) and then query in O(1)

Our goal is to check whether x exist from path i to j. We can accomplish that with segtree and unordered_map as a node and euler tour with path trick as the flattened tree. Though it almost TLEd, but still, it's AC.

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

const int MX = 2e5 + 5;
vi adj[MX];

void dfs(int node, int prev, vi& tour_lca, vi& tour_path, vi& depth, int& dep){
    tour_path.pb(node);
    tour_lca.pb(node);
    depth.pb(dep);
    for(auto& i : adj[node]){
        if (i != prev){
            dep++;
            dfs(i, node, tour_lca, tour_path, depth, dep);
            dep--;
            tour_lca.pb(node);
            depth.pb(dep);
        }
    }
    tour_path.pb(node);
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


struct SegTree{
    ll size;
    vector<unordered_map<int,int>> val;
    
    ll NEUTRAL_ELEMENT = 0;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.resize(2*size);
    }
 
    void merge(unordered_map<int,int>& a, unordered_map<int,int>& b, unordered_map<int,int>& cur){
        for(auto& i : a){
            cur[i.fir] = i.sec;
        }
        for(auto& i : b){
            cur[i.fir] += i.sec;
        }
    }

    void buildHelper(vi& a, vi& undo, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                //if it's in
                if (!undo[lx]){
                    val[x][a[lx]] = 1;
                }else{
                //if it's out
                    val[x][a[lx]] = -1;
                }
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper(a, undo, (x*2)+1, lx, m);
        buildHelper(a, undo, (x*2)+2, m, rx);
        merge(val[(x*2)+1], val[(x*2)+2], val[x]);
    }
 
    void build(vi& a, vi& undo){
        buildHelper(a, undo, 0, 0, size);
    }
 
    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    ll queryHelper(int l, int r, int v, int x, int lx, int rx){
        if (!val[x].count(v)) return 0;
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x][v];
        }
        int m = (lx + rx)/ 2;
        return queryHelper(l, r, v, (x*2)+1, lx, m) + queryHelper(l, r, v, (x*2)+2, m, rx);
    }
 
    ll query(int l, int r, int v){
        return queryHelper(l, r, v, 0, 0, size);
    }
};


int getLCA(int u, int v, vi& tour, vector<vector<pi>>& sparse, vi& ids){
    int l = min(ids[u], ids[v]), r = max(ids[v], ids[u]);
    int w = (__lg(r-l+1));
    return tour[(min(sparse[w][l], sparse[w][r-(1 << w)+1])).sec];
}

void solve(){
    int n, q;
    cin >> n >> q;

    vi a(n);
    for(auto& i : a) cin >> i;

    for(int i{1}; i <= n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    // get euler tour path for path query and lca
    vi tour_path;
    vi tour_lca;
    vi depth;
    int dep = 0;
    dfs(0, -1, tour_lca, tour_path, depth, dep);


    // precompute lca
    vector<vector<pi>> sparse(__lg(sz(depth))+1);
    
    processSparse(sz(depth), depth, sparse);

    vi ids_lca(n);
    for(int i{}; i < sz(tour_lca); i++){
        ids_lca[tour_lca[i]] = i;
    }

    vector<pi> ids_path(n, {-1, -1});

    vi undo;
    vi euler_path;
    for(int i{}; i < sz(tour_path); i++){
        if (ids_path[tour_path[i]].fir == -1){
            ids_path[tour_path[i]].fir = i;
            undo.pb(0);
        }else{
            ids_path[tour_path[i]].sec = i;
            undo.pb(1);
        }
        euler_path.pb(a[tour_path[i]]);
    }

    SegTree st;
    st.init(sz(euler_path) + 1);
    st.build(euler_path, undo);

    while(q--){
        int f, t, c;
        cin >> f >> t >> c;
        f--;t--;
        int lca = getLCA(f, t, tour_lca, sparse, ids_lca);
        if (lca != f && lca != t){
            cout << (st.query(ids_path[lca].fir, ids_path[f].fir+1, c)+st.query(ids_path[lca].fir, ids_path[t].fir+1, c) >= 1);
        }else{
            cout << (st.query(min(ids_path[f].fir,ids_path[t].fir), max(ids_path[f].fir,ids_path[t].fir)+1, c) >= 1);
        }
    }
    
}
 
int main(){
    setio("milkvisits");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
 

```