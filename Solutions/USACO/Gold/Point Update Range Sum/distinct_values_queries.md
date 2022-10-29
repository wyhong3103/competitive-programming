```

Did an offline query.

The idea is 

from 0 to n-1

if x existed before i, and a[i] is x, we make x at i instead

if there exist a query that ends at i, we answer the query = the total number of marked element in that segment.

We only want an element latest existence as that applied to all the on going segment. 

Gotta be honest, took the hint that we need to do an offline query, and I kind of just guessed/came up with the above algorithm, there isn't a lot of intuition but luck.

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
    
    ll NEUTRAL_ELEMENT = 0;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, 0LL);
    }
 
    ll merge(ll a, ll b){
        return a + b;
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
    ll queryHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return merge(queryHelper(l, r, (x*2)+1, lx, m), queryHelper(l, r, (x*2)+2, m, rx));
    }
 
    ll query(int l, int r){
        return queryHelper(l, r, 0, 0, size);
    }
    void printTree(){
        int cnt = -1;
        for(int i{}; i < size*2; i++){
            if (__lg(i+1) != cnt){
                cout << '\n';
                cnt = __lg(i+1);
            }
            cout << val[i] << ' ';
        }
    }
};


void solve(){
    int n, q;
    cin >> n >> q;
    
    vi a(n);
    for(auto& i : a) cin >> i;

    vector<pi> queries(q);
    
    vector<vi> r(n);
    for(int i{}; i < q; i++){
        cin >> queries[i].fir >> queries[i].sec;
        queries[i].fir--;
        queries[i].sec--;
        r[queries[i].sec].pb(i);
    }

    vi res(q);

    SegTree st;
    st.init(n+1);

    map<int,int> lst;

    for(int i{}; i < n; i++){
        if (lst.count(a[i])){
            st.set(lst[a[i]], 0);
        }
        lst[a[i]] = i;
        st.set(i ,1);

        for(auto& j : r[i]){
            res[j] = st.query(queries[j].fir,i+1);
        }
    }

    for(auto& i : res) cout << i << '\n';

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