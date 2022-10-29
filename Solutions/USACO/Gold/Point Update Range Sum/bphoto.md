```

Left first and then right!

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

    void setHelper(int i, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x]++;
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            setHelper(i,  (x*2)+1, lx, m);
        }else{
            setHelper(i,  (x*2)+2, m, rx);
        }
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void set(int i){
        setHelper(i, 0, 0, size);
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

void solve(){
    int n;
    cin >> n;


    vll a(n);
    for(auto& i : a) cin >> i;

    vll sorted = a;
    sorted.pb(1e9);
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    SegTree lt;
    lt.init(sz(sorted)+1);

    vector<pi> total(n);

    for(int i{}; i < n; i++){
        int index = upper_bound(all(sorted), a[i]) - sorted.begin();
        total[i].fir += lt.query(index, sz(sorted));
        lt.set(index);
    }

    SegTree rt;
    rt.init(sz(sorted)+1);

    for(int i{n-1}; i >= 0; i--){
        int index = upper_bound(all(sorted), a[i]) - sorted.begin();
        total[i].sec += rt.query(index, sz(sorted));
        rt.set(index);
    }

    ll res = 0;
    for(int i{}; i < n; i++){
        res += max(total[i].fir, total[i].sec) > min(total[i].fir, total[i].sec) * 2;
    }
    cout << res;
    
}
 
int main(){
    setio("bphoto");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
 

```