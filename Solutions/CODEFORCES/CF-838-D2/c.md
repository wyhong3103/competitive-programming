```

DP state

dp[i] = number of good extensions that ends at i
dp1[i] = number of good extension that has length 2m-1 and has exactly m a[i]

The reason we need number of good extensions that has exactly m a[i] is because

In this situation we can change median from a[i-1] to a[i] when a[i] != a[i-1]

For example, when we have m 1s, m-1 0s, we can add 2 0s to change the current median to 0! We can only do this (by adding 2 0 changing to the opposite median) when previous have exactly m!

DP transition

if a[i] == a[i-1]:
	dp[i] = dp[i-1] * 2 (extend by !a[i],a[i] or a[i],a[i])
	dp1[i] = dp1[i-1] (when we extend by !a[i],a[i] number of each 0s and 1s stays the same)
else:
	dp[i] = dp1[i-1] (we put two a[i],a[i] to flip the previous median)
	dp1[i] = dp[i] (all the current extension has exactly m a[i] and m-1 !a[i])

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


const int MOD = 998244353;

void solve(){
    int n;
    cin >> n;

    //number of good extension that ends at i
    vll dp(n);
    //number of good extension that length 2m-1 and has exactly m of a[i]
    vll dp1(n);

    dp[0] = 1;
    dp1[0] = 1;

    string s;
    cin >> s;

    for(int i{1}; i < n; i++){
        if (s[i] == '1'){
            if (s[i-1] == '0'){
                //pulling 11
                dp[i] = dp1[i-1];
                dp1[i] = dp[i];
            }else{
                //01 and 11
                dp[i] = (dp[i-1] * 2) % MOD;
                //when we use 01
                dp1[i] = dp1[i-1];
            }
        }else{
            if (s[i-1] == '1'){
                //pulling 00
                dp[i] = dp1[i-1];
                dp1[i] = dp[i];
            }else{
                //10 and 11
                dp[i] = (dp[i-1] * 2) % MOD;
                //when we use 01
                dp1[i] = dp1[i-1];
            }
        }
    }

    ll sm = 0;
    for(auto& i : dp){
       sm = (sm + i) % MOD;
    }
    cout << sm << '\n';
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