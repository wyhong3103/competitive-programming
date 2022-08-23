This is a pretty interesting problem.
```
So basically, we will have to do range DP on both whether the string is a palindrome, and the number of palindromes in that subarray.

For the first part, where we have to check if a substring is a palindrome, it takes O(N^2) to check, rather than naive appraoch which takes O(N^3)

for each subarray, if s[l] == s[r] and dp_palindrome[l+1][r-1] is a palindrome, then it's a palindrome

For the second part,

Number of palindromes in that subarray is equal to

dp[l][r] = dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1]

Because each dp arary already consist of its own number of palindrome substring, direct addition will cause double counting. So we will have to do a little combinatorics over here, which is PIE. 

dp[l][r] += 1, if substring[l][r] is a palindrome
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
    string s;
    cin >> s;

    int n = sz(s);

    vector<vll> dp(n, vll (n));
    vector<vector<bool>> dp_palindrome(n, vector<bool> (n));
    for(int i{}; i < n; i++){
        dp[i][i] = 1;
        dp_palindrome[i][i] = 1;
    }

    for(int i{2}; i <= n; i++){
        for(int j{}; j <= n-i; j++){
            if (s[j] == s[j+i-1] && ((j+1 <= j+i-2 && dp_palindrome[j+1][j+i-2]) || j+1 > j+i-2)){
                dp_palindrome[j][j+i-1] = 1;
            }
        }
    }

    for(int i{2}; i <= n; i++){
        for(int j{}; j <= n-i; j++){
            dp[j][j+i-1] = dp[j][j+i-2] + dp[j+1][j+i-1] - dp[j+1][j+i-2];
            dp[j][j+i-1] += dp_palindrome[j][j+i-1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        cout << dp[l][r] << '\n';
    }
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