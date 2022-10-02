This is the one that I can think of, I know it could be done by a 3D dp.
```

dp[i][j][k][l] = winning state for alice when there's i odd, j even, alice's parity = k (0 = even, 1 even), bob/alice turn (0 = alice, 1 = bob)

dp basecase

dp[0][0][0][0] = 1;
dp[0][0][0][1] = 1;
dp[0][0][1][0] = 0;
dp[0][0][1][1] = 0;

When it's empty and its even, it's a winning state else losing state.


dp transition

if current round is bob's round

we will try to minimize the value (take losing state for alice), and doesn't matter what value do we take, it doesn't affect the alice's parity so

dp[i][j][k][l] = min(dp[i-1][j][k][!l], dp[i][j-1][k][!l]);

if current round is alice's round

we will try to maximize the value (take winning state for alice), taking odd number flip our parity, taking even remain

when l = 1

dp[i][j][k][l] = min(dp[i-1][j][!k][!l], dp[i][j-1][k][!l]);
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
 
 
int recur(int o, int e, int parity, int p, auto& dp){
    if (dp[o][e][parity][p] != -1) return dp[o][e][parity][p];
 
    if (p){
        //Bob's turn
        dp[o][e][parity][p] = min((o >= 1 ? recur(o-1, e, parity, !p, dp) : 1), (e >= 1 ? recur(o, e-1, parity, !p,dp) : 1));
    }else{
        dp[o][e][parity][p] = max((o >= 1 ? recur(o-1, e, !parity, !p, dp) : 0), (e >= 1 ? recur(o, e-1, parity, !p,dp) : 0));
    }
 
    return dp[o][e][parity][p];
}
 
void solve(){
    int n;
    cin >> n;
 
    pi cnt;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        x %= 2;
        x += 2;
        x %= 2;
        if (x) cnt.sec++;
        else cnt.fir++;
    }
 
    vector<vector<vector<vi>>> dp(n+1, vector<vector<vi>> (n+1, vector<vi> (2, vi(2, -1))));
    dp[0][0][0][0] = 1;
    dp[0][0][0][1] = 1;
    dp[0][0][1][0] = 0;
    dp[0][0][1][1] = 0;
    recur(cnt.sec, cnt.fir, 0, 0, dp);
 
    cout << (dp[cnt.sec][cnt.fir][0][0] == 1 ? "Alice" : "Bob") << '\n';
 
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