```
dp[l][r] = minimum number of seconds needed to clear subarray [l:r]


transition =

for each i, l <= i <= r

if a[l] == a[i] && l != i:

dp[l][r] = min(dp[l][r], dp[l+1][i-1] + dp[i+1][r] + (1 if l+1 = i))  

We need to +1 if l+1 == i because when i > l, dp value doesn't exist

else:

dp[l][r] = min(dp[l][r], dp[l][i]+dp[i+1][r])


Base case = dp[i][i] = 1, 0 <= i < n


So why is this?

Notice that if a[l] == a[j], then subarray[l:j] can be a palindrome, in fact it is a palindrome if it's interval has been cleared. Also, notice that we do not need to + 1, you might be tempted to think that it'a new palindrome formed so we need to +1, but this is not the case. Notice that 

If the interval is a palindrome, a[l] and a[j] can be removed at the same second. And this is the case.

For example,

a d b c b a

a[0] == a[n-1], although the interval is not a palindrome, but it can be (after removing 'd'). It can be proven that there will always be a palindrome in the interval unless its empty (that's when we need to + 1). Because we can always leave a single character inside in order for it to be a palindrome.

in the case above, 

d b c b 

b c b / d can be removed, and it will be come a palindrome.

And finally the answer is dp[0][n-1]
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

    vi a(n);
    for(auto& i : a) cin >> i;

    vector<vi> dp(n+1, vi (n+1));
    
    for(int i{}; i < n; i++){
        dp[i][i] = 1;
    }
    
    for(int i{2}; i <= n; i++){
        for(int j{};j <= n-i; j++){
            dp[j][j+i-1] = n;
            for(int k{j}; k < j+i; k++){
                if (j != k && a[j] == a[k]){
                    dp[j][j+i-1] = min(dp[j][j+i-1], (j+1 == k ? 1 : dp[j+1][k-1]) + dp[k+1][j+i-1]);
                }else{
                    dp[j][j+i-1] = min(dp[j][j+i-1], dp[j][k] + dp[k+1][j+i-1]);
                }
            }
        }
    }

    cout << dp[0][n-1];
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