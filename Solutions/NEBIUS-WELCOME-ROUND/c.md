```

We need to find if there exist an i, 1 <= i <= p

such that

(i^2 + i) / 2 = (n * k) + (n - x)

Basically offset needs to be n-x, because that is how much we need to reach 0

Notice that you might be tempted to think, we only needed to try 1 <= i <= min(n,p)

That might be true for the case of i*i + i, but we're currently dealing with (i*i + i)/2, we couldn't apply it when we need to divide it by 2.

But what if we have 2n?

2*n ^ (2*n) + 2n / 2 = 2n^2 + n mod n = 0 mod n

We have a cycle here!

So we just need to try i from 1 <= i <= min(n, 2p) and see if it equals to n-x mod n


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
 
 
void solve(){
    ll n, x, p;
    cin >> n >> x >> p;
 
    bool ok = 0;
    for(ll i{1}; i <=min(p,2*n); i++){
        ok |= (((i * i + i) / 2LL) % n) == (n-x) % n;
    }
    cout << (ok ? "YES" : "NO") << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
```