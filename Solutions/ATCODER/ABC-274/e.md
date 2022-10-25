```

A very standard bitmask DP.


dp[s][i] = minimal time needed to reach i-th node as the last node after going through (bit that is set in s) nodes


transition

for every 1 in s,  we try to let i be the last node, and visit from every other 1 in (s^i)

first N nodes are island, last M nodes are chests

if we ever reach a chest, we should update our speed

After doing the above

we check if current S has involved every N island, if yes, we try to let it go back to the origin, and the answer is simply the minimal of that.

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
 
 
const int MX = 18;
//time , speed (speed isn't really necessary! if we have visited a set of m nodes, then speed is simply 2^m)
pair<long double, ll> dp[1 << MX][MX];
 
long double dist(pll a, pll b){
    return hypot(a.fir-b.fir, a.sec-b.sec);
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<pll> a(n);
    vector<pll> b(m);
 
    for(auto& i :a) cin >> i.fir >> i.sec;
    for(auto& i :b) cin >> i.fir >> i.sec;
 
    for(int i{}; i < (1 << (n+m)); i++){
        for(int j{}; j < n+m; j++){
            dp[i][j] = {-1 ,-1};
        }
    }
 
    //remember to go back to the origin
    long double mn = DBL_MAX;
    for(int i{1}; i < (1 << (n+m)); i++){
        for(int j{}; j < n+m; j++){
            if (i & (1 << j)){
                int cnt = __builtin_popcount(i);
 
                if (j < n){
                    if (cnt == 1){
                        dp[i][j] = {dist(a[j], {0,0}), 1};
                        break;
                    }
                    for(int k{}; k < n+m; k++){
                        if (j == k) continue;
                        if (i & (1 << k)){
                            pll loc = (k < n ? a[k] : b[k-n]);
                            if (dp[i][j].fir == -1 || dp[i ^ (1 << j)][k].fir + (dist(a[j], loc)/dp[i^(1<<j)][k].sec) < dp[i][j].fir){
                                dp[i][j] = {dp[i^(1<<j)][k].fir + (dist(a[j], loc)/dp[i^(1<<j)][k].sec), dp[i^(1<<j)][k].sec};
                            }
                        }
                    }
                }else{
                    if (cnt == 1){
                        dp[i][j] = {dist(b[j-n], {0,0}), 2};
                        break;
                    }
                    for(int k{}; k < n+m; k++){
                        if (j == k) continue;
                        if (i & (1 << k)){
                            pll loc = (k < n ? a[k] : b[k-n]);
                            if (dp[i][j].fir == -1 || dp[i ^ (1 << j)][k].fir + (dist(b[j-n], loc)/(dp[i^(1<<j)][k].sec)) < dp[i][j].fir){
                                dp[i][j] = {dp[i^(1<<j)][k].fir + (dist(b[j-n], loc)/(dp[i^(1<<j)][k].sec)), dp[i^(1<<j)][k].sec*2};
                            }
                        }
                    }
                }
            }
        }
        int cnt = 0;
        for(int j{}; j < n; j++){
            if (i & (1 << j)) cnt++;
        }
        if (cnt == n){
            for(int j{}; j < n+m; j++){
                if (i & (1<<j)) {
                    pll loc = (j < n ? a[j] : b[j-n]);
                    mn = min(mn, dp[i][j].fir + (dist(loc, {0,0}) / dp[i][j].sec));
                }
            }
        }
    }
 
    cout << setprecision(7) << fixed;
    cout << mn;
 
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