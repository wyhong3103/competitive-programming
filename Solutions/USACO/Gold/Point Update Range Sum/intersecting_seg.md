```

Calculate

x y x y first, then y x y x, by reversing the array and do it over again



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
 
    ll queryHelper(int l, int r, int x, int lx, int rx){
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return val[x];
        if (rx-lx == 1){
            return val[x];
        }
 
        int m = (lx+rx)/2;
        return merge(queryHelper(l, r, (x*2)+1, lx, m), queryHelper(l, r, (x*2)+2,m, rx));
    }
 
    ll query(int l, int r){
        return queryHelper(l, r, 0, 0, size);
    }
};
 
void solve(){
    int n;
    cin >> n;
 
    vi a(2*n);
    for(auto& i : a) cin >> i;
 
    SegTree st;
    st.init(2*n);
 
    vi res(n);
    vi left(n, -1);
 
    for(int i{}; i < sz(a); i++){
        if (left[a[i]-1] == -1){
            left[a[i]-1] = i;
            st.set(left[a[i]-1]);
        }else{
            res[a[i]-1] = st.query(left[a[i]-1]+1, i);
            st.set(left[a[i]-1]);
            left[a[i]-1] = -1;
        }
    }

    reverse(all(a));
    for(int i{}; i < sz(a); i++){
        if (left[a[i]-1] == -1){
            left[a[i]-1] = i;
            st.set(left[a[i]-1]);
        }else{
            res[a[i]-1] += st.query(left[a[i]-1]+1, i);
            st.set(left[a[i]-1]);
            left[a[i]-1] = -1;
        }
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