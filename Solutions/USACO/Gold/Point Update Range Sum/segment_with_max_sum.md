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
    vector<ll> seg;
    vector<ll> pref;
    vector<ll> suf;
    vector<ll> sum;

 
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        seg.assign(2*size, 0LL);
        pref.assign(2*size, 0LL);
        suf.assign(2*size, 0LL);
        sum.assign(2*size, 0LL);
    }
 
    void buildHelper(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                seg[x] = a[lx];
                pref[x] = a[lx];
                suf[x] = a[lx];
                sum[x] = a[lx];
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper(a, (x*2)+1, lx, m);
        buildHelper(a, (x*2)+2, m, rx);
        seg[x] = max({seg[(x*2)+1], seg[(x*2)+2], suf[(x*2)+1]+pref[(x*2)+2]});
        pref[x] = max(pref[(x*2)+1], sum[(x*2)+1]+pref[(x*2)+2]);
        suf[x] = max(suf[(x*2)+2], sum[(x*2)+2]+suf[(x*2)+1]);
        sum[x] = sum[(x*2)+1] + sum[(x*2)+2];
    }
 
    void build(vi& a){
        buildHelper(a, 0, 0, size);
    }
 
    void setHelper(int i, ll v, int x, int lx, int rx){
        if (rx-lx == 1){
            seg[x] = v;
            pref[x] = v;
            suf[x] = v;
            sum[x] = v;
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            setHelper(i, v, (x*2)+1, lx, m);
        }else{
            setHelper(i, v, (x*2)+2, m, rx);
        }
        seg[x] = max({seg[(x*2)+1], seg[(x*2)+2], suf[(x*2)+1]+pref[(x*2)+2]});
        pref[x] = max(pref[(x*2)+1], sum[(x*2)+1]+pref[(x*2)+2]);
        suf[x] = max(suf[(x*2)+2], sum[(x*2)+2]+suf[(x*2)+1]);
        sum[x] = sum[(x*2)+1] + sum[(x*2)+2];
    }
 
    void set(int i, int v){
        setHelper(i, v, 0, 0, size);
    }
 
    vll valHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return {0,0,0,0};
        }
        else if (lx >= l && rx <= r){
            return {seg[x], pref[x], suf[x], sum[x]};
        }
        int m = (lx + rx) / 2;
        vll left = valHelper(l, r, (x*2)+1, lx, m); 
        vll right= valHelper(l, r, (x*2)+2, m, rx);
        
        vll ret(4);
        ret[0] = max({left[0], right[0], left[2]+right[1]});
        ret[1] = max(left[1], left[3] + right[1]);
        ret[2] = max(right[2], right[3] + left[2]);
        ret[3] = left[3] + right[3];
        return ret;
    }
 
    ll getVal(int l, int r){
        vll ret = valHelper(l, r, 0, 0, size);
        ll mx = 0;
        for(auto& i : ret) mx = max(i, mx);
        return mx;
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
    
    cout << st.getVal(0,n) << '\n';
    while (m--){
        int i, v;
        cin >> i >> v;
        st.set(i, v);
        cout << st.getVal(0, n) << '\n';
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