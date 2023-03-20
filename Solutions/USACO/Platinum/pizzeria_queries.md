```

Store the min to reach left end and right end of segment.

How to search the min to reach x?

if x is located in the right half, we use min of left half to reach right end + length between m and x

same goes to the case where x is located in the left half

Until we hit a single element.

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
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

struct Data{
    ll l, r;
};

struct SegTree{
    int size = 1;
    vector<Data> val;

    void init(int n){
        while (size < n) size *= 2;
        val.resize(size * 2, {INT_MAX, INT_MAX});
    }

    Data merge(Data a, Data b, ll len){
        return {min(a.l, b.l + len), min(a.r + len, b.r)};
    }

    void build(vll& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)) val[x] = {a[lx], a[lx]};
            return;
        }

        int m = (lx+rx)/2;
        build(a, x*2+1, lx, m);
        build(a, x*2+2, m, rx);

        val[x] = merge(val[x*2+1], val[x*2+2], (rx-lx)/2);
    }

    void build(vll& a){
        build(a, 0, 0, size);
    }

    void set(ll v, int i, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = {v, v};
            return;
        }

        ll m = (lx+rx)/2;
        if (i < m){
            set(v, i, x*2+1, lx, m);
        }
        else set(v, i, x*2+2, m, rx);

        val[x] = merge(val[x*2+1], val[x*2+2], (rx-lx)/2);
    }

    void set(ll v, int i){
        set(v, i, 0, 0, size);
    }

    ll query(ll k, int x, int lx , int rx){
        if (rx-lx == 1){
            return abs(k-lx) + val[x].l;
        }

        ll m = (lx + rx) / 2;
        if (k >= m){
            return min(val[x*2+1].r + (k-m+1), query(k, x*2+2, m, rx));
        }else{
            return min(val[x*2+2].l + (m-k), query(k, x*2+1, lx, m));
        }
    }

    ll query(ll k){
        return query(k, 0, 0, size);
    }

    void print(){
        int cnt = -1;
        for(int i{}; i < size*2 - 1; i++){
            if (__lg(i+1) != cnt){
                cout << '\n';
                cnt = __lg(i+1);
            }
            cout << "{ "<< val[i].l << ", " <<  val[i].r << "}, ";
        }
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

    //st.print();

    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int k, x;
            cin >> k >> x;
            k--;
            st.set(x, k);
        }else {
            int k;
            cin >> k;
            k--;
            cout << st.query(k) << '\n';
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