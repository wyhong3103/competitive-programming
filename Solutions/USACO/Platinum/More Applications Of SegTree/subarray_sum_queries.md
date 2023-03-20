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

struct Data{
    ll sum, mx, pf, sf;
};

struct SegTree{
    int size = 1;
    vector<Data> val;

    void init(int n){
        while (size < n) size *= 2;
        val.resize(size * 2, {});
    }

    Data merge(Data a, Data b){
        Data ret = {
            a.sum + b.sum,
            max({0LL, a.mx, b.mx, a.sf + b.pf}),
            max(a.sum + b.pf, a.pf),
            max(b.sum + a.sf, b.sf)
        };
        ret.mx = max({ret.pf, ret.mx, ret.sf});
        return ret;
    }

    void build(vll& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)) val[x] = {a[lx], a[lx], a[lx], a[lx]};
            return;
        }

        int m = (lx+rx)/2;
        build(a, x*2+1, lx, m);
        build(a, x*2+2, m, rx);

        val[x] = merge(val[x*2+1], val[x*2+2]);
    }

    void build(vll& a){
        build(a, 0, 0, size);
    }

    void set(ll v, int i, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = {v, v, v, v};
            return;
        }

        int m = (lx+rx)/2;
        if (i < m){
            set(v, i, x*2+1, lx, m);
        }
        else set(v, i, x*2+2, m, rx);

        val[x] = merge(val[x*2+1], val[x*2+2]);
    }

    void set(ll v, int i){
        set(v, i, 0, 0, size);
    }

    ll query(){
        return val[0].mx;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    
    vll a(n);
    for(auto& i : a) cin >> i;

    SegTree st;
    st.init(n);
    st.build(a);

    while(q--){
        int i, x;
        cin >> i  >> x;
        i--;
        st.set(x, i);
        cout << st.query() << '\n';
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