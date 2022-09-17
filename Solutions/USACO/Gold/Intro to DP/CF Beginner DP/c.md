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
    int n, m;
    cin >> n >> m;

    vector<vll> dp(n, vll(m));

    dp[0][0] = 1;
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (i+2 < n && j+1 < m) dp[i+2][j+1] += dp[i][j];
            if (j+2 < m && i+1 < n) dp[i+1][j+2] += dp[i][j];
        }
    }
    cout << dp[n-1][m-1];
}
 
int main(){
    setio("knight");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```
