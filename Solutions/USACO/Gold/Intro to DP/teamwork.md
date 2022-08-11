This is actually a very similar problem we did before (Barcode).
```
The state is the i-th cow, dp[i] stores the maximum value if our team were to end at i-th cow

Transition : dp[i+j] = max(dp[i+j], dp[i-1] (if i > 0) + (maximum * (j+1)), 0 <= j <= k
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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MXN = 1e4+1;
ll dp[MXN];

void solve(){
    int n, k;
    cin >> n >> k;

    vi a(n);
    for(auto& i : a) cin >> i;
    
    for(int i{}; i < n; i++){
        int mx = 0;
        for(int j{}; j < min(n-i, k); j++){
            mx = max(a[i+j], mx);
            dp[i+j] = max(dp[i+j], (!i ? 0 : dp[i-1]) + (mx * (j+1)));
        }
    }

    cout << dp[n-1];
}
 
int main(){
    setio("teamwork");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```