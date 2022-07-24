Input constraint gave a hint that's it's a dp, and it has to be done in n^2 time complexity.
```
DP state = [i-th toss, j-th streak]

DP value = maximum value we can achieve in state [i,j]

Transition = 
dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + x[i] + streak[j])
dp[i+1][0] = max(dp[i+1][0], dp[i][j])

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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MX = 5005;
ll dp[MX][MX];
ll streak[MX];
 
void solve(){
    int n, m;
    cin >> n >> m;
    
    vi x(n);
    for(auto& i : x) cin >> i;
 
    while(m--){
        ll c, y;
        cin >> c >> y;
        streak[c] = y;
    }
    
    for(int i{}; i < n; i++){
        for(int j{}; j <= n; j++){
            if (!dp[i][j] && j) continue;
            dp[i+1][j+1] = max(dp[i][j] + x[i] + streak[j+1], dp[i+1][j+1]);
            dp[i+1][0] = max(dp[i][j], dp[i+1][0]);
        }
    }
 
    ll mx = 0;
    for(int i{}; i <= n; i++){
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