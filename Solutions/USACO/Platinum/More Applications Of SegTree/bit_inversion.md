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
    pi pf, sf;
    int mx;
};

struct SegTree{
    ll size;
    vector<Data> val;
    
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, {});
    }
 
    Data merge(Data a, Data b, int len){
        Data ret = {};
        ret.pf = a.pf;
        ret.sf = b.sf;

        if (a.pf.fir == len && a.pf.sec == b.pf.sec) {
            ret.pf.fir = a.pf.fir + b.pf.fir;
        }
        if (b.sf.fir == len && a.sf.sec == b.sf.sec) {
            ret.sf.fir = a.sf.fir + b.sf.fir;
        }

        ret.mx = max({a.mx, b.mx, ret.pf.fir, ret.sf.fir, (a.sf.sec == b.pf.sec) * (a.sf.fir + b.pf.fir) });
        return ret;
    }

    void build(string& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                int bt = a[lx]-'0';
                val[x] = {{1, bt}, {1,bt}, 1};
            }
            return;
        }
 
        int m = (lx+rx)/2;
        build(a, (x*2)+1, lx, m);
        build(a, (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2], (rx-lx)/2);
    }
 
    void build(string& a){
        build(a, 0, 0, size);
    }
 
    void set(int i, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x].pf.sec = !val[x].pf.sec;
            val[x].sf.sec = !val[x].sf.sec;
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            set(i,(x*2)+1, lx, m);
        }else{
            set(i,(x*2)+2, m, rx);
        }
        val[x] = merge(val[(x*2)+1], val[(x*2)+2], (rx-lx)/2);
    }
 
    void set(int i){
        set(i, 0, 0, size);
    }


    ll query(){
        return val[0].mx;
    }
};


void solve(){
    string s;
    cin >> s;

    SegTree st;
    st.init(sz(s));
    st.build(s);

    int q;
    cin >> q;
    while(q--){
        int i;
        cin >> i;
        i--;
        st.set(i);
        cout << st.query() << ' ';
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