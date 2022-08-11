A very simple problem.
```
First we sort the array, then for each i, we look for the element that is no bigger than a[i]+k, then simply do nCr on it. One thing to take note is we shouldn't consider the element i in the combinations, because it's always going to be in the tuple , otherwise, we're going to doublecount.

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

 
const int MOD = 1e9+7;
 
ll modpow(ll n,ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
 
    if (p%2) return (sq * n) % MOD;
    return sq;
}
 
ll ncr(ll n, ll r){
    ll num = 1;
    for(ll i{n}; i > n-r; i--){
        num = (num * i) % MOD;
    }
 
    ll denom = 1;
    for(ll i{1}; i <= r; i++){
        denom = (denom * i) % MOD;
    }
 
    return (num * modpow(denom, MOD-2)) % MOD;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    
    vi a(n);
    for(auto& i : a) cin >> i;

    sort(all(a));


    ll res = 0;
    for(int i{}; i < n; i++){
        int to = upper_bound(all(a), a[i]+k) - a.begin() - 1;
        if (to < 0 || to-i+1 < m){
            continue;
        }else{
            res = (res + ncr(to-i, m-1)) % MOD;
        }
    }

    cout << res << '\n';
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
```