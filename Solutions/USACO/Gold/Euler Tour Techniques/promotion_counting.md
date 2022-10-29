```

Flatten the tree with euler tour technique.

Keep sorted array in each segment (we can use 2 pointer to merge array in O(N)). count number of element that is bigger than x in log n time in each involved segment [in[x], out[x].

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

struct SegTree{
    ll size;
    vector<vll> val;
    
    ll NEUTRAL_ELEMENT = 0;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.resize(2*size);
    }
 
    void merge(vll& a, vll& b, vll& cur){
        int p1 = 0, p2 = 0;
        while (p1 < sz(a) && p2 < sz(b)){
            if (a[p1] > b[p2]){
                cur.pb(b[p2]);
                p2++;
            }else{
                cur.pb(a[p1]);
                p1++;
            }
        }
        while (p2 < sz(b)){
            cur.pb(b[p2]);
            p2++;
        }
        while (p1 < sz(a)){
            cur.pb(a[p1]);
            p1++;
        }
    }

    void buildHelper(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x].pb(a[lx]);
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
    ll queryHelper(int l, int r, ll v, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x].end() - lower_bound(all(val[x]), v);
        }
        int m = (lx + rx) / 2;
        return queryHelper(l, r, v, (x*2)+1, lx, m)  + queryHelper(l, r,v, (x*2)+2, m, rx);
    }
 
    ll query(int l, int r, ll v){
        return queryHelper(l, r, v, 0, 0, size);
    }
    /*
    void printTree(){
        int cnt = -1;
        for(int i{}; i < size*2; i++){
            if (__lg(i+1) != cnt){
                cout << '\n';
                cnt = __lg(i+1);
            }
            cout << val[i] << ' ';
        }
    }

    */
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

    vll a(n);
    for(auto& i : a) cin >> i;

    for(int i{1}; i <= n-1; i++){
        int p;
        cin >> p;
        p--;
        adj[p].pb(i);
    }
    
    vector<pi> tour(n);
    vi ids(n);
    int cnt = -1;
    dfs(0, -1, tour, ids, cnt);

    vi euler(n);
    for(int i{}; i < n; i++){
        euler[i] = a[ids[i]];
    }


    SegTree st;
    st.init(n+5);
    st.build(euler);

    for(int i{}; i < n; i++){
        cout << st.query(tour[i].fir+1, tour[i].sec+1, a[i]) << '\n';
    }
}

 
int main(){
    setio("promote");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
 

```