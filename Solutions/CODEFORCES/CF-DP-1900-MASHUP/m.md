```

DP on grid

dp[i][j][l][x] = maximal sum at cell[i][j] s.t l group has been used and if x == 1, we haven't closed l-th group, x == 0, l group is closed

if a[i] == b[j]

transition from dp[i-1][j-1], either continue the group, or create new group from a group that is currently continuing or a group that is finished


Regardless of the situation

transition from dp[i-1][j] & dp[i][j-1]

get the max for the current cell


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

const int MX =1005;

int dp[MX][MX][11][2];
 
void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    string a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));

    for(int i{}; i <= n; i++) dp[i][0][0][0] = 0;
    for(int i{}; i <= m; i++) dp[0][i][0][0] = 0;

    for(int i{1}; i <= n; i++){
        for(int j{1}; j <= m; j++){
            if (a[i-1] == b[j-1]){
                for(int l{}; l <= k; l++){
                    if (dp[i-1][j-1][l][1] != -1){
                        dp[i][j][l][1] = max(dp[i][j][l][1], dp[i-1][j-1][l][1]+1);
                    }
                    if (l < k && dp[i-1][j-1][l][0] != -1){
                        dp[i][j][l+1][1] = max(dp[i][j][l+1][1], dp[i-1][j-1][l][0]+1);
                    }
                    if (l < k && dp[i-1][j-1][l][1] != -1){
                        dp[i][j][l+1][1] = max(dp[i][j][l+1][1], dp[i-1][j-1][l][1]+1);
                    }
                }
            }
            for(int l{}; l <= k; l++){
                if (dp[i-1][j][l][1] != -1){
                    dp[i][j][l][0] = max(dp[i][j][l][0], dp[i-1][j][l][1]);
                }
                if (dp[i-1][j][l][0] != -1){
                    dp[i][j][l][0] = max(dp[i][j][l][0], dp[i-1][j][l][0]);
                }
                if (dp[i][j-1][l][1] != -1){
                    dp[i][j][l][0] = max(dp[i][j][l][0], dp[i][j-1][l][1]);
                }
                if (dp[i][j-1][l][0] != -1){
                    dp[i][j][l][0] = max(dp[i][j][l][0], dp[i][j-1][l][0]);
                }
            }
        }
    }

    cout << max(dp[n][m][k][1], dp[n][m][k][0]);
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