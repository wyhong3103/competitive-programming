```cpp
const int MX = ;
int ranking[MX];
int parent[MX];
    
int dsu_get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a]));
}

bool dsu_union(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);
    
    if (a == b) return false;

    if (ranking[a] == ranking[b]) ranking[a]++;

    if (ranking[a] > ranking[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
    return true;
}

//initialize parent[i] = i, 0 <= i < n
```