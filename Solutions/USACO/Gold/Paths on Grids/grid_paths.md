```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MX = 1000;
const int MOD = 1e9 + 7;
int dp[MX][MX];

void solve(){
    int n;
    cin >> n;

    vector<string> grid(n);
    for(auto& i : grid) cin >> i;

    dp[0][0] = (grid[0][0] == '.' ? 1 : 0);
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            if (grid[i][j] == '*') continue;
            if (i < n-1) dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            if (j < n-1) dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
        }
    }

    cout << (grid[n-1][n-1] == '.' ? dp[n-1][n-1] : 0);
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