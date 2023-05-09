```

obvious case

n = 1 always YES

n is even and m > 1, we can always tie it, so NO

n is odd, m >= n, we can let every a[i] to be i, so NO, it will be a tie

Generalization

let's look at n = 3, m = 3

1 1 1 2 2 2 3 3 3

We can have the above and make it a tie

So from the above, it's not hard to see that, if m >= smallest factor of n, then we can always make it tie, else it will eventually reduce to 1,

why?

notice that n is unchanged, and the smallest number that divides n is x, x > m, and each turn m is going to reduce at least by 1, and there is no way we could have m == x, so it will converge

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
int sieve[MX];
 
void gen_sieve(){
    for(int i{2}; i < MX; i++){
        if (sieve[i]) continue;
        sieve[i] = i;
        for(int j{2 * i}; j < MX; j += i){
            if (!sieve[j]) sieve[j] = i;
        }
    }
}
 
void solve(){
    //if n is even number and m > 1, always NO
    //else YES?
 
    ll n, m;
    cin >> n >> m;
 
    if ((n % 2 == 0 && m > 1) || (n > 1 && m >= sieve[n])){
        cout << "NO" << '\n';
    }else{
        cout << "YES" << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    gen_sieve();
    while(t--){
        solve();
    }
    return 0;
}

```