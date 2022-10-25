```
Dp state
dp[i][j][k][l] = maximum value at i-th row, j-th room, k-th room used and whether it have considered the adjacent room(1 yes 0 no)

Dp transition

There are 3 transitions in total, only transition from a cell that is valid (value is >= 0, every state is initialized with -1, except for base case)

Go straight down,
dp[i+1][j][k+1][l] = max(dp[i+1][j][k+1][l], dp[i][j][k][l] + grid[i+1][j])

Go to the adjacent cell (only when l is 0, to avoid overcount)
dp[i][!j][k+1][!l] = max(dp[i][!j][k+1][!l], dp[i][j][k][l] + grid[i][!j])

Consider the adjacent cell w/o going to it (only when l is 0, to avoid overcount)
dp[i][j][k+1][!l] = max(dp[i][j][k+1][!l], dp[i][j][k][l] + grid[i][!j])

Base case

dp[0][0/1][0][0] = 0

Initially, I only consider the first 2 transitions, omitted the third one, basically, I only considered counting galleries which can be represented as a path, which is not true in general

which failed at

3 2
100 1
100 100
100 1
0 0

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
 
int dp[300][2][450][2];
 
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    vector<vi> grid(n+1, vi(2));
 
    for(int i{}; i <= n; i++){
        cin >> grid[n-i][0] >> grid[n-i][1];
    }
 
    memset(dp, -1, sizeof(dp));
 
    dp[0][0][0][0] = 0;
    dp[0][1][0][0] = 0;
    for(int i{}; i <= n; i++){
        for(int j{}; j < (n*2)-k; j++){
            //go straight down 
            if (i < n){
                if (dp[i][0][j][0] >= 0){
                    dp[i+1][0][j+1][0] = max(dp[i+1][0][j+1][0], dp[i][0][j][0] + grid[i+1][0]);
                }
                if (dp[i][1][j][0] >= 0){
                    dp[i+1][1][j+1][0] = max(dp[i+1][1][j+1][0], dp[i][1][j][0] + grid[i+1][1]);
                }
            }
            //go down after visiting the adjacent
            if (i < n){
                if (dp[i][0][j][1] >= 0){
                    dp[i+1][0][j+1][0] = max(dp[i+1][0][j+1][0], dp[i][0][j][1] + grid[i+1][0]);
                }
                if (dp[i][1][j][1] >= 0){
                    dp[i+1][1][j+1][0] = max(dp[i+1][1][j+1][0], dp[i][1][j][1] + grid[i+1][1]);
                }
            }
            //visit adjacent
            if (dp[i][0][j][0] >= 0){
                dp[i][1][j+1][1] = max(dp[i][1][j+1][1], dp[i][0][j][0] + grid[i][1]);
            }
            if (dp[i][1][j][0] >= 0){
                dp[i][0][j+1][1] = max(dp[i][0][j+1][1], dp[i][1][j][0] + grid[i][0]);
            }

            //take the adjacent w/o going to it
            if (dp[i][0][j][0] >= 0){
                dp[i][0][j+1][1] = max(dp[i][0][j+1][1], dp[i][0][j][0] + grid[i][1]);
            }
            if (dp[i][1][j][0] >= 0){
                dp[i][1][j+1][1] = max(dp[i][1][j+1][1], dp[i][1][j][0] + grid[i][0]);
            }
        }
    }
 
    int mx = 0;
    for(int i{}; i < 450; i++){
        mx = max(dp[n][0][i][0], mx);
        mx = max(dp[n][0][i][1], mx);
        mx = max(dp[n][1][i][0], mx);
        mx = max(dp[n][1][i][1], mx);
    }
    cout << mx;
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