```

Let's first analyze the sequence


a1 * x2 + y2 * x3 + y3 ..... xn-1 + yn_1 * an

Notice that the order of x and y doesn't really matter, they can be swapped.

(xi-s)(yi-s) >= 0, just simply means either both number is >= s, or <= s

Let's prove that the x y we choose is always in a min max fashion (i.e minimize one and maximize the other one),

Let's have the sum below, and only consider the number ai, xi + yi = ai, without loss of generality, let p > q

... + p * xi + yi * q + ...

If we are to reduce xi by 1 and increase yi by 1,

... + p * (xi-1) + (yi+1) * q + ...

Initial sum would reduce by p and increase by q. Which is smaller than the original sum, bc p > q.

So the idea is it is always good to have one that is min and max, because that ensures us the smallest sum.

But p and q is not really fixed? So obviously, we cannot really do any kind of greedy.

Also notice that, the total options for xi and yi is very small, either just {0, a[i]} / {a[i], 0} OR {s, a[i]-s} / {a[i]-s, s}

Total different number that ends on the right is only 4.

So that gives us the idea to DP.

DP state

dp[i][j] = minimal sum so far at the i-th element s.t j is used as the elemnet on the right (that is yet to sum)


DP Transition

dp[i][j] = min(dp[i][j], dp[i-1][k] + (a[i]-j * k));

For every possible j and k

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

void solve(){
    int n, s;
    cin >> n >> s;

    vll a(n);
    for(auto& i : a) cin >> i;

    map<ll,ll> dp;

    dp[a[0]] = 0;

    for(int i{1}; i < n-1; i++){
        map<ll,ll> dp1;
        if (a[i] <= s){
            dp1[a[i]] = LONG_LONG_MAX;
            dp1[0] = LONG_LONG_MAX;
            for(auto& j : dp){
                dp1[a[i]] = min(dp1[a[i]], j.sec);
                dp1[0] = min(dp1[0], (a[i]*j.fir)+j.sec);
            }
        }
        else{
            if (!dp1.count(s)) dp1[s] = LONG_LONG_MAX;
            if (!dp1.count(a[i]-s)) dp1[a[i]-s] = LONG_LONG_MAX;
            for(auto& j : dp){
                dp1[s] = min(dp1[s], ((a[i]-s)*j.fir)+j.sec);
                dp1[a[i]-s] = min(dp1[a[i]-s], (s*j.fir)+j.sec);
            }
        }
        dp = dp1;
    }

    ll mn = LONG_LONG_MAX;
    for(auto& i : dp) mn = min(mn, i.fir*a[n-1] + i.sec);
    cout << mn << '\n';
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