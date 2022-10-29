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
    vector<pll> val;
    
    pll NEUTRAL_ELEMENT = {INT_MAX, -1};

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.resize(2*size);
    }
 
    pll merge(pll a, pll b){
        if (a.fir > b.fir) return b;
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

void dfs(int node,  vi& tour, vi& depth, int& dep){
    tour.pb(node);
    depth.pb(dep);
    for(auto& i : adj[node]){
        dep++;
        dfs(i, tour, depth, dep);
        dep--;
        tour.pb(node);
        depth.pb(dep);
    }
}


void solve(){
    int n, q;
    cin >> n >> q;

    for(int i{1}; i <= n-1; i++){
        int f;
        cin >> f;
        f--;
        adj[f].pb(i);
    }

    vi tour;
    vi depth;
    int dep = 0;
    dfs(0, tour, depth, dep);

    vi at(n);
    for(int i{}; i < sz(tour); i++){
        at[tour[i]] = i;
    }

    SegTree st;
    st.init(sz(depth)+1);
    st.build(depth);

    while(q--){
        int a, b;
        cin >> a >> b;
        a--;b--;
        if (at[a] > at[b]) swap(a, b);
        cout << tour[st.query(at[a], at[b]+1)]+1 << '\n';;
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