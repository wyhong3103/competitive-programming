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

const int MXX = 1e6+1;
const int MOD = 1e9 + 7;
ll dp[MXX];

void solve(){
    int n, x;
    cin >> n >> x;

    vi a(n);
    for(auto& i : a) cin >> i;

    dp[0] = 1;
    for(int i{1}; i <= x; i++){
        for(auto& c : a){
            if (i-c >= 0){
                dp[i] = (dp[i] + dp[i-c]) % MOD;
            }
        }
    }

    cout << dp[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```