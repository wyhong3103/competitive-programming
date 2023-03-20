```
Segment Tree that allows Range Update Point Query with commutative / non-commutative & associative operation

```
```cpp

// Be careful of garbage value

struct SegTree{
    ll size = 1;
    vll val;

    ll NO_OP = LONG_LONG_MIN;
    
    void init(int n){
        while (size < n){
            size *= 2;
        }
        val.resize(size * 2, 0);
    }

    // a = new, b = old
    ll op(ll a, ll b){
        if (a == NO_OP) return b;
        return a;
    }

    // lazy propagation
    void propagate(int x, int lx, int rx){
        if (rx-lx == 1) return;
        val[x*2 + 1] = op(val[x], val[x*2+1]);
        val[x*2 + 2] = op(val[x], val[x*2+2]);
        val[x] = LONG_LONG_MIN;
    }
    
    void setHelper(ll v, int l, int r, int x, int lx, int rx){
        if (r >= rx && l <= lx){
            val[x] = op(v, val[x]);
            return;
        }
        if (min(r, rx) - max(l, lx) <= 0) return;

        propagate(x, lx, rx);

        int m = (lx + rx) / 2;
        setHelper(v, l, r, x*2 + 1, lx, m);
        setHelper(v, l, r, x*2 + 2, m, rx);
    }

    void set(ll v, int l, int r){
        setHelper(v, l, r, 0, 0, size);
    }   

    ll queryHelper(int i, int x, int lx, int rx){
        if (rx-lx == 1){
            return val[x];
        }
        
        int m = (lx+rx)/2;

        ll v;
        if (i < m){
            v = queryHelper(i, x*2+1, lx, m);
        }else{
            v = queryHelper(i, x*2+2,m, rx);
        }
        return op(val[x], v);
    }

    ll query(int i){
        return queryHelper(i, 0, 0, size);
    }

    void print(){
        int cnt = -1;
        for(int i{}; i < size*2 - 1; i++){
            if (__lg(i+1) != cnt){
                cout << '\n';
                cnt = __lg(i+1);
            }
            cout << val[i] << ' ';
        }
        cout << '\n';
    }

};

```