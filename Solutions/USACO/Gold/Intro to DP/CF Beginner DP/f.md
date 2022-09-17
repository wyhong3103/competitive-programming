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

    vi coins;

    int total = 0;
    int cur = 1;
    while (total <= n){
        total += (cur*(cur+1))/2;
        coins.pb(total);
        cur++;
    }

    int m = sz(coins);

    vi dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i{1}; i <= n; i++){
        for(int j{}; j < m; j++){
            if (i-coins[j] >= 0) dp[i] = min(dp[i], dp[i-coins[j]]+1);
        }
    }
    cout << dp[n] << '\n';
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