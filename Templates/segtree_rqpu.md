```

Segment Tree that allows Range Query Point Update

Can be used on any associative operation on segment (GCD / Multiply/ Max / Min/ Bitwise Operation). Nodes in the segment tree can be customized to storing anything!

To initialize - SegTree st; st.init(n);
To build - st.build(a)
To set - st.set(index, value)
To get val [l, r)- st.query(l, r) 

A better way to implement segment tree, is to use a merge function for merging segments rather than doing it manually under each func, and have a NEUTRAL_ELEMENT which returns something that wouldn't change the value of the segment.
```
```cpp
// Be careful of unused value / garbage value
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
        val.assign(2*size, 0LL);
    }
 
    ll merge(ll a, ll b){
        return min(a, b);
    }

    void build(vi& a, int x, int lx, int rx){
        if (rx-lx == 1){
            if (lx < sz(a)){
                val[x] = a[lx];
            }
            return;
        }
 
        int m = (lx+rx)/2;
        build(a, (x*2)+1, lx, m);
        build(a, (x*2)+2, m, rx);
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void build(vi& a){
        build(a, 0, 0, size);
    }
 
    void set(int i, ll v, int x, int lx, int rx){
        if (rx-lx == 1){
            val[x] = v;
            return;
        }
 
        int m = (lx+rx)/2;
        if (i < m){
            set(i, v, (x*2)+1, lx, m);
        }else{
            set(i, v, (x*2)+2, m, rx);
        }
        val[x] = merge(val[(x*2)+1], val[(x*2)+2]);
    }
 
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }


    // Make sure it runs in O(log N), eliminate the segment that is impossible, return the segment that is fully covered
    ll query(int l, int r, int x, int lx, int rx){
        if (min(r, rx) - max(l, lx) <= 0){
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r){
            return val[x];
        }
        int m = (lx + rx) / 2;
        return merge(query(l, r, (x*2)+1, lx, m), query(l, r, (x*2)+2, m, rx));
    }
 
    ll query(int l, int r){
        return query(l, r, 0, 0, size);
    }
    /*
    void print(){
        int cnt = -1;
        for(int i{}; i < size*2 - 1; i++){
            if (__lg(i+1) != cnt){
                cout << '\n';
                cnt = __lg(i+1);
            }
            cout << val[i] << ' ';
        }
    }

    */
};

```