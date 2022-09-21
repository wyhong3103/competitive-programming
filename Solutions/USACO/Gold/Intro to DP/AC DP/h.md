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

const int MOD = 1e9 + 7;
 
void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for(auto& i : a) cin >> i;

    vector<vi> dp(n, vi (m));
    dp[0][0] = 1;
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (a[i][j] == '#') continue;
            if (i-1 >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j-1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[n-1][m-1];
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