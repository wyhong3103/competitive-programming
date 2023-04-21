```

DP State

dp[i][j] = total settings for the dead heroes that can lead to i heroes alive with j damage dealt

DP Transition

For each transition, we let 

damage = min(x, j+i-1), as each round we deal i-1 damages for each hero, j is the previously accumulated damage, and it doesn't exceed x

dp[k][damage] = dp[i][j] * C[i][i-k] * (damage-j)^(i-k)

The idea is, we select i-k of the i heroes as the dead hero, and their health range is from j+1 to damage, because they could only die from those

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

const int MOD = 998244353;
const int MX = 505;
ll dp[MX][MX];
ll C[MX][MX];

void gen(){
    for(int i{}; i < MX; i++){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j{1}; j < i; j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
        }
    }
}

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p%2 ? n * sq : sq) %MOD;
}

void solve(){
    int n, x;
    cin >> n >> x;
    gen();

    dp[n][0] = 1;

    for(int i{n}; i >= 2; i--){
        for(int j{}; j <= x; j++){
            ll dam = min(x, j + i - 1);
            //k alive
            for(int k{}; k <= i; k++){
                dp[k][dam] += (((dp[i][j] * C[i][i-k]) % MOD) * modpow(dam-j, i-k)) % MOD;
                dp[k][dam] %= MOD;
            }
        }
    }
    
    ll total = 0;
    for(int i{}; i <= x; i++) total = (total + dp[0][i]) % MOD;
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