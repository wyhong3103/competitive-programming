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
int n;
vi a;

void solve(){
    cin >> n;
    a.resize(n);
    for(auto& i : a) cin >> i;

    dp[0] = 0;
    dp[1] = abs(a[1]-a[0]);

    for(int i{2}; i < n; i++){
        dp[i] = min(abs(a[i]-a[i-1]) + dp[i-1], abs(a[i]-a[i-2]) + dp[i-2]);
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