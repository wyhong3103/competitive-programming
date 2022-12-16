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
 
    vector<string> a(2);
    for(auto& i : a) cin >> i;
 
    int total = 0;
    for(auto& i : a){
        for(auto& j : i){
            total += j == 'B';
        }
    }
 
    
    //always start from left most
 
 
    vector<vi> dp(2, vi(n));
 
    if (a[0][0] == 'B') dp[0][0] = 1;
    if (a[1][0] == 'B') dp[1][0] = 1;
 
    for(int i{}; i < n; i++){
        //from left
        if (a[0][i] == 'B'){
            if (i-1 >= 0 && dp[0][i-1]) dp[0][i] = 1 + dp[0][i-1];
        }
        if (a[1][i] == 'B'){
            if (i-1 >= 0 && dp[1][i-1]) dp[1][i] = 1 + dp[1][i-1];
        }
 
        int temp0 = dp[0][i];
        int temp1 = dp[1][i];
 
        //from up/down
        if (a[0][i] == 'B'){
            if (dp[1][i]) dp[0][i] = max(dp[0][i], 1 + temp1);
        }
        if (a[1][i] == 'B'){
            if (dp[0][i]) dp[1][i] = max(dp[1][i], 1 + temp0);
        }
    }
 
    cout << (max(dp[1][n-1],dp[0][n-1]) == total ? "YES" : "NO") << '\n';
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