```

Bruteforce every pairs, and then do DP with segtree in sorted order by end point, we can do coordinate compression on segtree to find the relative index

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
 
 
struct SegTree{
    ll size;
    vll val;
    
    ll NEUTRAL_ELEMENT = LONG_LONG_MIN;
 
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, 0);
    }
 
    ll merge(ll a, ll b){
        return max(a, b);
    }
 
    void set(int i, ll v, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = max(val[x], v);
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
 
void solve(){
    int n;
    cin >> n;
 
    vector<pi> lr(n);
    for(auto& i : lr) cin >> i.fir >> i.sec;
 
    vector<pi> combined;
 
    //endpoint
    vi ep;
    ep.pb(-1);
    for(int i{}; i < n; i++){
        ep.pb(lr[i].fir);
        ep.pb(lr[i].sec);
        for(int j{}; j < i; j++){
            if (min(lr[i].sec, lr[j].sec) - max(lr[j].fir, lr[i].fir) < 0) continue;
            pi r = {min(lr[i].fir, lr[j].fir), max(lr[i].sec, lr[j].sec)};
            combined.pb(r);
        }
    }
    
    sort(all(combined), [](pi& l, pi& r){
        return l.sec < r.sec;
    });
 
    sort(all(ep));
    ep.resize(unique(all(ep)) - ep.begin());
 
    SegTree st;
    st.init(sz(ep));
   
    for(auto& i : combined){
        int prev = lower_bound(all(ep), i.fir) - ep.begin();
        int index = lower_bound(all(ep), i.sec) - ep.begin();
        st.set(index, st.query(0, prev) + 2);
    }
 
    cout << n-st.query(0, sz(ep)) << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```