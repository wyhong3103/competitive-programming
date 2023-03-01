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
 
const int MX = 2e5 + 5;
const int MOD = 998244353;
int dp[MX][2];
 
void solve(){
    int n;
    cin >> n;
    vector<pi> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;
 
    dp[0][0] = 1;
    dp[0][1] = 1;
 
    for(int i{1}; i < n; i++){
        if (a[i].fir != a[i-1].fir) {
            dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
        }
 
        if (a[i].fir != a[i-1].sec) {
            dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
        }
 
        if (a[i].sec != a[i-1].fir) {
            dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
        }
 
        if (a[i].sec != a[i-1].sec) {
            dp[i][1] = (dp[i][1] + dp[i-1][1]) % MOD;
        }
    }
 
    cout << (dp[n-1][0]+dp[n-1][1]) % MOD;
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