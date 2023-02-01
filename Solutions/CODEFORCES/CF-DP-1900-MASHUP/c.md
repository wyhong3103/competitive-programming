```

Initial Idea

To let

dp[i][j][k] = minimal cost so far after processing first i items with j items taken and k items stolen

And then do a knapsack

but this is O(N^3), at first I thought that the third state is going to be at most 2000^2, but turned out, if t >= n, then we can just ignore it as it is guaranteed that we can steal all the remaining items.


Reduced down to O(N^2)

DP state

dp[i][j] = minimal cost after processing i item s.t j items have been taken (bought + stole)

If j >= n, that just mean the current is valid.

DP Transition

if dp[i-1][j] is a valid state (i.e not -1),

dp[i][min(n, j+a[i].t+1)] = min(dp[i][min(n, j+a[i].t+1)], dp[i-1][j]+a[i].c)

For the 2nd dimension, we do j+a[i].t+1, because we bought one item and stole a[i].t items.

DP base case

dp[i][j] = -1 for all i and j, except for i = 0 && j = 0, dp[0][0] = 0

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


const int MXN = 2005;
ll dp[MXN][MXN];

void solve(){
    ll n;
    cin >> n;

    vector<pll> item;

    for(int i{}; i < n; i++){
        ll t, c;
        cin >> t >> c;
        item.pb({c, t});
    }

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;

    for(int i{1}; i <= n; i++){
        for(int j{}; j <= n; j++){
            if (dp[i-1][j] != -1){
                dp[i][j] = (dp[i][j] == -1 ? dp[i-1][j] : min(dp[i-1][j], dp[i][j]));
                ll& state = dp[i][min(n, j+item[i-1].sec+1)];
                state = (state == -1 ? dp[i-1][j]+item[i-1].fir : min(state, dp[i-1][j]+item[i-1].fir));
            }
        }
    }

    cout << dp[n][n];
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