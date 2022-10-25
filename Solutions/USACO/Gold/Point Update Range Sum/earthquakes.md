```

It's okay to go in and delete every element in l and r! and look how many element in that segment is <= p, because we delete very element right afterward! So time complexity will almost be the same.


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


// Segment tree for min
struct SegTree{
    ll size;
    vll val;
    
    ll NEUTRAL_ELEMENT = LONG_LONG_MAX;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, LONG_LONG_MAX);
    }
 
    ll merge(ll a, ll b){
        return min(a, b);
    }
 
    void setHelper(int i, ll v, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = v;
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


    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    ll queryHelper(int l, int r, ll p, int x, int lx, int rx){
        if (val[x] > p) return 0;
        if (min(r, rx) - max(l, lx) <= 0){
            return 0;
        }
        if (rx-lx == 1){
            val[x] = NEUTRAL_ELEMENT;
            return 1;
        }

        int m = (lx + rx) / 2;
        ll total =queryHelper(l, r, p, (x*2)+1, lx, m) + queryHelper(l, r, p, (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
        return total;
    }
 
    ll query(int l, int r, ll p){
        return queryHelper(l, r,p, 0, 0, size);
    }
   

};

void solve(){
    int n, m;
    cin >> n >> m;

    SegTree st;
    st.init(n);

    while(m--){
        int t;
        cin >> t;
        if (t == 1){
            int i, h;
            cin >> i >> h;
            st.set(i, h);
        }else{
            int l, r, p;
            cin >> l >> r >> p;
            cout << st.query(l, r, p) << '\n';
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