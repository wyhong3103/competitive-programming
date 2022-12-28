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
 
const int MOD = 1e9 + 7;
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p %2  ? sq * n : sq) % MOD;
}
 
void solve(){
    ll n;
    cin >> n;
 
    ll res = (n * (n+1));
    res %= MOD;
    res *= (2*n+1);
    res %= MOD;
    res *= modpow(6, MOD-2);
    res %= MOD;
 
    ll ans = 2*res;
    ans %= MOD;
    ans -= ((n*(n+1)) % MOD) * modpow(2, MOD-2);
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
 
 
    cout << (ans*2022) % MOD << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```