```

Weight is too large to be cached as a state, so we would use the value as a state instead.

dp[i][j] = minimal weight used by a subset of first i items and with j value

transition

dp[i][j] = min(dp[i-1][j], dp[i][j])

if (dp[i-1][j] != INF && dp[i-1][j] + a[i].w <= W):
	dp[i][j+a[i].w] = min(dp[i-1][j+a[i].v], dp[i-1][j] + a[i].w)

Only transition from the previous item, as the current item (current row in dp states) might already have values that are transitioned using the current item which would cause the use of current item more than once.

We basically want to minimize the weight used in each state, that way we could maximize our value with minimal state.
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


void solve(){
    ll n, w;
    cin >> n >> w;

    vector<pll> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;

    ll max_val = 1e5+5;

    vector<vll> dp(n+1, vll (max_val+1, LONG_LONG_MAX));
    dp[0][0] = 0;

    for(int i{1}; i <= n; i++){
        for(int j{}; j <= max_val; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (dp[i-1][j] != LONG_LONG_MAX && dp[i-1][j] + a[i-1].fir <= w){
                dp[i][j+a[i-1].sec] = min({ dp[i-1][j]+a[i-1].fir, dp[i-1][j+a[i-1].sec], dp[i][j+a[i-1].sec] });
            }
        }
    }

    int mx = 0;
    for(int i{}; i <= max_val; i++){
        if (dp[n][i] != LONG_LONG_MAX) mx = max(mx, i);
    }
    cout << mx;

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