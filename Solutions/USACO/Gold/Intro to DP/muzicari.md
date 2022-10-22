```
We can simply the problem down to

We're given a 2xT rectangles, we are to fit every 1xa[i] rectangle into it!

It is always possible to fit all of them in!

The idea is, we can knapsack on one of the row, use as much space as possible (most optimal) on one of the row, this will guanratee us the next row will be perfectly fit in as well!

Simply greedy would fail this, same as the reason why greedy doesn't work on knapsack problem.
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
    int t, n;
    cin >> t >> n;

    vi a(n);
    for(auto& i :a) cin >> i;


    //{val,used or no}
    vector<vector<pi>> dp(n+1, vector<pi>(t+1));

    for(int i{}; i < n; i++){
        for(int j{}; j <= t; j++){
            dp[i+1][j].fir = dp[i][j].fir;
            if (j-a[i] >= 0 && dp[i+1][j].fir < dp[i][j-a[i]].fir+a[i]){
                dp[i+1][j].fir = dp[i][j-a[i]].fir+a[i];
                dp[i+1][j].sec = 1;
            }
        }
    }

    vi first(n);

    int i = n-1, j = t;
    while (j){
        if (dp[i][j].sec){
            i--;
            j -= a[i];
            first[i] = 1;
        }else{
            i--;
        }
    }

    vi res(n);

    int cur = 0;
    for(int i{}; i < n; i++){
        if (first[i]){
            res[i] = cur;
            cur += a[i];
        }
    }

    cur = 0;
    for(int i{}; i < n; i++){
        if (!first[i]){
            res[i] = cur;
            cur += a[i];
        }
    }

    for(auto& i : res) cout << i << ' ';
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