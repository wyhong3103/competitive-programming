```
I don't think this should be a normaly problem , tbh. Also, idk if its because I already knew how this work (because of CPH), or it's really not this hard.

Could just take a look at CPH, it has a good explanation on this problem.
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

void solve(){
    ll n, x;
    cin >> n >> x;

    //{total, last ride's weight}
    vector<pll> dp(1 << n);
    vi a(n);
    for(auto& i : a) cin >> i;


    dp[0] = {1,0};
    for(int i{1}; i < (1 << n); i++){
        dp[i].fir = INT_MAX;
        for(int j{}; j < n; j++){
            if (i & (1 << j)){
                if (dp[i^(1<<j)].sec + a[j] <= x){
                    dp[i] = min(dp[i], {dp[i^(1<<j)].fir, dp[i^(1<<j)].sec+a[j]});
                }else{
                    dp[i] = min(dp[i], {dp[i^(1<<j)].fir+1, a[j]});
                }
            }
        }
    }

    cout << dp[(1<<n)-1].fir;
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