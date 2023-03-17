```

Basically given nxm grid, for each row, you need to take the first x cell, x > 0

And, x for row 1 > x for row 2 < x for row 3 > x for row 4 .....

We can easily solve this with prefix/suffix max and prefix sum.

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

const int MX = 1505;
ll dp[MX][MX];

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vi> a(n, vi(m));
    for(int i{}; i <n;i++){
        for(int j{};j<m;j++)cin>>a[i][j];
    }
    
    vector<vll> pf(n, vll(m));

    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            pf[i][j] = a[i][j];
            if (j) pf[i][j] += pf[i][j-1];
        }
    }

    for(int i{1}; i <= n; i++){
        for(int j{}; j < m; j++){
            dp[i][j] = LONG_LONG_MIN;
        }
    }

    for(int i{1}; i <= n; i++){
        if (i % 2 == 0){
            ll mx = dp[i-1][m-1];
            for(int j{m-2}; j >= 0; j--){
                dp[i][j] = mx + pf[i-1][j];
                mx = max(mx, dp[i-1][j]);
            }
        }else{
            ll mx = dp[i-1][0];
            for(int j{1}; j < m; j++){
                dp[i][j] = mx + pf[i-1][j];
                mx = max(mx, dp[i-1][j]);
            }
        }
    }

    ll mx = LONG_LONG_MIN;
    for(int i{}; i < m; i++){
        mx = max(mx, dp[n][i]);
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