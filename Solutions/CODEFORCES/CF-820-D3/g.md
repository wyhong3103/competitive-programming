```
This problem can totally be reduced down to 2D DP as we only need the minimal move!

DP State

dp[i][j][k] = numbers of ways can be done to empty all substring t in s[0:i] using j moves and whether the current position is being removed or no (if k == 0, then the current substring ending at i is not being removed but instead transitioned, if k == 1, then the current substring is removed)

DP Basecase

dp[0][0][0] = 1

When the string is empty, there is exactly one way to clear substring t!

DP Transition

if s[i-m : i] == t
	
	//At i-m, it could/couln't be a substring, regardless, we have to transition from it! It is an optimal substructure, so there is no need to worry that we might skip something

	dp[i][j+1][1] += dp[i-m][j][0] + dp[i-m][j][1], for 0 <= j <= n


	//If within the substring t that ends at i, can forms another substring t, that means the current substring t, won't be able to remove, as part of it has already been removed within!
	
	dp[i][k][0] += dp[i-j][k][1], for 1 <= j <= size of t, 0 <= k <= n
	
else
	
	//If the current substring ends at i, isn't t, then simply transition from the previous dp state

	dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][1], 0 <= j <= n

Finally prints the lowest move needed and the number of ways at dp[n][i] , 0 <= i <= n

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

const int MOD = 1e9 + 7;

void solve(){
    string a, b;
    cin >> a >> b;

    int n = sz(a);
    int m = sz(b);
    vector<vector<vi>> dp(n+2, vector<vi> (n+2, vi (2)));
    dp[0][0][0] = 1;

    for(int i{1}; i <= n; i++){
        if (i-m >= 0 && a.substr(i-m, m) == b){
            for(int j{}; j <= n; j++){
                dp[i][j+1][1] += dp[i-m][j][0];
                dp[i][j+1][1] %= MOD;
                dp[i][j+1][1] += dp[i-m][j][1];
                dp[i][j+1][1] %= MOD;
            }
            for(int j{(i-m)+1}; j < i; j++){
                for(int k{}; k <= n; k++){
                    dp[i][k][0] += dp[j][k][1];
                    dp[i][k][0] %= MOD;
                }
            }
        }else{
            for(int j{}; j <= n; j++){
                dp[i][j][0] += dp[i-1][j][0];
                dp[i][j][0] %= MOD;
                dp[i][j][0] += dp[i-1][j][1];
                dp[i][j][0] %= MOD;
            }
        }
    }

    for(int i{}; i <= n; i++){
        if (dp[n][i][0] || dp[n][i][1]){
            cout << i << ' ' << (dp[n][i][0] + dp[n][i][1]) % MOD << '\n';
            return;
        }
    }
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