```

DP state

dp[mask] = maximal value of man in subset j with the first (popcount) women

DP transition

dp[mask] = dp[mask ^ (1 << i)] + a[i][popcount-1], for every bit i that is set in mask

The idea is 

We don't care about how the men are paired up with the woman for each subset! We only care about it's maximal value, so the idea is we could use any of the i-th man to pair up with the popcount-th woman, to get the maximal value.

(not so intuitive to me yet, i kind of looked at the solution)

My initial idea was to have 2^(2*n) bitmask, but this is unnecessary, and would MLE and TLE. The above solution was a smarter way for us to pair up the couple, and make sure that we've tried every necessary pairs.

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
    int n;
    cin >> n;
    
    vector<vi> a(n, vi (n));

    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            cin >> a[i][j];
        }
    }

    vll dp(1 << n);

    for(int i{1}; i < (1 << n); i++){
        //j-th man
        int cnt = __builtin_popcount(i);
        for(int j{}; j < n; j++){
            if (!(i & (1 <<j))) continue;
            dp[i] = max(dp[i], dp[i ^ (1 << j)] + a[j][cnt-1]);
        }
    }
    cout << dp[(1<<n)-1] << '\n';
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    int inc = 1;
    while(t--){
        cout << "Case " << inc++ << ": ";
        solve();
    }
    return 0;
}

```