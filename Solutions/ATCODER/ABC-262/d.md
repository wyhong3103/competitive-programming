Totally did not expect this solution to work, but damn, it worked in first try!
```
This is a little complicated ngl.

Anyways, this is a 4 dimensional DP, space and time complexity = O(n^4)

DP state = [subset size, item, value, weight]

This is kind of like knapsack, but also a little coin change, as it counts the number of ways to form an element.


Anways, notice that, in order for the average of a certain size to be integer, the remainder of the sum of the elements (mod subset size) must be 0.

So we can apply a little modular arithmetic here.

And here is the transition

dp[m][i][j][k] = m-th subset size, i-th item, j-th value, k-th weight

dp[m][i][j][k] += dp[m][i-1][(j-a[i]) % m][k-1] % MOD
dp[m][i][j][k] += dp[m][i-1][j][k] % MOD

And the reason we're doing this is because


Note that, in coin change, if we are to form a coin of value j, we transition from the previous coin , dp[j] += dp[j-value]

In this case, we are doing the same thing, but to deal with modulus of the subset size, and it will never goes out of bound because of modulus, so we could just sum them up.

k-1, because each element weighted 1, we will have to take the previous weight.

If (j-a[i]) % m == 0 and k == 1, we should add 1 to the dp value, as it's transitiong from dp[0][0] which is empty state, and ways to form an empty state is always 1.

The reason we will have to deal with each subset size individually is because the value we're using for each subset size, is apparently the remainder, and the value of 0 when m = 3, and m = 2, is apparently different, so there is no way we could transition between different subset size.
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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}


const int MX = 101;
const int MOD = 998244353;
ll dp[MX][MX][MX][MX];
 
void solve(){
    int n;
    cin >> n;

    vll a(n);
    for(auto& i : a) cin >> i;

    ll cnt = 0;
    for(int m{1}; m <= n; m++){
        for(int i{1}; i <= n; i++){
            for(int j{}; j < m; j++){
                for(int k{1}; k <= m; k++){
                    if ((((j-a[i-1])%m)+m)%m == 0 && k == 1) dp[m][i][j][k] = (dp[m][i][j][k]+1) % MOD;
                    else dp[m][i][j][k] = (dp[m][i][j][k] + dp[m][i-1][(((j-a[i-1])%m)+m)%m][k-1]) % MOD;
                    dp[m][i][j][k] = (dp[m][i][j][k] + dp[m][i-1][j][k]) % MOD;
                }
            }
        }

        cnt = (cnt + dp[m][n][0][m]) % MOD;
    }

    cout << cnt;
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