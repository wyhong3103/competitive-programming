```
Let's generalize this problem a little bit.

First of all, we're to find the minimum number of lanes we needd so that during the run, the cows don't collide with each other. In order to fulfil the condition, cow i cannot get past cow j, such that j > i. 

Now this is pretty obvious, basically we're to find the minimum number of LIS needed to cover the entire sequence, and now this is equivalence to the length of longest non-increasing subsequence.

To do this,  we can get the final position of every cow, and start finding the longest non-increasing subsequence.
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

 
void solve(){
    ll n, t;
    cin >> n >> t;

    vll a(n);
    for(int i{}; i < n; i++){
        ll at, s;
        cin >> at >> s;
        a[i] = at + (s*t);
    }

    vll dp(n+1);
    fill(all(dp), -INT_MAX);
    dp[0] = -dp[0];

    for(int i{}; i < n; i++){
        int lo = 0, hi = n-1;
        while (hi > lo){
            int mid = lo + (hi-lo+1)/2;
            if (dp[mid] >= a[i]){
                lo = mid;
            }else hi = mid-1;
        }
        dp[lo+1] = a[i];
    }

    int mx = 0;
    for(int i{}; i <= n; i++){
        if (dp[i] != -INT_MAX) mx = max(i, mx);
    }

    cout << mx;
}

int main(){
    setio("cowjog");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```