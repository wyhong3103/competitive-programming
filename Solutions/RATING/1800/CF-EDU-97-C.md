```

DP state

dp[i][j] = minimal cost for first i values such that all first i values are taken before or equal to j seconds

DP transition

dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(j-a[i-1]))
dp[i][j] = min(dp[i][j], dp[i][j-1])

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
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
    sort(all(a));

    vector<vi> dp(n+1, vi((n * n) + 1, INT_MAX));

    fill(all(dp[0]), 0);

    for(int i{1}; i <= n; i++){
        for(int j{i}; j <= n*n; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(j-a[i-1]));
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }


    int mn = INT_MAX;
    for(int i{}; i <= n*n; i++){
        mn = min(dp[n][i], mn) ;
    }
    cout << mn << '\n';
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