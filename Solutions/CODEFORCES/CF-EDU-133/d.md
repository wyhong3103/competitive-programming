Not so intuitive way of solving it.
```
Length of move goes like this

k, k+1, k+2, k+3...

sum of moves would definitely <= n

So the maximal moves we can make is around ~ 650

650*(651)/2 ~ 200,000

DP state = [i,j] = [k+i-th move, j-th element] = Number of ways to reach j-th element with only using the k+i-th length

DP transition = dp[i][j] += dp[i-1][j-(k+i)] + dp[i][j-(k+i)], such that j-(k+i) >= 0

The reason is we could only transition from the cell with k+i-1 length, also because we're only transitioning from the element that is with k+i-1 move, (only once), but the truth is we could transition from more than once from that particular element.

For example,

Say we have j = 1, i = 2, the element that will be reached from j=1, is 1+2, 1+4, 1+6.....

So, by transitioning from dp[i][j-(k+i)], that will be considered.

And the final answer is the sum of the column, in this problem, we will have to perform some space trick, or else we're getting MLE.
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
 
const int MX = 2e5+5;
const int MOD = 998244353;

int dp1[MX];
int dp[MX];

void solve(){
    int n, k;
    cin >> n >> k;
    
    vi res(n);
    dp1[0] = 1;
    for(int i{1}; i < 751; i++){
        for(int j{}; j <= n; j++){
            if (j-(k+(i-1)) >= 0){
                dp[j] = (dp1[j-(k+(i-1))] + dp[j]) % MOD;
                dp[j] = (dp[j-(k+(i-1))] + dp[j]) % MOD;
            }
        }
          
        //space trick
        for(int j{}; j <= n; j++){
            if (j) res[j-1] = (res[j-1] + dp1[j]) % MOD;
            dp1[j] = dp[j];
            dp[j] = 0;
        }
    }

    for(int j{1}; j <= n; j++){
        res[j-1] = (res[j-1] + dp[j]) % MOD;
    }

    for(auto& i : res) cout << i << ' ';
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

With prefix sum
```

dp[i][j] = numbers of way in which we reach j, making exactly i moves

Let x = k+i-1
dp[i][j] = dp[i-1][j-x] + dp[i-1][j-2x] + dp[i-1][j-3x]....


```