```
N <= 1000, M <= 10, K <= 1000

probability to win if we get to spin at most k times

each move we got m possible result


DP state

dp[i][j] = number of ways we can get here to j at i-th move

DP transition

dp[i+1][at] += dp[i][j], 0 <= j <= n, 0 <= i <= k, at = new location which will depends on every 1 .... M move

Probability of winning 

sum of all dp[i][n] * (1 / m^i) 

i.e Number of ways we can reach square N with i moves * probability to roll i sequence.

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
 
ll dp[1005][1005];
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? (n * sq) % MOD : sq);
}
 
void solve(){
    int n, m, K;
    cin >> n >> m >> K;
    
    dp[0][0] = 1;
    
    for(int i{}; i < K; i++){
        for(int j{}; j < n; j++){
            for(int k{1}; k <= m; k++){
                if (j + k > n){
                    int at = n-(k-(n-j));
                    dp[i+1][at] = (dp[i+1][at] + dp[i][j]) % MOD;
                }else{
                    int at = j + k;
                    dp[i+1][at] = (dp[i+1][at] + dp[i][j]) % MOD;
                }
            }
        }
    }
 
    ll res = 0;
    for(int i{}; i <= K; i++){
        res = (res + ((dp[i][n] * modpow(modpow(m,i), MOD-2)) % MOD)) % MOD;
    }
 
    cout << res;
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