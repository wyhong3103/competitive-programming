```

Flatten the tree with euler tour technique, use segment tree to answer how many element x is in the range!

Building segment tree takes N log N (log N levels, N per level for merging the map)

Another approach is to use binary search with euler tour technique, the idea is simple, we can store the number of nodes in depth d for every depth. Then when query is asked, simply binary search the subtree [in, out] when root = Ui.
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


// Segment tree for min
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
        for(auto& i : a) cur[i.fir] = i.sec;
        for(auto& i : b) cur[i.fir] += i.sec;
    }

    void buildHelper(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x][a[lx]]++;
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper(a, (x*2)+1, lx, m);
        buildHelper(a, (x*2)+2, m, rx);
        merge(val[(x*2)+1], val[(x*2)+2], val[x]);
    }
 
    void build(vi& a){
        buildHelper(a, 0, 0, size);
    }
 
    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    ll queryHelper(int l, int r, int v, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return (val[x].count(v) ? val[x][v] : 0);
        }
        int m = (lx + rx) / 2;
        return queryHelper(l, r, v, (x*2)+1, lx, m) + queryHelper(l, r, v, (x*2)+2, m, rx);
    }
 
    ll query(int l, int r, int v){
        return queryHelper(l, r, v, 0, 0, size);
    }
};

void dfs(int node, int prev, vector<pi>& tour, vi& ids, int& cnt){
    cnt++;
    ids[cnt] = node;
    tour[node].fir = cnt;
    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node, tour, ids, cnt);
        }
    }
    tour[node].sec = cnt;
}


void solve(){
    int n;
    cin >> n;

    for(int i{1}; i <= n-1; i++){
        int p;
        cin >> p;
        p--;
        adj[p].pb(i);
    }
    
    vi dist(n);
    vector<bool> vis(n);
    dist[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()){
        int cur = q.front(); q.pop();
        for(auto& i : adj[cur]){
            if (vis[i]) continue;
            vis[cur] = 1;
            dist[i] = dist[cur] + 1;
            q.push(i);
        }
    }


    vector<pi> tour(n);
    vi ids(n);
    int cnt = -1;
    dfs(0, -1, tour, ids, cnt);


    vi euler(n);

    for(int i{}; i < n; i++){
        euler[i] = dist[ids[i]];
    }

    SegTree st;
    st.init(n+5);
    st.build(euler);

    int Q = 0;
    cin >> Q;
    while(Q--){
        int u, d;
        cin >> u >> d;
        u--;
        cout << st.query(tour[u].fir, tour[u].sec+1, d) << '\n';
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