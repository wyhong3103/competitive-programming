```

dp[i] = is i a winning position?

base case, dp[0] = 0, losing position

A position is only a winnning position, if we can transition to a losing position. That is

dp[i] |= !dp[i-a[j]] 0 <= i <= k, 0 <= j < n

| = OR

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(auto& i : a) cin >> i;

    vi dp(k+1);
    dp[0] = 0;
    for(int i{}; i <= k; i++){
        for(int j{}; j < n; j++)
            if (i - a[j] >= 0) dp[i] |= !dp[i-a[j]];
    }

    cout << (dp[k] ? "First" : "Second");
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