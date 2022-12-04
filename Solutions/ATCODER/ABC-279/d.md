```

Try the graph x*b + a/(sqrt(x+1)) on desmos, it's a unimodal function.

Ternary search to find the lowest y we could get.

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    ll a, b;
    cin >> a >> b;
 
    auto compute = [&](ll x){
        return (x*b) + (a/(long double)sqrt(x+1));
    };
 
    ll lo = 0, hi = ceil(a/b);
    long double res = a;
    while(hi-lo > 3){
        ll m1 = lo + ((hi-lo)/3);
        ll m2 = hi - ((hi-lo)/3);
        if (fabs(compute(m1)-compute(m2)) < EPS){
            lo = m1;
            hi = m2;
        }
        else if (compute(m1) > compute(m2)) {
            lo = m1; 
        }else{
            hi = m2;
        }
    }
 
 
    for(ll i{lo}; i <= hi; i++){
        res = min(res, compute(i));
    }
    cout << setprecision(10) << fixed;
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