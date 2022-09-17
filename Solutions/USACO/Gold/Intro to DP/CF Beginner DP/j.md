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
    
    if (!n){
        cout << 1;
        return;
    }

    vector<vi> dp(n, vi(3));
    fill(all(dp[0]),1);
    
    for(int i{1}; i < n; i++){
        for(int j{1}; j < 3; j++){
            dp[i][1] += dp[i-1][j];
        }
        for(int j{}; j < 3; j++){
            dp[i][0] += dp[i-1][j];
        }
        for(int j{}; j < 3; j++){
            dp[i][2] += dp[i-1][j];
        }
    }
    cout << dp[n-1][0]+dp[n-1][1]+dp[n-1][2];
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