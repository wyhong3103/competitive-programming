LIS in O(n log n).
```
DP + Binary Search

dp state = length of LIS
dp value = smallest element that ends at i-th length

Initialize dp[1....n] = inf, and dp[0] = -inf

The idea goes like this

Notice that if i > j, dp[i] > dp[j]

Notice that this is all the information we need to binary search, 

The optimal placement of a[i] is dp[j+1], where j is the element that is smaller than a[i] and is the maximal amongst all, and we only replace dp[j+1] if a[i] < dp[j+1]

The reason why i > j and dp[i] > dp[j], is because 

if dp[j] > dp[i], it would never be in an sequence that its length is smaller than i, but bigger than i. Although it could be, but why would we as it is not an optimal move. As the optimal move is to store the smallest element at i, because that's how we can optimally create an LIS.

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
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    vi dp(n+1);
    fill(all(dp), INT_MAX);
    dp[0] = -dp[0];

    for(int i{}; i < n ; i++){
        int lo = 0, hi = n-1;
        while (hi > lo){
            int mid = lo + (hi-lo+1)/2;
            if (a[i] > dp[mid]){
                lo = mid;
            }else hi = mid-1;
        }
        if (dp[lo+1] > a[i]) dp[lo+1] = a[i];
    }
    int mx = 0;
    for(int i{1}; i <= n; i++){
        if (dp[i] != INT_MAX) mx = max(mx, i);
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