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
                val[x] = a[lx];
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
            val[x] = 1;
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
 
    ll valHelper(int l, int x, int lx, int rx){
        if (rx <= l){
            return 0;
        }else if (lx >= l){
            return val[x];
        }
        if (rx-lx == 1){
            return val[x];
        }

        int m = (lx+rx)/2;
        return merge(valHelper(l, (x*2)+1, lx, m), valHelper(l, (x*2)+2, m, rx));
    }
 
    ll getVal(int l){
        return valHelper(l, 0, 0, size);
    }
};
 
void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    SegTree st;
    st.init(n);

    for(int i{}; i < n; i++){
        cout <<  st.getVal(a[i]-1) << ' ';
        st.set(a[i]-1);
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