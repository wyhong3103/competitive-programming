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
    vll val;
 
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        val.assign(size*2, 0LL);
    }

    ll merge(ll l, ll r){
        return l+r;
    }
 
    void buildHelper(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x] = 1;
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
 
    void setHelper(int i, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = !val[x];
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            setHelper(i, (x*2)+1, lx, m);
        }else{
            setHelper(i, (x*2)+2, m, rx);
        }
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void set(int i){
        setHelper(i,  0, 0, size);
    }
 
    ll valHelper(int cur, int x, int lx, int rx){
        if (rx-lx == 1){
            return lx;
        }

        int m = (lx+rx)/2;
        if (val[(x*2)+2] > cur){
            return valHelper(cur, (x*2)+2, m, rx);
        }else{
            return valHelper(cur-val[(x*2)+2], (x*2)+1, lx, m);
        }
    }
 
    ll getVal(int k){
        return valHelper(k, 0, 0, size);
    }
};
 
void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    SegTree st;
    st.init(n);
    st.build(a);

    vi res(n);
    for(int i{n-1}; i >= 0; i--){
        res[i] = st.getVal(a[i])+1;
        st.set(res[i]-1);
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