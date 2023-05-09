```

Let's first see why is the number on the cell [i,j] is C[i+j][i]

Note that we start at (0,0) and each time we can only go down and right, each cell [i,j] essentially represents the number of ways to reach with i+j moves s.t i of them needs to be arrow down.

But how do we find the answer?

Say the height of the white cell in current column j is n, the total for current column j is

a[0][j] * n + a[1][j] * n-1 + ... + a[n-1][j]

Beacuse the idea is the total in the row i need to do n-i moves to get out of the white cells

but we can't count like this, as it will TLE

After observing the pattern of each cell, it's now hard to see that, each cell in col j+1, is the prefix sum of the previous column from [0,i], and each cell in col j+2 is the prefix sum of the prefix sum of column j [0,i]

Why does the above matter?

a[0][j] * n + a[1][j] * n-1 + ... + a[n-1][j]

First let's notice the prefix sum of a[0][j], a[1][j]... first

prefix sum row 1 : a[0][j]
prefix sum row 2 : a[0][j], a[1][j]
prefix sum row 3 : a[0][j], a[1][j], a[2][j]

Notice that if we sum all the prefix sum, we're essentially getting

a[0][j] * n + a[1][j] * n-1 + ... + a[n-1][j]

```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MX = 5e5 + 5;
const int MOD = 1e9 + 7;
ll fact[MX];
 
 
void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = ( sq * sq ) %MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}
 
ll ncr(ll n, ll r){
    return (fact[n] * modpow((fact[n-r] * fact[r]) % MOD,MOD-2)) % MOD;
}
 
void solve(){
    int n;
    cin >> n;
    n++;
 
    gen_fact();
    vi a(n);
    for(auto& i : a) cin >> i;
 
    ll total = 0;
    for(int i{}; i < n; i++){
        if (a[i] > 0) total = i+1;
    }
 
    for(int i{2}; i <= a[0]; i++){
        int lo = 0, hi = n-1;
        while (hi > lo){
            int mid = lo + (hi-lo+1)/2;
            if (a[mid] >= i) lo = mid;
            else hi = mid-1;
        }
        total = (total + ncr(lo+i, i)) %MOD;
    }
    cout << total;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
 //   cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```