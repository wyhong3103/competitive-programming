```
This dp problem is very different from the DP problems I have done in the past.

dp[i][j][k] = {every possible size of interval for j-th element as the last element of the interval when it's the k-th group and that preserve the most significant bits so far at bit 2^i}

The idea is we can store the valid size of interval that preserves the bit.

DP basecase

before the largest bit which is ~ 63

every dp[63][j][k] consist all the valid interval size.

What are the invalid intervals?

if we at position 2, and group is 3, it's not valid, because position 2 can only have at most an interval of size 2.

If we at position 4, and group is group 3, max interval size is only 2, becuase if we go larger than that, we would not have enough groups.


Transition

From the MSB to the LSB.

At the i-th bit, j-th element as the end of k-th group,

For every possible interval of the previous bit, we only remain the interval that has the sum that remain i-th bit. basically sum(a[i-interval+1:i]) & 2^i must be true. 

Repeat the same thing for every possible j,k.

If dp[i][n][k] has at least one possible interval size that can preserve the bit, that means there is a way we can construct the sum s.t i-th bit is preserve.

If not, the possible interval moves of this bit, is the same as the previous one, since we couldn't maintain this bit w/o losing the previous one.

Keep repeating until we reach the end.

It's like divide and conquer, we have x intervals that gives 2^i bit, from those interval, we find the interval that can also preserve 2^i-1 bit, so on and so forth.

At the end, we can just pick a random interval from dp[i][n][k] and simulate it to the beginnig to get the sum. It is guaranteed that all preserved bit will be preserved in the AND of sum.

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
    int n, k;
    cin >> n >> k;

    //possible moves that preserve the previous bits
    vector<vector<vi>> dp(n+5, vector<vi>(k+5));
    for(int i{1}; i <= n; i++){
        for(int j{1}; j <= min(i, k); j++){
            if (j == 1){
                dp[i][j].pb(i);
            }else{
                for(int l{1}; l <= i-j+1; l++){
                    dp[i][j].pb(l);
                }
            }
        }
    }

    vll a(n);
    for(auto& i : a) cin >> i;

    vll pref(n+1);
    for(int i{1}; i <= n; i++){
        pref[i] = a[i-1] + pref[i-1];
    }

    for(int i{63}; i >= 0; i--){
        vector<vector<vi>> dp1 (n+5, vector<vi>(k+5));
        dp1[0][0].pb(0);

        for(int j{1}; j <= n; j++){
            for(int l{1}; l <= k; l++){
                for(int x{}; x < sz(dp[j][l]); x++){

                    int dist = dp[j][l][x];
                    ll sm = pref[j] - pref[j-dist];

                    if ((sm & (1LL << i)) && sz(dp1[j-dist][l-1])){
                        dp1[j][l].pb(dist);
                    }
                }
            }
        }

        if (sz(dp1[n][k])){
            swap(dp1, dp);
        }
    }

    
    ll mx = (1LL << 63)-1;
    int group = k;
    int at = n;
    while (at != 0){
        int dist = dp[at][group][0];
        mx &= pref[at]-pref[at-dist];
        at -= dist;
        group--;
    }

    cout << mx;
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