This problem isn't just about finding binomial coefficient that easy. It requires a few techniques, like precomputation of factorial, custom power function, so that we could perform modular arithmetic in there, also Euler's theorem, on Modular Multiplicative Inverse, where a % mod / b % mod is actually equal to (a % mod) * power(b, mod-2), given that mod is a prime number. A pretty good problem overall, only if you know the math and techniques.

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()

using namespace std;
using vi = vector<int>;
using ll = long long;

void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


const int MAX = 1000000;
const ll MOD = 1e9+7;
ll factorial[MAX];

void generate(){
    factorial[0] = 1;
    for(int i{1}; i <= MAX; i++){
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

ll power(ll a, ll b){
    if (b == 1) return a;
    ll sq = power(a, b/2);
    sq = (((sq % MOD) * (sq % MOD)) % MOD);
    if (b % 2 != 0){
        return (sq * a) % MOD;
    }
    return sq;
}


void solve(){
    int t;
    cin >> t;
    generate();
    while (t--){
        int n, r;
        cin >> n >> r;
        // (n! / (n-r)!) /(r)!
        cout << ((((factorial[n] * power(factorial[n-r], MOD-2)) % MOD) * power(factorial[r],MOD-2)) % MOD) << '\n';
    }
}


int main(){
    //setio("t");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```