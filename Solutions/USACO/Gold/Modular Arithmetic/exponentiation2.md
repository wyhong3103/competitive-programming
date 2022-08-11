Took me a while to realize what I was doing wrong. So basically, notice that in all modular arithmetic identities/ theorem etc, we never really uses mod on the power, because it doesn't work that way, you cannot simply apply MOD on the power. Except for Fermat's Theorem, we need to apply MOD-1 as the modulus (given MOD is a prime number) to the power, and MOD to the entire number.
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

ll modpow(ll x, ll n, ll MOD){
    if (n == 0) return 1;
    ll sq = modpow(x, n/2, MOD) % MOD;
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
        ll a, b, c;
        cin >> a >> b >> c;
        
        cout << modpow(a, modpow(b,c,MOD-1), MOD) << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```