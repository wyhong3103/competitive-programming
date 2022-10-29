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
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p / 2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq);
}
 
void solve(){
    vll f(3);
    vll s(3);
    for(auto& i : f){
        cin >> i;
        i %= MOD;
    }
    for(auto& i : s){
        cin >> i;
        i %= MOD;
    }
 
 
    ll fs = f[0];
    for(int i{1}; i < 3; i++){
        fs = (fs * f[i]) % MOD;
    }
 
    ll ss = s[0];
    for(int i{1}; i < 3; i++){
        ss = (ss * s[i]) % MOD;
    }
 
    
    ll total = (fs - ss) % MOD;
    total += MOD;
    total %= MOD;
 
    //cout << (total * modpow(MOD, MOD-2)) % MOD;
    cout << total;
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