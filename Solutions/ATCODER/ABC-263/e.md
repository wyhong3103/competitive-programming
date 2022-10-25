
```

dp[i] = expected value of die rolls to get from i to N

(although we could do the other way round, but it's not really recommended as it is not convinient to do cummulative sum with it, you will see)

Let's first look at the case without 0 (1 to Ai for each die roll)

DP transition : 

dp[i] = (dp[i+j]+1) * (1/a[i]) , 1 <= j <= a[i]

It could be simplified as

dp[i] = (sum(dp[i+j], 1 <= j <= a[i]) / a[i]) + 1

And that's the answer, for it.

But right now it's different we have to consider 0, and total number of moves for each die is now a[i]+1

dp[i] = (sum(dp[i+j], 0 <= j <= a[i]) / a[i]+1) + 1

dp[i] transition from dp[i] is an infinite loop, we need to do something mathematical.

Let's take dp[i] out of the equation

dp[i] = (dp[i] / a[i]+1) + (sum(dp[i+j], 1 <= j <= a[i]) / a[i]+1) + 1

dp[i] - (dp[i]/a[i]+1) = " "

dp[i] * (1 - 1/a[i]+1) = " "

dp[i] * (a[i] / a[i] + 1) = " "

dp[i] =  (" " * a[i] + 1) / a[i]


And this is the correct transition, we can get the sum of a segment using prefix sum.

```
[Editorial with the same approach and LaTex](https://atcoder.jp/contests/abc263/editorial/4552)
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
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    if (p%2) return (n * sq) % MOD;
    return sq;
}

void solve(){
    int n;
    cin >> n;

    vll a(n-1);
    for(auto& i : a) cin >> i;

    vll suffix_sm(n);
    vll dp(n);
    
    for(int i{n-2}; i >= 0; i--){
        dp[i] = (((suffix_sm[i+1] - (i+a[i]+1 >= n ? 0 : suffix_sm[i+a[i]+1]) + MOD) % MOD) * modpow(a[i]+1, MOD-2)) + 1;
        dp[i] %= MOD;
        dp[i] = ((dp[i] * (a[i]+1)) % MOD) * modpow(a[i], MOD-2);
        dp[i] %= MOD;
        suffix_sm[i] = dp[i] + suffix_sm[i+1];
        suffix_sm[i] %= MOD;
    }

    cout << dp[0];
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