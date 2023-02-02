```

My initial idea

E(X) = (1/n)^A * (N) * total number of ways to have the X bits flipped for the first time with only A moves + with A+1 moves...

The above is an infinite series, so we need to find a geometric series or something, to find its the sum of the series

Which is super complicated, and i didnt manage to find a combinatorics way to solve it 

(OR IF ITS EVEN POSSIBLE)

Solution

The key solution is to realize the EV equation

Let X = number of differences in string a and b

E(X) = X/N * (1 + E(X-1)) + (N-X)/N * (1 + E(X+1))

The reason the above would work is because, when we have X differences on the string, the next move we make is either flipping a bit that is the same, or not the same. 

There is n-x bits that are the same, so the probability of that * (1 + E(X+1)) 

Same goes to the bits that are different.

After playing around with the EV equation, we could do some algebra to avoid the infinity recurrence.

Turned out we could always reduce

E(X) to E(X) = C + E(X-1)

And then it's just DP.

Base Case

E(N) = 1 + (E(N-1)) 
E(0) = 0 (since it ends right after it has 0 differences)


We can go from top down

E(N-1) = N-1/N * (1 + E(N-2)) + 1/N * (1 + E(N))

E(N-1) = N-1/N * (1 + E(N-2)) + 1/N * (1 + 1 + E(N-1))

E(N-1) = N-1/N * (1 + E(N-2)) + 1/N + 1/N + E(N-1)/N

N * E(N-1) = N-1 * (1 + E(N-2)) + 1 + 1 + E(N-1)

N * E(N-1) - E(N-1) = N-1 * (1 + E(N-2)) + 1 + 1

(N-1) * E(N-1) = N-1 * (1+E(N-2)) + 2

E(N-1) = 1 + E(N-2) + 2/N-1

E(N-1) = E(N-2) + (1 + (2/N-1))

Play around with the equation, you will see, X/N * (1+E(X-1)) would always get reduce down to 1+E(X-1), cus at the end every term on the right will always get divided by X.

Also, it turns out there is a formula for the constant.

C(X) = ((N-X) * (1 + C(X+1)) / X) + 1

We can compute all constant first (top to bottom),

and then do DP, (bottom to top)

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


const int MOD = 998244353;
ll n;

ll modpow(ll n, ll p){
    if (!p) return 1;
    
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}

ll recur(ll cur, vll& dp, vll& constant){
    if (cur == 0){
        return 0;
    }
    if (cur < n){
        constant[cur] = ((n-cur) * (constant[cur+1] + 1)) % MOD;
        constant[cur] = (constant[cur] * modpow(cur, MOD-2)) % MOD;
        constant[cur] = (constant[cur] + 1) % MOD;
    }

    dp[cur] = (constant[cur] + recur(cur-1, dp, constant)) % MOD;

    return dp[cur];
}

void solve(){
    cin >> n;

    string a, b;
    cin >> a >> b;

    ll x = 0;
    for(int i{}; i < n; i++){
        x += a[i] != b[i];
    }

    vll dp(n+1);
    vll constant(n+1);
    constant[n] = 1;

    recur(n, dp, constant);

    cout << dp[x] << '\n';
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