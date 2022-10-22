```

s = n - floor(n/10)

Binary search the lower bound of n, the bigger the n, the bigger the s, eventually we will meet s.

To find the next number that will spit the same answer, we can simply iterate from the lower bound to lower_bound to ~ 20, if it has ~10 more, the answer will change! so it's within the range.

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
    ll n;
    cin >> n;
 
    ll lo = 1, hi = n*10;
    while (hi > lo){
        ll mid = lo + (hi-lo)/2; 
        if (mid - (mid/10) >= n) hi = mid;
        else lo = mid+1;
    }
    cout << lo << ' ';
    for(ll i{lo+1}; i <= lo+20; i++){
        if (i- (i/10) == n) cout << i << ' ';
    }
    cout << '\n';
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