```
Using vector<vi> as the Node, and not use an array will get TLE! WEIRD! Spent few hours debugging it, didn't really know how array work in C++. It has been a really long time since I last dealt with array.
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

struct Node{
    //[[a,b], [c, d]]
    int a, b, c, d;
};

Node a[200005];
Node val[800005];
 
// Segment tree for matrix multiplication
struct SegTree{
    ll size;
    int n, r;
    
    Node NEUTRAL_ELEMENT = {1, 0, 0, 1};
 
    void init(int nt, int rt){
        n = nt;
        r = rt;
        size = 1;
        while (size < n){
            size *= 2;
        } 
    }
 
    Node merge(Node a, Node b){
        Node res;
        res.a = ((a.a * b.a) % r) +( (a.b * b.c) % r) ;
        res.b = ((a.a * b.b) % r) +( (a.b * b.d) % r);
        res.c = ((a.c * b.a) % r) +( (a.d * b.c) % r);
        res.d = ((a.c * b.b) % r) +( (a.d * b.d) % r);
        res.a %= r;
        res.b %= r;
        res.c %= r;
        res.d %= r;
        
        return res;
    }
 
    void buildHelper(int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < n){
                val[x] = a[lx];
            }
            return;
        }
 
        int m = (lx+rx)/2;
        buildHelper( (x*2)+1, lx, m);
        buildHelper( (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void build(){
        buildHelper( 0, 0, size);
    }
 
 
    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    Node queryHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return merge(queryHelper(l, r, (x*2)+1, lx, m), queryHelper(l, r, (x*2)+2, m, rx));
    }
 
    Node query(int l, int r){
        return queryHelper(l, r, 0, 0, size);
    }
};
 
 
void solve(){
    int r, n, m;
    cin >> r >> n >> m;

    SegTree st;
    st.init(n, r);

    for(int i{}; i < n; i++){
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
    }
    st.build();

    while(m--){
        int l, r;
        cin >> l >> r;
        l--;
        Node res = st.query(l, r);
        cout << res.a << ' ' << res.b << '\n';
        cout << res.c << ' ' << res.d << '\n';
        cout << '\n';
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