```

Find the maximal

b1 + b2 + b3 - (r-l)

b1 + b2 + b3 -r + l

Not hard to see that, for a range [l,r], optimal move is to have a[l] = b1, a[r] = b3

Sol

Fix middle element, i, find the max a[j] + l, j < i, find the max a[j] - r, j > i

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
    vector<ll> val;
    
    ll NEUTRAL_ELEMENT = LONG_LONG_MIN;
 
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, NEUTRAL_ELEMENT);
    }
 
    ll merge(ll a, ll b){
        return max(a, b);
    }
 
    void build(vll& a, int x, int lx, int rx){
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
 
    void build(vll& a){
        build(a, 0, 0, size);
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
    /*
    void print(){
        int cnt = -1;
        for(int i{}; i < size*2 - 1; i++){
            if (__lg(i+1) != cnt){
                cout << '\n';
                cnt = __lg(i+1);
            }
            cout << val[i] << ' ';
        }
    }
 
    */
};
 
 
 
void solve(){
    int n;
    cin >> n;
    vll a(n);
    for(auto& i : a) cin >> i;
 
    SegTree st1, st2;
    st1.init(n);
    st2.init(n);
    
    vll l(n), r(n);
    for(int i{}; i < n; i++){
        l[i] = a[i] + i + 1;
        r[i] = a[i] - i - 1;
    }
 
    st1.build(l); st2.build(r);
 
    ll mx = 0;
    for(int i{1}; i < n-1; i++){
        mx = max(mx, a[i] + st1.query(0, i) + st2.query(i+1, n));
    }
    cout << mx << '\n';
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