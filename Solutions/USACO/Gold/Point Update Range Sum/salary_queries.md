Coordinate compression + range sum query with seg tree.

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

 
    void setHelper(int i, int v, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] += v;
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
 
    void set(int i, int v){
        setHelper(i, v, 0, 0, size);
    }
 
    ll queryHelper(int l, int r, int x, int lx, int rx){
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return val[x];
 
        int m = (lx+rx)/2;
        return merge(queryHelper(l, r, (x*2)+1, lx, m), queryHelper(l, r, (x*2)+2,m, rx));
    }
 
    ll query(int l, int r){
        return queryHelper(l, r, 0, 0, size);
    }
};


void solve(){
    int n, m;
    cin >> n >> m;


    vi a(n);
    for(auto& i : a) cin >> i;

    vi sorted = a;
    sorted.pb(1e9+1);

    vector<pair<int,pi>> queries;

    for(int i{}; i < m; i++){
        char c;
        cin >> c;
        int u, v;
        cin >> u >> v;
        int t = (c == '?' ? 2 : 1);
        if (t == 1){
            sorted.pb(v);
        }
        queries.pb({t, {u,v}});
    }

    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());
    
    SegTree st;
    st.init(sz(sorted));

    for(auto& i : a){
        int index = lower_bound(all(sorted), i) - sorted.begin();
        st.set(index, 1);
    }
    
    for(auto& i : queries){
        if (i.fir == 1){
            int index = lower_bound(all(sorted), a[i.sec.fir-1]) - sorted.begin();
            st.set(index, -1);
            index = lower_bound(all(sorted), i.sec.sec) - sorted.begin();
            st.set(index, 1);
            a[i.sec.fir-1] = i.sec.sec;
        }else{
            int l = lower_bound(all(sorted), i.sec.fir) - sorted.begin();
            int r = lower_bound(all(sorted), i.sec.sec+1) - sorted.begin();
            cout << st.query(l, r) << '\n';
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