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
 

const int MOD = 1e9 + 7;

ll modpow(ll x, ll n){
    if (n == 0) return 1;
    ll sq = modpow(x, n/2) % MOD;
    sq = (((sq % MOD) * (sq % MOD)) % MOD);
    if (n % 2 != 0){
        sq = (sq * x) % MOD;
    }
    return sq;
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        cout << modpow(a, b) << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```