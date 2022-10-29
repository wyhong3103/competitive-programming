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
    vll inver;
    
    ll NEUTRAL_ELEMENT = 0;

    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        // make sure the size allocated is size * 2 
        val.assign(2*size, 0LL);
        inver.assign(2*size, 0LL);
    }
 
    ll merge(ll a, ll b){
        return a + b;
    }

    void setHelper(int i, ll v, int t, int x, int lx, int rx){
        if (rx-lx == 1){
            if (t == 1) val[x] += v;
            else inver[x] += v;
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            setHelper(i, v, t, (x*2)+1, lx, m);
        }else{
            setHelper(i, v, t, (x*2)+2, m, rx);
        }
        if (t == 1) val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
        else inver[x] = merge(inver[(x*2)+1], inver[(x*2)+2]);
    }
 
    void set(int i, int v, int t){
        setHelper(i, v, t, 0, 0, size);
    }


    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    ll queryHelper(int l, int r, int t, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            if (t == 1) return val[x];
            else return inver[x];
        }
        int m = (lx + rx) / 2;
        return merge(queryHelper(l, r, t, (x*2)+1, lx, m), queryHelper(l, r, t, (x*2)+2, m, rx));
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
        ll inver = st.query(x+1, n+1, 1);
        total += inver;
        st.set(x, inver, 2);
        st.set(x, 1, 1);
    }

    for(int i{}; i < n; i++){
        cout << total-st.query(i, n+1, 2) << '\n';
    }
}
 
int main(){
    setio("haircut");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
 

```