```

Observations

1. If current value is not 0, we can always make a different, either + a[i+1] or - a[i+1] by our current value

2. It's very obvious that we need to know all of our current value, because we need to know when we're going to result a[i+1] as 0, which would affect the number of distinct sequences.

3. Only the current value matters, whatever is before it, doesn't matter at all. Which implied, it's either we add the next value or subtract the next value, it doesn't really matter what we do to the previous element. This is an indication for DP.

DP state

dp[i][j] = number of different sequences so far at i-th such that we have j as our current value for i-th element

DP Base case

dp[1][a[1]] = 1

DP transition

If j == 0,

dp[i+1][a[i+1]] += dp[i][j]  

Otherwise,

dp[i+1][a[i+1] + j] += dp[i][j]
dp[i+1][a[i+1] - j] += dp[i][j]  

Notice that number could go negative, so we need a way to tackle this w/o using map to store the dp state. Notice that for each number it ranges from [0, 300], at max, we could have 300*300, we can also assume that at worst, we could have -300*300

So we could transform the actual value with this formula = abs(-300*300 + a[i]), so that the value is always a positive number which allows us to store as index.

When doing transition, we need to transform j back to its actual value, and then only subtract/add to a[i+1]

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

const int MXN = 305;
const int MXM = 300*300*2 + 5;
const int MOD = 998244353;
int dp[MXN][MXM];

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    const int MN = -300*300;

    dp[1][abs(MN-a[1])] = 1;

    for(int i{1}; i < n-1; i++){
        for(int j{}; j < MXM; j++){
            if (!dp[i][j]) continue;
            int nxt = abs(MN-a[i+1]);
            int cur = abs(-MN-j);
            if (cur) dp[i+1][nxt+cur] = (dp[i+1][nxt+cur] + dp[i][j]) % MOD; 
            dp[i+1][nxt-cur] = (dp[i+1][nxt-cur] + dp[i][j]) % MOD;
        }
    }    

    int total = 0;
    for(int i{}; i < MXM; i++){
        total += dp[n-1][i];
        total %= MOD;
    }
    cout << total;
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