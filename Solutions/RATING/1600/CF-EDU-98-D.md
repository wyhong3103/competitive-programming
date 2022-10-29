Interesting problem.
```
The most important observation in this problem is that, we're simply asked to find the number of oredered ways to partition integer n, using only odd numbers

We're going to solve this problem using dp

notice that in coin change, to find the number of ordered ways we can use to form coin i, the transition is simply

dp[i] = dp[i-coin1] + dp[i-coin2] ....

for this problem, it's simply

dp[i] = dp[i-1] + dp[i-3] + dp[i-5]

But if we are to do this in a naive dp approach, we would end up having O(N^2) time complexity and N states, now take a look at this very important observation

dp[1] = dp[0]
dp[3] = dp[2] + dp[0]
dp[5] = dp[4] + dp[2] + dp[0]

Note that dp[1], dp[3], dp[5] takes in the same even indexed dp value, we could totally avoid this with prefix sum. Where we only need to keep track of the sum of odd indexed state, and sum of even indexed state. Try to visualise it, you will see that we could do this with prefix sum.

The other way to think of it is

dp[3] = dp[2] + dp[0]
dp[5] = dp[4] + dp[2] + dp[0] -> dp[4] + dp[3]

which is fibonacci sequence
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

const int MOD = 998244353;

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n,p/2);
    sq = (sq * sq) % MOD;
    if (p%2){
        return (sq*n) % MOD;
    }
    return sq;
}

void solve(){
    int n;
    cin >> n;
    vi dp(n+1);
    //{even sum, odd sum}
    pi sm{1,0};

    for(int i{1}; i <= n; i++){
    	//If i is odd, take even sum, otherwise, odd sum
        dp[i] = (i%2 ? sm.fir: sm.sec);
        //if i is odd, add the value of dp[i] to it's corresponding sum , even/odd
        (i%2 ? sm.sec : sm.fir) = ((i%2 ? sm.sec : sm.fir) + dp[i]) % MOD;
    }
    cout << (dp[n] * modpow(modpow(2,n),MOD-2)) % MOD;
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