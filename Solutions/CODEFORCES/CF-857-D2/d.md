```

Sort the ai, bi, and then we start iterating from the smallest ai.

If we are to take ai, then we take any aj before ai, cus aj < ai, and we only care about the maximum we take.

If we are to take ai, one potential maximal b is simply the suffix maximum from n-1 to j, j = i+1.

Or, from 0 to i-1, we can take one of the b[j], if it is bigger than the suffix maximum then we can consider it.
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
    int n;
    cin >> n;
 
    vector<pll> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;
 
    sort(all(a));
    
    vll mx(n);
    for(int i{n-1}; i >= 0; i--){
        mx[i] = a[i].sec;
        if (i < n-1) mx[i] = max(mx[i], mx[i+1]);
    }
 
    ll mn = LONG_LONG_MAX;
    set<ll> pf;
    for(int i{}; i < n; i++){
        if (!i){
           mn = min(mn, abs(a[i].fir - mx[i+1]));
        }else{
            
            ll l = LONG_LONG_MAX, r = LONG_LONG_MAX;
 
            if (pf.lower_bound(a[i].fir) != pf.end()){
                r = *pf.lower_bound(a[i].fir);
            }
 
            if (pf.lower_bound(a[i].fir) != pf.begin()){
                l = *(--pf.lower_bound(a[i].fir));
            }
 
 
            mn = min(mn, (i == n-1 ? LONG_LONG_MAX : abs(a[i].fir - mx[i+1])));
            
            if (i == n-1 || r >= mx[i+1]){
                mn = min(mn, abs(r-a[i].fir));
            }
 
            if (i == n-1 || l >= mx[i+1]){
                mn = min(mn, abs(l-a[i].fir));
            }
        }
 
        pf.insert(a[i].sec);
    }
    cout << mn << '\n';
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