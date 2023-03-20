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

const int MOD = 998244353;

struct SegTree{
    int size = 1;
    vector<pll> val;

    void init(int n){
        while (size < n) size *= 2;
        val.resize(size * 2, {});
    }

    pll merge(pll a, pll b){
        return {(b.fir * a.fir) % MOD, (a.sec * b.fir + b.sec) % MOD};
    }

    void build(vector<pll>& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)) val[x] = a[lx];
            return;
        }

        int m = (lx+rx)/2;
        build(a, x*2+1, lx, m);
        build(a, x*2+2, m, rx);

        val[x] = merge(val[x*2+1], val[x*2+2]);
    }

    void build(vector<pll>& a){
        build(a, 0, 0, size);
    }

    void set(pll& v, int i, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = v;
            return;
        }

        int m = (lx+rx)/2;
        if (i < m){
            set(v, i, x*2+1, lx, m);
        }
        else set(v, i, x*2+2, m, rx);

        val[x] = merge(val[x*2+1], val[x*2+2]);
    }

    void set(pll v, int i){
        set(v, i, 0, 0, size);
    }

    pll query(int l, int r, int x, int lx, int rx){
        if (rx <= r && lx >= l){
            return val[x];
        }
        else if (min(r, rx) - max(l, lx) <= 0) return {1, 0};
        
        int m = (lx+rx)/2;
        return merge(query(l, r, x*2+1, lx, m), query(l, r, x*2+2, m, rx));
    }

    ll query(int l, int r, ll x){
        pll f = query(l, r, 0, 0, size);
        return (f.fir * x + f.sec) % MOD;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<pll> a(n);
    for(int i{}; i < n; i++){
        cin >> a[i].fir  >> a[i].sec;
    }

    SegTree st;
    st.init(n);
    st.build(a);

    while(q--){
        int t, a, b, c;
        cin >> t >> a >> b >> c;
        if (t){
            cout << st.query(a, b, c) << '\n';
        }else{
            st.set({b, c}, a);
        }
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