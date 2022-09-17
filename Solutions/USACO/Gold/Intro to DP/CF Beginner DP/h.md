```
Good problem.

It's actually just coin change , but unordered coin change, took me a while to figure that out.

Let's do the naive O(n^3) dp first, only we try to optimize it.

dp[i][j] = last used coin as coin i and the total number of ways to form strength j while fulfilling all the condition

dp transition,

For every coin i, we can transition from every strength k from coin j, 0 <= j <= floor(i/2)

dp[i][k+i] += dp[j][k]

answer = sum of dp[i][n], 0 <= i <= n

Although this is correct, but it wouldn't work, it's too slow, let's optimize it

The one and only most important observation, 

Notice that if we need to transition from 0 to i/2, we might as well just do a prefix sum on every j from 0 to i/2, because if we can do i/2, then we can also do every state before i/2.

So

dp[i][j] = First i coins used & total number of unordered ways to form set of strength j

dp transition ,

dp[i][j+i] = dp[i/2][j] , 0 <= j <= n 

After doing transition, we add all the value to the next state

dp[i+1][j] += dp[i][j] , 0 <= j <= n
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
    
    vector<vll> dp(n+1, vll (n+1));
    dp[0][0] = 1;

    for(int i{}; i <= n; i++){
        for(int j{}; j <= n; j++){
            if (i && j + i <= n) dp[i][j+i] += dp[i/2][j];
        }

        if (i == n) continue;
        for(int j{}; j <= n; j++){
            dp[i+1][j] += dp[i][j];
        }
    }

    cout << dp[n][n];
}
 
int main(){
    setio("peacefulsets");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```