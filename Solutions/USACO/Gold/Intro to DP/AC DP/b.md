This problem is the extension of the last problem, I think I am really starting to get the hang of DP. The idea of DP is literally not to do some overlapping subproblems, and about identifying the states and transition. In this problem, it doesn't really matter how we reach a certain state, all we're interested in, is the cost we need to reach i-th state. So the state will be the position.
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
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MAX = 1e5 + 5;
int dp[MAX];

void solve(){
    int n, k;
    cin >> n >> k;

    vi a(n);
    for(auto& i : a) cin >> i;

    for(int i{}; i < k; i++){
        dp[i] = abs(a[i] - a[0]);
    }

    for(int i{k}; i < n; i++){
        dp[i] = INT_MAX;
        for(int j{1}; j <= k; j++){
            dp[i] = min(dp[i], abs(a[i]-a[i-j]) + dp[i-j]);
        }
    }

    cout << dp[n-1];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```