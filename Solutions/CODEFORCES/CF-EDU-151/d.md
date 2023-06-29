```

Not hard to see that k will always be one particular point we can reach if there isn't a condition.

So is there a way to compute the answer for each k?

Yes, for each point i, the minimum of prefix sum starting from i is how much points we can cancel out.

So we want the point that lets us cancel the most.


Why is prefix minimum the total points we can cancel out?

Think about this, if we currently at k, any negative that is added to it right away is cancelled out, it is also the prefix minimum.

There might some addition, but if we ever reach k again, and below it, it's just the same as creating new prefix minimum.

The idea is for every newly created minimum, we won't go below k if we don't have a new minimum, (not hard to see why this is true), so the total points we have cancelled out is the minmum of prefix sum from the point

We dont need segtree, we can just compute suffix min

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
/*
 
k is always one of the value you could sum up to
 
if we set a particular value k, how to compute the max rating?
 
k is only a good number, if we can ever reach it
 
the highest first point we can reach?
 
we want to find a point such that most lost is cancelled
 
prefix min is the total we will lost
 
*/
 
 
// Be careful of unused value / garbage value
// Segment tree for min
struct SegTree{
    ll size;
    vll val;
    
    ll NEUTRAL_ELEMENT = LONG_LONG_MAX;
 
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, 0LL);
    }
 
    ll merge(ll a, ll b){
        return min(a, b);
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
 
void solve(){
    int n;
    cin >> n;
 
    vll a(n);
    for(auto& i : a) cin >> i;
    
 
    ll cur = 0;
    vll pf(n);
    for(int i{}; i < n; i++){
        cur += a[i];
        pf[i] = cur;
    }
 
    SegTree st;
    st.init(n);
    st.build(pf);
 
    pll mn{st.query(0, n), 0};
    cur = 0;
    for(int i{}; i < n; i++){
        cur += a[i];
        //find pf min 
        mn = min(mn, {st.query(i, n) - cur, cur});
    }
 
    cout << mn.sec << '\n';
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