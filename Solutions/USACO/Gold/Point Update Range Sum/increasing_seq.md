```

For every i, simply get the sum to every element that is after i, that has bigger element.

Then the count for i, is simply the sum + 1. The reason we add 1 is because when i is alone, it has to be considered as well.

Basically for every i we find the total arrange including i! That's the reason we can connect to every element after us and prevent overcount!

It's like doing dp.

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

const int MOD = 1e9 + 7;
 
struct SegTree{
    ll size;
    vll val;
 
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        val.assign(size*2, 0LL);
    }
 
    ll merge(ll l, ll r){
        return (l+r) % MOD;
    }
    
    void setHelper(int i, int v, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = val[x] + v;
            val[x] %= MOD;
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
 
    void set(int i, ll v){
        setHelper(i, v, 0, 0, size);
    }
 
    ll queryHelper(int l, int x, int lx, int rx){
        if (rx <= l) return 0;
        if (lx >= l) return val[x];
 
        int m = (lx+rx)/2;
        return merge(queryHelper(l, (x*2)+1, lx, m), queryHelper(l, (x*2)+2,m, rx));
    }
 
    ll query(int l){
        return queryHelper(l,0, 0, size);
    }
};


void solve(){
    int n;
    cin >> n;
    vll a(n);
    for(auto& i : a) cin >> i;

    vll sorted = a;
    sorted.pb(1e9+2);

    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    SegTree st;
    st.init(sz(sorted));

    ll total = 0;
    for(int i{n-1}; i >= 0; i--){
        int index = upper_bound(all(sorted), a[i]) - sorted.begin();
        ll cur = st.query(index);
        cur += 1;
        cur %= MOD;
        total = (total + cur) % MOD;
        st.set(index-1, cur);
    }
    cout << total ;
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