```

Maximal subarray sum for storing the max contiguous block

As for setting and emptying,

We let the node represent the entire segment, if we want to clean it we mark it as clean, and change everything to max (prefix, suffix, max). if we want to fill it, we mark it as fill, and 0 for everything else.

If we ever need to go down to its children, we propagate the change first. So basically before accesing its children, its children gon contain old value.

How to find the first block that is >= p?

If the current segment has max >= p, we first check if the left child has it (check its max), and then check whether its between left child and right child, and then right child.

And then when we done setting, we recompute the prefix/suffix/max for all the ancestors.

BUT WAed for some reasons, i will come back it someday


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
    int em, fi, pf, sf, mx;
};

struct SegTree{
    int size = 1;
    vector<Data> val; 

    void init(int n){
        while (size < n) size *= 2;
        val.resize(size*2, {});
    }

    void build(int n, int x, int lx, int rx){
        if (rx-lx == 1) {
            if (rx <= n) val[x] = {0, 0, 1, 1, 1};
            else val[x] = {0, 0, 0, 0, 0};
            return; 
        }

        int m = (rx+lx)/2;

        build(n, x*2+1, lx, m);
        build(n, x*2+2, m, rx);

        //compute new pf, sf, mx
        int l = (rx-lx)/2;
        val[x].pf = val[x*2+1].pf + (val[x*2+1].pf == l) * val[x*2+2].pf;
        val[x].sf = val[x*2+2].sf + (val[x*2+2].sf == l) * val[x*2+1].sf;
        val[x].mx = max({val[x].pf, val[x].sf, val[x*2+1].sf + val[x*2+2].pf, val[x*2+1].mx, val[x*2+2].mx});
    }

    void build(int n){
        build( n, 0, 0, size);
    }

    //fill p
    //force = 0, nothing, force = 1 = force to take prefix, force = 2, force to take suffix
    bool fill(int p, int x, int lx, int rx, int force){
        if (val[x].mx < p) return false;

        if (val[x].mx == p && val[x].mx == rx-lx){
            val[x] = {0, 1, 0, 0, 0};
            return true;
        }

        // propagate the changes
        int l = (rx-lx)/2;

        if (val[x].em){
            val[x*2+1] = {1, 0, l, l, l };
            val[x*2+2] = {1, 0, l, l, l };
        }
        val[x].em = 0;

        //filling0, 0, 2, 2, 2 }, { 0, 0, 2, 2, 2
        int m = (rx+lx)/2;

        if (force == 1){
            //force pf
            if (val[x*2+1].pf >= p){
                fill(p, x*2+1, lx, m, 1);
            }else{
                fill(val[x*2+1].pf, x*2+1, lx, m, 1);
                fill(p-val[x*2+1].pf, x*2+2, m, rx, 1);
            }
        }else if (force == 2){
            //force sf
            if (val[x*2+2].sf >= p){
                fill(p, x*2+2, m, rx, 2);
            }else{
                fill(val[x*2+2].sf, x*2+2, m, rx, 2);
                fill(p-val[x*2+2].sf, x*2+1, lx, m, 2);
            }
        }
        else if (val[x*2+1].mx >= p){
            fill(p, x*2+1, lx, m, 0);
        }else if (val[x*2+1].sf != 0 && val[x*2+1].sf + val[x*2+2].pf >= p){
            //if the segment is on both side
            int left = val[x*2+1].sf;
            int right = p-left;
            fill(left, x*2+1, lx, m, 2);
            fill(right, x*2+2, m, rx, 1);
        }else{
            //only completely on the right segment
            fill(p, x*2+2, m, rx, 0);
        }

        //compute new pf, sf, mx
        val[x].pf = val[x*2+1].pf + (val[x*2+1].pf == l) * val[x*2+2].pf;
        val[x].sf = val[x*2+2].sf + (val[x*2+2].sf == l) * val[x*2+1].sf;
        val[x].mx = max({val[x].pf, val[x].sf, val[x*2+1].sf + val[x*2+2].pf, val[x*2+1].mx, val[x*2+2].mx});

        return true;
    }
    
    bool fill(int p){
        return fill(p, 0, 0, size, 0);
    }

    //empty [l, r)
    void empty(int l, int r, int x, int lx, int rx){
        if (rx <= r && lx >= l){
            val[x] = {1, 0, rx-lx,rx-lx,rx-lx};
            return;
        }else if (min(r,rx) - max(l,lx) <= 0) return;

        int len = (rx-lx)/2;
        //propage the changes
        if (val[x].fi){
            val[x*2+1] = {0, 1, 0, 0, 0};
            val[x*2+2] = {0, 1, 0, 0, 0};
        }
        if (val[x].em){
            val[x*2+1] = {1, 0, len, len, len };
            val[x*2+2] = {1, 0, len, len, len };
        }
        val[x].fi = 0;
        val[x].em = 0;

        //emptying
        int m = (rx+lx)/2;

        empty(l, r, x*2+1, lx, m);
        empty(l, r, x*2+2, m, rx);

        //compute new pf, sf, mx
        val[x].pf = val[x*2+1].pf + (val[x*2+1].pf == len) * val[x*2+2].pf;
        val[x].sf = val[x*2+2].sf + (val[x*2+2].sf == len) * val[x*2+1].sf;
        val[x].mx = max({val[x].pf, val[x].sf, val[x*2+1].sf + val[x*2+2].pf, val[x*2+1].mx, val[x*2+2].mx});
    }

    void empty(int l, int r){
        empty(l, r, 0, 0, size);
    }

    void printTree(){
        int cnt = -1;
        for(int i{}; i < size*2 - 1; i++){
            if (__lg(i+1) != cnt){
                cout << '\n';
                cnt = __lg(i+1);
            }
            cout << "{ " << val[i].em << ", " << val[i].fi << ", " << val[i].pf <<  ", " << val[i].sf << ", " << val[i].mx << " }" << ", ";
        }
    }

};

void solve(){
    int n, m;
    cin >> n >> m;

    SegTree st;
    st.init(n);
    st.build(n);

    int cnt = 0;
    while(m--){
        char c;
        cin >> c;
        if (c == 'L'){
            int l, r;
            cin >> l >> r;
            l--;
            st.empty(l, r);
        }else{
            int p;
            cin >> p;
            cnt += !st.fill(p);
        }
        st.printTree();
        cout<<'\n';
    }
    cout << cnt;
}

int main(){
    //setio("seating");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```