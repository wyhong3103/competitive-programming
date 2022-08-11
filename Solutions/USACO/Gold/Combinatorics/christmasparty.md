```
Find the number of arrangements such that i-th element cannot be at i positions

To find the number of ways to arrange this, we can use PIE

Say n = 4, and let's denote the array as a,b,c,d

Number of way to arrange it is simply

4! - 3! (a) - 3! (b) - 3! (c) - 3! (d) + 2! (ab) + 2! (ac) + 2! (ad) + 2! (c) + 2!(bd) + 2! (cd) - 1 (abc) - 1 (abd) - 1 (acd) - 1 (bcd) + 1 (abcd)

The idea is to prevent overcounting, because when we subtract number of arrangements when we fixed a, it involved ab,ac,ad,abc,abd,acd,bcd, abcd as well. That's why PIE would work here.

To make it work, we need to precompute factorial, and also nCr, the only reason we can precompute ncr is because n is fixed. We use ncr to find the number of subsets such that the size is k , 1 <= k <= n
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
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;
ll factorial[MAX];
ll ncr[MAX];

void gen_fact(){
    factorial[0] = 1;
    for(int i{1}; i <= MAX; i++){
        factorial[i] = (i * factorial[i-1]) % MOD;
    }
}

ll modpow(ll n,ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
 
    if (p%2) return (sq * n) % MOD;
    return sq;
}
 
void gen_ncr(int n){
    ll num = 1;
    for(int i{n}; i >= 1; i--){
        num = (num*i) % MOD;
        ncr[n-i+1] = num;
    }

    ll denom = 1;
    for(int i{1}; i <= n; i++){
        denom = (denom*i) % MOD;
        ncr[i] = (ncr[i] * modpow(denom, MOD-2)) % MOD;
    }
}

void solve(){
    int n;
    cin >> n;

    gen_ncr(n);
    gen_fact();

    ll res = factorial[n];
    for(int i{1}; i <= n; i++){
        if (i%2){
            res = (((res - ((ncr[i]*(factorial[n-i]))%MOD)) + MOD) % MOD) % MOD;
        }else{
            res = (res + ((ncr[i]*(factorial[n-i]))%MOD)) % MOD;
        }
    }

    cout << res;
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