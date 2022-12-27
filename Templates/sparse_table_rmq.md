```

More to it, read CPH.

```
```cpp


void processSparse(vi& a, vector<vi>& sparse){
    for(int i{}; i <= __lg(n); i++){
        for(int j{}; j <= n-(1 << i); j++){
            if (!i){
                sparse[i].pb(a[j]);
            }else{
                int w = i-1;
                sparse[i].pb(min(sparse[w][j], sparse[w][j+(1 << w)]));
            }
        } 
    }
}


void solve(){
    int n, q;
    cin >> n >> q;

    vi a(n);
    for(auto& i : a) cin >> i;

    vector<vi> sparse(__lg(n)+1);
    
    processSparse(a, sparse);

    while(q--){
        int l, r;
        cin >> l >> r;
        // min or [l, r]
        int w = (__lg(r-l+1));
        cout << (min(sparse[w][l], sparse[w][r-(1 << w)+1])) << '\n';
    }
}
```