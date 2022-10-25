```

The idea is to

Have 2 ararys, one for normal inversion count for pairs, another one for triplets, which store the number of inversion pairs of number i.

Everytime we add a number, the inversion triplet is simply the number of inversion pairs that has greater number than it that exist before the number itself.

And then we add the new inversion pairs to that number on the inversion triplets array.

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
    vll inv1;
    vll inv2;
 
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        inv1.assign(size*2, 0LL);
        inv2.assign(size*2, 0LL);
    }
 
    ll merge(ll l, ll r){
        return l+r;
    }
 
    void setHelper(int i, int v,int t, int x, int lx, int rx){
        if (rx-lx == 1){
            if (t == 0) inv1[x]+=v;
            else inv2[x]+=v;
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            setHelper(i, v, t, (x*2)+1, lx, m);
        }else{
            setHelper(i, v, t, (x*2)+2, m, rx);
        }
        inv1[x] = merge(inv1[(x*2)+1], inv1[(x*2)+2]);
        inv2[x] = merge(inv2[(x*2)+1], inv2[(x*2)+2]);
    }
 
    void set(int i, int v,int t){
        setHelper(i, v, t, 0, 0, size);
    }
 
    ll queryHelper(int l, int r, int t, int x, int lx, int rx){
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return (t == 0 ? inv1[x] : inv2[x]);
 
        int m = (lx+rx)/2;
        return merge(queryHelper(l, r, t,(x*2)+1, lx, m), queryHelper(l, r, t, (x*2)+2,m, rx));
    }
 
    ll query(int l, int r, int t){
        return queryHelper(l, r, t, 0, 0, size);
    }
};
 
void solve(){
    int n;
    cin >> n;
 
    SegTree st;
    st.init(n+2);

    ll total = 0;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        total += st.query(x+1, n+1, 1);
        int inv = st.query(x+1, n+1, 0);
        st.set(x, inv, 1);
        st.set(x, 1, 0);
    }

    cout << total;
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