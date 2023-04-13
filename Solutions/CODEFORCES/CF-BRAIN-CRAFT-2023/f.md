```

gcd(2^x, 2^y) is simply min(2^x, 2^y)

tricky part of this question is

a^k mod m = a^(k mod (m-1)) mod m

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
 
const int MOD = 1e9 + 7;
const int MX = 1e5 + 5;
ll fact[MX];
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq= modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n*sq: sq) % MOD;
}
 
void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i) % (MOD-1);
    }
}
 
void solve(){
    ll a, b, n;
    cin >> a >> b >> n;
 
    if (a > b) swap(a, b);
 
    cout << modpow(n, fact[a]) << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >>t;
    gen_fact();
    while(t--){
        solve();
    }
    return 0;
}
```