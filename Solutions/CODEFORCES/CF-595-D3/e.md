```

DP state

dp[i][0/1] = at floor i, it's either we're in the middle of an elavator or we're not

DP transition

dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i-1]
dp[i][1] = min(dp[i-1][0] + c, dp[i-1][1]) + b[i-1]

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
 
const int MX = 2e5 + 5;
ll dp[MX][2];
 
void solve(){
    int n, c;
    cin >> n >> c;
 
    vi a(n-1);
    for(auto& i : a) cin >> i;
    vi b(n-1);
    for(auto& i : b) cin >> i;
 
    dp[1][0] = a[0];
    dp[1][1] = b[0]+c;
    for(int i{2}; i <= n; i++){
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i-1];
        dp[i][1] = min(dp[i-1][0] + c + b[i-1], dp[i-1][1] + b[i-1]);
    }
 
    for(int i{}; i < n; i++){
        cout << min(dp[i][0], dp[i][1]) << ' ';
    }
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