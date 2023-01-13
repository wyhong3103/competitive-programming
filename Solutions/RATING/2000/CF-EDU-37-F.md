```

Notice that for each element, there will be a time when we replace a[i] with div[a[i]] and it will stays the same.

for example, div[2] = 2, no matter how many time we proceed to do the operation, it just going to stay the same.

And the number is smaller than 10. (max 6, proved by DP with max constraint)

So for each query, we can just process the number that has been processed less than 10 times. Those that performed more than that, we just remove it.

We can use a map for the above!

Then just a fenwick tree for point upd/range sum.

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


const int MX = 1e6 + 5;
const int MX2 = 3e5 + 10;
int sieve[MX];
int divi[MX];
int a[MX2];
ll fenwick_tree[MX2];
int n, m;

struct FenwickTree{
    //Sum of [1,k]
    ll sum(ll k){
        ll s = 0;
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
};

void gen_sieve(){
    for(int i{2}; i < MX; i++){
        if (sieve[i]) continue;
        for(int j{2*i}; j < MX; j+=i){
            sieve[j] = i;
        }
    }
}

void solve(){
    gen_sieve(); 
    divi[1] = 1;
    for(int i{2}; i < MX; i++){
        map<int,int> pf;
        int x = i;
        while (sieve[x]){
            pf[sieve[x]]++;
            x /= sieve[x];
        }
        pf[x]++;

        ll divisors = 1;
        for(auto& j : pf) divisors *= j.sec+1;
        divi[i] = divisors;
    }

    cin >> n >> m;

    FenwickTree fwt;
    for(int i{1}; i <= n; i++){
        cin >> a[i];
        fwt.upd(i, a[i]);
    }


    map<int,int> mp;
    for(int i{1}; i <= n; i++) mp[i] = 0;

    for(int i{}; i < m; i++){
        int t, l, r;
        cin >> t >> l >> r;

        if (t == 1){
            auto it = mp.lower_bound(l);
            while (it != mp.end()){
                if (it->fir > r) break;
                ll at = fwt.sum(it->fir) - (it->fir == 1 ? 0 : fwt.sum(it->fir-1));
                fwt.upd(it->fir, -at);
                fwt.upd(it->fir, divi[at]);
                it->sec++;

                if (it->sec > 10){
                    int cur = it->fir;
                    it++;
                    mp.erase(cur);
                }else{
                    it++;
                }
            }
        }else{
            cout << fwt.sum(r) - (l == 1 ? 0 : fwt.sum(l-1)) << '\n';
        }
    }
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