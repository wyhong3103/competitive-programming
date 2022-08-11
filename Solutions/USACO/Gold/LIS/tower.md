We're essentially looking for minimal number of decreasing subsequences that would cover the array, and this is quite similar to what we did in pcb. Minimal number of decreasing sequences (chain) = length of longest non-decreasing sequences (antichain), this can be proved by Dilworth's Theorem. 
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

 
void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    vi dp(n+1);
    fill(all(dp), INT_MAX);
    dp[0] = -dp[0];

    for(int i{}; i < n; i++){
        int at = upper_bound(all(dp), a[i]) - dp.begin();
        dp[at] = a[i];
    }

    int mx = 0;
    for(int i{}; i <= n; i++){
        if (dp[i] != INT_MAX) mx=  max(i, mx);
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