```

It turned out we can do this with dp!

Let dp state:

dp[i][j] = number of good sequences with MEX = i, (largest number is i-1 if j == 0, else largest number is i+1)

Let dp transition:

First off, let's look at the case where a[i] == 0 and a[i] == 1

These are the only two numbers we can start a subsequence with

if (a[i] == 0):
	dp[1][0] = 1

if (a[i] == 1):
	dp[0][1] = 1


Another thing we need to take note of is that, we can only fill a MEX from dp[a[i]][0], but not dp[a[i]][1], this is because, if we are to fill a MEX sequence that exist a number that is MEX+1, when we add a[i] to the subseq, MEX would become MEX+2, and (MEX+2)-MEX > 1

So,

Transition to fill in the MEX is

dp[a[i]+1][0] += dp[a[i]][0]

Now, transition to continue down the subseq!


continuing the subseq with MEX-1

dp[a[i]+1][0] = (dp[a[i]+1][0] * 2)
dp[a[i]+1][1] = (dp[a[i]+1][1] * 2)

continuing the subseq with MEX+1

if (a[i]){
   dp[a[i]-1][1] = (dp[a[i]-1][1] + dp[a[i]-1][1])
   dp[a[i]-1][1] = (dp[a[i]-1][1] + dp[a[i]-1][0])
}
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

    vi a(n);
    for(auto& i : a) cin >> i;

    vector<vll> dp(n+5, vll(2));
    for(int i{}; i < n; i++){
        //continuing the subseq with MEX-1
        dp[a[i]+1][0] = (dp[a[i]+1][0] * 2) % MOD;
        dp[a[i]+1][1] = (dp[a[i]+1][1] * 2) % MOD;

        //continuing the subseq with MEX+1
        if (a[i]){
            dp[a[i]-1][1] = (dp[a[i]-1][1] + dp[a[i]-1][1]) % MOD;
            dp[a[i]-1][1] = (dp[a[i]-1][1] + dp[a[i]-1][0]) % MOD;
        }

        //fill the MEX
        dp[a[i]+1][0] = (dp[a[i]+1][0] + dp[a[i]][0]) % MOD;

        if (a[i] == 0){
            dp[1][0] = (dp[1][0] + 1) % MOD;
        }else if (a[i] == 1){
            dp[0][1] = (dp[0][1] + 1) % MOD;
        }
    }

    ll total = 0;
    for(int i{}; i <= n+2; i++){
        total = (total + dp[i][0] + dp[i][1]) % MOD;
    }
    cout << total << '\n';
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