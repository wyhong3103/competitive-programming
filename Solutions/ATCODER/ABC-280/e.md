```

A very standard DP.

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MOD = 998244353;
const int MX = 2e5 + 5;
ll dp[MX];
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? sq * n : sq) % MOD;
}
 
void solve(){
    ll n, p;
    cin >> n >> p;
 
    for(int i{1}; i <= n; i++){
        dp[i] = ((dp[i-1]+1) * (((100-p)*modpow(100, MOD-2)) % MOD)) % MOD;
        dp[i] += ((dp[max(0, i-2)]+1) * ((p*modpow(100, MOD-2)) % MOD)) % MOD;
        dp[i] %= MOD;
    }
    cout << dp[n];
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