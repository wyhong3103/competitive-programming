```

initialize parent[i] = i, 0 <= i < n


```
```cpp

const int MX = 1e5;

struct DSU{
    int ranking[MX];
    int parent[MX];
        
    int get(int a){
        return parent[a] = (parent[a] == a ? parent[a] : get(parent[a]));
    }

    bool merge(int a, int b){
        a = get(a);
        b = get(b);
        
        if (a == b) return false;

        if (ranking[a] == ranking[b]) ranking[a]++;

        if (ranking[a] > ranking[b]){
            parent[b] = a;
        }else{
            parent[a] = b;
        }
        return true;
    }
};
```