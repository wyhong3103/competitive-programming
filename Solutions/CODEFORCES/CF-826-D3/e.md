```

dp[i] = state of the i-th element, it's true if it's one of the ends of a segment, otherwise false.

dp transition

if the current element was to be a beginning, it's previous element must be an ending and i+a[i] must be within the boundary

so we mark dp[i+a[i]] = 1

if the current element was to be an ending, dp[i-a[i]-1] must be true (an ending), because if we are to start a segment at i-a[i], i-a[i]-1 must be one of the ending

so we mark

dp[i] = 1

finally if dp[n] is an ending then good

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
    vi a(n);
    for(auto& i : a) cin >> i;
 
    vi dp(n+1);
    dp[0] = 1;
 
    for(int i{1}; i <= n; i++){
        //right
        if (i+a[i-1] <= n && dp[i-1]){
            dp[i+a[i-1]] = 1;
        }
        //left
        if (i-1-a[i-1] >= 0 && dp[i-1-a[i-1]]){
            dp[i] = 1;
        }
    }
    cout << (dp[n] ? "YES" : "NO")<< '\n';
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