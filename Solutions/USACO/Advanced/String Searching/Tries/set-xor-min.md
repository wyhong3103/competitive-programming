```

Memory Limit is strict, we have to use a vector

The idea is simple, we construct the trie, starting from MSB, and then when we wanna do XOR operation, we walk on the trie, takes whats best for us

```
```cpp

struct Trie{
    vector<Trie> c;
    vi cnt;

    void insert(ll s, int pos){
        while (sz(c) < 2){
            c.pb({});
            cnt.pb(0);
        }
        if (pos >= 0){
            int b = (bool)(s & (1LL << pos));
            c[b].insert(s, pos-1);
            cnt[b]++;
        }
    }

    void erase(ll s, int pos){
        if (pos >= 0){
            int b = (bool)(s & (1LL << pos));
            cnt[b]--;
            c[b].erase(s, pos-1);
        }
    }

    void dfs(ll s, int pos, ll& res){
        if (s & (1LL << pos)){
            res += (!cnt[1]) * (1LL << pos);
            if (pos) c[!!cnt[1]].dfs(s, pos-1, res);
        }else{
            res += (!cnt[0]) * (1LL << pos);
            if (pos) c[!cnt[0]].dfs(s, pos-1, res);
        }
    }
};

void solve(){
    int q;
    cin >> q;

    Trie tr;
    set<ll> exist;

    while(q--){
        ll t, x;
        cin >> t >> x;
        if (!t){
            if (!exist.count(x)) tr.insert(x, 31);
            exist.insert(x);
        }else if (t == 1){
            if (exist.count(x)) tr.erase(x, 31);
            exist.erase(x);
        }else{
            ll res = 0;
            tr.dfs(x, 31, res);
            cout << res << '\n';
        }
    }
    /*
    while(q--){
        int t = rand() % 3;
        ll x = (rand() * q * 310313LL) % (int)(1e9 + 7);
        if (!t){
            if (!exist.count(x)) tr.insert(x, 31);
            exist.insert(x);
        }else if (t == 1){
            if (exist.count(x)) tr.erase(x, 31);
            exist.erase(x);
        }else{
            ll res = 0;
            tr.dfs(x, 31, res);
        }
    }*/
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```