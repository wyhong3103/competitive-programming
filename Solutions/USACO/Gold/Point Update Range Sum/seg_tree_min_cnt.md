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
 
struct SegTree{
    ll size;
    vector<pll> val;
 
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        val.assign(2*size, {0, 0});
    }
 
    void buildHelper(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x] = {a[lx], 1};
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper(a, (x*2)+1, lx, m);
        buildHelper(a, (x*2)+2, m, rx);
        if (val[(x*2)+1].fir == val[(x*2)+2].fir){
            val[x] = {val[(x*2)+1].fir, val[(x*2)+1].sec + val[(x*2)+2].sec};
        }else if (val[(x*2)+1].fir > val[(x*2)+2].fir){
            val[x] = val[(x*2)+2];
        }else{
            val[x] = val[(x*2)+1];
        }
    }
 
    void build(vi& a){
        buildHelper(a, 0, 0, size);
    }
 
    void setHelper(int i, ll v, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = {v, 1};
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            setHelper(i, v, (x*2)+1, lx, m);
        }else{
            setHelper(i, v, (x*2)+2, m, rx);
        }
        if (val[(x*2)+1].fir == val[(x*2)+2].fir){
            val[x] = {val[(x*2)+1].fir, val[(x*2)+1].sec + val[(x*2)+2].sec};
        }else if (val[(x*2)+1].fir > val[(x*2)+2].fir){
            val[x] = val[(x*2)+2];
        }else{
            val[x] = val[(x*2)+1];
        }
    }
 
    void set(int i, int v){
        setHelper(i, v, 0, 0, size);
    }
 
    pll valHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return {LONG_LONG_MAX, 1LL};
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        pll left = valHelper(l, r, (x*2)+1, lx, m); 
        pll right= valHelper(l, r, (x*2)+2, m, rx);
        if (right.fir == left.fir){
            return {right.fir, right.sec + left.sec};
        }else if (right.fir > left.fir){
            return left;
        }
        else{
            return right;
        }
    }
 
    pll getVal(int l, int r){
        return valHelper(l, r, 0, 0, size);
    }
};
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    SegTree st;
    st.init(n);
    st.build(a);
    
    while (m--){
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1){
            st.set(u, v);
        }else{
            cout << st.getVal(u, v).fir << ' ' << st.getVal(u,v).sec << '\n';
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