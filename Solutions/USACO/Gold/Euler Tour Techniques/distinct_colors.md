```

Flatten the tree with euler tour.

Process distinct value query with SegTree.

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


// Segment tree for min
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
        return a + b;
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
};

const int MX = 2e5 + 5;
vi adj[MX];

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
    
    vi a(n);
    for(auto& i : a) cin >> i;

    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    vector<pi> tour(n);
    vi ids(n);
    int cnt = -1;
    dfs(0, -1, tour, ids, cnt);

    vi euler(n);
    for(int i{}; i < n; i++) euler[i] = a[ids[i]];

    vector<vi> r(n);
    for(int i{}; i < n; i++){
        r[tour[i].sec].pb(i);
    }

    vi res(n);

    SegTree st;
    st.init(n+1);

    map<int,int> lst;

    for(int i{}; i < n; i++){
        if (lst.count(euler[i])){
            st.set(lst[euler[i]], 0);
        }
        lst[euler[i]] = i;
        st.set(i ,1);

        for(auto& j : r[i]){
            res[j] = st.query(tour[j].fir,i+1);
        }
    }

    for(auto& i : res) cout << i << ' ';
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