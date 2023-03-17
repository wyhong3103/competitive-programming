```

This segment tree allows Range Update Range Query, only if the set operation is associative and the set & query operation is distributive.

```
```cpp

// Segment Tree that handles 2 type of query
// set(v, l, r) = Multiply the element from the index l to r-1 by v
// query(l, r) = Get the sum of the element from the index l to r-1

const int MOD = 1e9 + 7;

struct SegTree{
    int size = 1;
    vll val1, val2;

    ll NO_OP = 1;

    void init(int n){
        while (size < n) size *= 2;
        val1.resize(size * 2, 1);
        val2.resize(size * 2, 0);
    }

    // Operation Merging Function
    // Make sure we handle NO_OP if necessary
    ll op(ll a, ll b){
        return (a * b) % MOD;
    }

    // Value Merging Function
    // Make sure we handle NO_OP if necessary
    ll merge(ll a, ll b){
        return (a + b) % MOD;
    }

    // Things to do in lazy propagation
    // 1. Push the operation on current node to its children, merge the operation properly
    // 2. Set the new value for children
    // 3. Set current node to NO_OP, and then set the new value of current node
    void propagate(int x, int lx, int rx){
        if (rx-lx == 1) return;

        val1[x*2+1] = op(val1[x], val1[x*2+1]);
        val2[x*2+1] = op(val1[x], val2[x*2+1]);

        val1[x*2+2] = op(val1[x], val1[x*2+2]);
        val2[x*2+2] = op(val1[x], val2[x*2+2]);

        val1[x] = NO_OP;
        val2[x] = merge(val2[x*2+1], val2[x*2+2]);
    }

    void buildHelper(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)) val2[x] = a[lx];
            return;
        }

        int m = (lx+rx)/2;
        buildHelper(a, x*2+1, lx, m);
        buildHelper(a, x*2+2, m, rx);
        val2[x] = merge(val2[x*2+1], val2[x*2+2]);
    }

    void build(vi& a){
        buildHelper(a, 0, 0, size);
    }

    // Make sure we also apply operation after getting the merged value
    void setHelper(ll v, int l, int r, int x, int lx, int rx){
        propagate(x, lx, rx);
        if (r >= rx && l <= lx){        
            val1[x] = op(v, val1[x]);
            val2[x] = op(val2[x], v);
            return;
        }

        if (min(r, rx) - max(l, lx) <= 0) return;

        int m = (lx+rx)/2;
        setHelper(v, l, r, x*2+1, lx, m);
        setHelper(v, l, r, x*2+2, m, rx);
        val2[x] = op(merge(val2[x*2+1], val2[x*2+2]), val1[x]);
    }

    void set(ll v, int l, int r){
        setHelper(v, l, r, 0, 0, size);
    }
    
    // Make sure we returned the correct value when there is no intersection between segments
    ll queryHelper(int l, int r, int x, int lx, int rx){
        if (r >= rx && l <= lx){
            return val2[x];
        }

        if (min(r, rx) - max(l, lx) <= 0) return 0;

        int m = (lx+rx)/2;

        return op(merge(queryHelper(l, r,x*2+1,  lx, m), queryHelper(l, r, x*2+2, m, rx)), val1[x]);
    }

    ll query(int l, int r){
        return queryHelper(l, r, 0, 0, size);
    }

};

```