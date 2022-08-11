The idea is fairly simple.
```
AAABC

We simply have to consider having indistinguishable objects.

So instead of taking n! to find the number of different strings, we need to consider that.

number of different strings that can be formed using the characters given is , 5C3 * 2C1 * 1C1, 

Because we can choose any 3 posiitons from the 5 positions as A, after choosing those, we only left with 2 positions, and 2 for B, and the last one 1 for C

and the number of ways to arrange them is simply the multiplication of them. (Product Rule)

More specifically, it can be n! / n1! * n2! * n3!

This is because we have n! permutations of the characters, and we divide those order that are repeated.
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
    string s;
    cin >> s;
    
    vi c(26);
    for(auto& i : s){
        c[i-'a']++;
    }

    int cur = sz(s);

    ll res = 1;
    for(auto& i : c){
        res = (res * ncr(cur,i)) % MOD;
        cur -= i;
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