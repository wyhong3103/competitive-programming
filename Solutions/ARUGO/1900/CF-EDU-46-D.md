The idea of solving this problem is with a little dp and combinatorics

```
Dp state = i-th position
Dp value = number of good arrays so far at i (does not necessarily ends at i, just the total good arrays that is before i and at i)

The final answer is simply dp[n-1]

First let's talk about how many ways can we form a good array that starts from i, length of the good array is simply a[i]+1, and obviously the end point of the good arrays can be x, i+a[i] <= x <= n-1, 

From i to x of its good array, there is (x-i-1) choose (a[i]-1) ways to form the good array, because it can be a subsequence so literally, say a[i] = 2, and the length = 2+1 = 3

i _ _ _ _ _ _ _ x

x-i-1 because we only need to choose from the elements between x and i, and we need to choose len-2 (because we already set x and i) and elements. And that gives us the number of arrays we can form that starts at i and ends at x.

Next thing we do is add the value to dp[x] (without pairing up with previous good arrays), and then add dp[x] with dp[x] * dp[i-1], because that is the number of ways we can pair up with previous good arrays. (product rules)
```

```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MOD = 998244353;
const int MAX = 1e3 + 5;
//dp value = number of good sequences that ends at i
ll dp[MAX];
ll pascal[MAX][MAX];

void gen_pascal(){
    pascal[0][0] = 1;
    for(int i{1}; i < MAX;  i++){
        for(int j{}; j < MAX; j++){
            if (!j){
                pascal[i][j] = 1;
                continue;
            }
            pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1]) % MOD;
        }
    }
}
 

void solve(){
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    for(auto& i : a) cin >> i;

    for(ll i{}; i < n; i++){
        if (a[i] <= 0 || i+a[i] >= n) continue;
        vector<ll> prefix(n);
        for(ll j{i+(a[i])}; j < n; j++){
            prefix[j] = pascal[j-i-1][a[i]-1];
            prefix[j] = (prefix[j] + (!j ? 0 : prefix[j-1])) % MOD;
            dp[j] = (dp[j] + prefix[j]) % MOD;
            dp[j] = (dp[j] + ((prefix[j] * (!i ? 0 : dp[i-1])) % MOD)) % MOD;
        }
    } 

    cout << dp[n-1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    gen_pascal();
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```