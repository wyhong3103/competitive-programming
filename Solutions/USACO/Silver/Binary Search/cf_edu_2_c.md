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
    ll n, x, y;
    cin >> n >> x >> y;

    ll cur = min(x, y);

    auto good = [&](ll mid){
        return (mid/x) + (mid/y) >= n-1;
    };

    ll lo = 0, hi = LONG_LONG_MAX;
    while (hi > lo){
        ll mid = lo + (hi-lo)/2;
        if (good(mid)){
            hi = mid;
        }else lo = mid+1;
    }
    cout << cur+lo;
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