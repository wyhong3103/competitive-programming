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
 

const int MXN = 1e5 + 5;
const int MXM = 105;
const int MOD = 1e9 + 7;

ll dp[MXN][MXM];

 
void solve(){
    int n, m;
    cin >> n >> m;

    vi a(n);
    for(auto& i : a) cin >> i;

    dp[0][a[0]] = 1;
    if (!a[0]){
        for(int i{1}; i <= m; i++) dp[0][i] = 1;
    }
    for(int i{}; i < n; i++){
        if (a[i] != 0){
            dp[i+1][a[i]+1] = (dp[i+1][a[i]+1] + dp[i][a[i]]) % MOD;
            dp[i+1][a[i]] = (dp[i+1][a[i]] + dp[i][a[i]]) % MOD;
            dp[i+1][a[i]-1] = (dp[i+1][a[i]-1] + dp[i][a[i]]) % MOD;
            continue;
        }
        for(int j{1}; j <= m; j++){
            if (!dp[i][j]) continue;
            dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;
        }
    }
    
    if (a[n-1] != 0){
        cout << dp[n-1][a[n-1]];
        return;
    }
    ll total = 0;
    for(int i{1}; i <= m; i++){
        total = (total + dp[n-1][i]) % MOD;
    }

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