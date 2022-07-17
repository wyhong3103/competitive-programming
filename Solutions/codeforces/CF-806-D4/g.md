```
Simple DP, 

DP state = [i-th chest, j-th bad key used]

The reason we can do this is because we can only use >= 30 bad keys because 2^30 goes up to 10^9 which exceeds the limit, so every other chest box opened later will result in 0.

Transition is simply 

dp[i+1][j] = max(dp[i][j] + a[i]/(1 << j))
dp[i+1][j+1] = max(dp[i][j] + a[i]/(1 << j+1))

One tricky part is that when j == the max value, we need to consider it as the answer, because the way our dp works is it stops after the ~30th key, it wouldn't take more bad keys after that, but in reality, we could still take bad key after it even though it results in 0, but the value we had before that is big enough to be the answer.
```
```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    ll n, k;
    cin >> n >> k;
     
    vector<ll> a(n);
    for(auto& i : a) cin >> i;
 
    //i-th box, i-th bad key used
    vector<vector<ll>> dp(n+1);
    for(int i{}; i < n+1; i++){
        dp[i].resize(33);
        fill(all(dp[i]), -LONG_LONG_MAX);
    }

    ll res = 0;
    dp[0][0] = 0;
    for(ll i{}; i < n; i++){
       for(ll j{}; j < 32; j++){
            if (dp[i][j] > -LONG_LONG_MAX){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] - k + (a[i]/(((ll)1) << j)));
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (a[i]/(((ll)1) << (j+1))) );
                if (j == 31) res = max({dp[i+1][j], res, dp[i+1][j+1]});
            }
       }
    }
 
    for(int i{}; i < 33; i++){
        res = max(dp[n][i], res);
    }
 
    cout << res << '\n';
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