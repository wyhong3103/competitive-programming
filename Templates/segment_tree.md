```

Can be used on any associative operation on segment (GCD / Multiply/ Max / Min/ Bitwise Operation). Nodes in the segment tree can be customized to storing anything!

To initialize - SegTree st; st.init(n);
To build - st.build(a)
To set - st.set(index, value)
To get sum [l, r)- st.sum(from, to) 

```
```cpp

// Segment tree for min
struct SegTree{
    ll size;
    vll val;
 
    void init(int n){
        size = 1;
        while (size < n){
            size *= 2;
        } 
        val.assign(2*size, 0LL);
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
        val[x] = min(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void build(vi& a){
        buildHelper(a, 0, 0, size);
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
        val[x] = min(val[(x*2)+1] ,val[(x*2)+2]);
    }
 
    void set(int i, int v){
        setHelper(i, v, 0, 0, size);
    }
 
    ll valHelper(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return LONG_LONG_MAX;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return min(valHelper(l, r, (x*2)+1, lx, m), valHelper(l, r, (x*2)+2, m, rx));
    }
 
    ll getVal(int l, int r){
        return valHelper(l, r, 0, 0, size);
    }
};

```