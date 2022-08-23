```
dp[i][j] = minmal interval to cover up subarray [i:j]

dp transition = 

for each j in the current subarray[l:r],

if a[l] == a[j], 

dp[l][r] = min(dp[l][r], dp[l][j-1]+dp[j+1][r])

This is because if they are the same character we can treat them as the same interval

else

dp[l][r] = min(dp[l][r], dp[l][j]+dp[j+1][r])

DP order = from smaller subarray to bigger
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
    for(auto& i :a) cin >> i;

    //n+1, to avoid going out of bounds
    vector<vi> dp(n+1, vi (n+1));
    for(int i{}; i < n; i++){
        dp[i][i] = 1;
    }

    for(int i{2}; i <= n; i++){
        for(int j{}; j <= n-i; j++){
            dp[j][j+i-1] = INT_MAX;
            for(int k{j}; k < j+i; k++){
                if (j != k && a[j] == a[k]){
                    dp[j][j+i-1] = min(dp[j][j+i-1], dp[j][k-1] + dp[k+1][j+i-1]);
                }else{
                    dp[j][j+i-1] = min(dp[j][j+i-1], dp[j][k] + dp[k+1][j+i-1]);
                }
            }
        }
    }

    cout << dp[0][n-1] << '\n';
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