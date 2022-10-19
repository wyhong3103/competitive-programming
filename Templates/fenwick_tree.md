```cpp
//1-indexed
const int MAX = 1e5 +5;
int a[MAX];
int fenwick_tree[MAX];

//Sum of [1,k]
int sum(int k){
    int s = 0;
    while (k >= 1){
        s += fenwick_tree[k];
        k -= k&-k;
    }
    return s;
}

//Update
void upd(int k, int x){
    while (k <= n){
        fenwick_tree[k] += x;
        k += k&-k;
    }
}

void construct(){
    for(int i{1}; i <= n; i++){
        int k = i + (i&-i);
        if (k < n){
            fenwick_tree += a[i];
        }
    }
}
```