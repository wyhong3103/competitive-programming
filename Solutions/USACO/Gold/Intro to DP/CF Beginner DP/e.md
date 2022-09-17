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
    
    vector<vi> a(n, vi (n));

    for(int i{}; i < n; i++){
        for(int j{}; j <= i; j++){
            cin >> a[i][j];
        }
    }
    
    vector<vi> dp(n, vi (n, -INT_MAX));

    dp[0][0] = a[0][0];
    for(int i{1}; i < n; i++){
        for(int j{}; j <= i; j++){
            if (j >= 1){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i][j]);
            }
            if (j != i){
                dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i][j]);
            }
        }
    }

    int res = -INT_MAX;
    for(int i{}; i < n; i++){
        res = max(dp[n-1][i], res);
    }
    cout << res;
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