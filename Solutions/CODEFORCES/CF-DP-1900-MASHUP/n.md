```

DP State

dp[i][j][k] = i-th bottle used, j bottle used, k free space, k could be negative

If we do not let k be negative, we would have to deal with a lot other stuff, like what to do when free space is smaller than what we can pour etc, so we can let k be negative and let the next bottle handle it

Transition

Use the current bottle

dp[i][j][k + (b[i]-a[i])] = max(dp[i][j][k+(b[i]-a[i])], dp[i-1][j-1][k])

Dont use the current bottle

dp[i][j][k-a[i]] = max(dp[i][j][k+-a[i]], dp[i-1][j][k] + a[i])


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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


const int MX = 105;
unordered_map<int,int> dp[MX][MX];
 
void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    dp[0][0][0] = 0;

    for(int i{1}; i <= n; i++){
        for(int j{}; j <= n; j++){
            for(auto& k : dp[i-1][j]){
                if (k.sec == INT_MAX) continue;
                //use this bottle
                dp[i][j+1][k.fir+(b[i-1]-a[i-1])] = min((dp[i][j+1].count(k.fir+(b[i-1]-a[i-1])) ? dp[i][j+1][k.fir+(b[i-1]-a[i-1])] : INT_MAX), k.sec);
                //dont use this bottle
                dp[i][j][k.fir-a[i-1]] = min((dp[i][j].count(k.fir-a[i-1]) ? dp[i][j][k.fir-a[i-1]] : INT_MAX), k.sec + a[i-1]);
            }
        } 
    }

    int mn = INT_MAX;
    for(int j{1}; j <= n; j++){
        if (sz(dp[n][j]) >= 1){
            for(auto& k : dp[n][j]){
                if (k.fir >= 0) mn = min(mn, k.sec);
            }
        }
        if (mn != INT_MAX){
            cout << j << ' ' << mn << '\n';
            return;
        }
    }
    
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