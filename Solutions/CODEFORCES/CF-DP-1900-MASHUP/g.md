```

instead of using

dp[i][sums of a[j]][sums of b[i]] = 1 if we can reach this state 0 if we cant

notice that

sums(a[j]) / sums(b[j]) = k
sums(a[j]) = sums(b[j]) * k

sums(a[j]) - sums(b[i]) * k = 0

We just need to store the difference!!!! That would reduce the state by one dimension, which is very efficient.

At the end, the answer is just dp[0].

We might need to use a map, since it involves negative number.

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

void solve(){
    int n, k;
    cin >> n >> k;

    vi a(n), b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    map<int,int> dp;
    map<int,int> dp1;

    dp[0] = -1;

    for(int i{}; i < n; i++){
        for(auto& j : dp){
            dp1[j.fir] = max(dp1.count(j.fir) ? dp1[j.fir] : -1, j.sec);
            dp1[j.fir + a[i] - k * b[i]] = max(dp1[j.fir + a[i] - k * b[i]], a[i] + (j.sec == -1 ? 0 : j.sec));
        }
        swap(dp1, dp);
    }

    cout << dp[0];
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