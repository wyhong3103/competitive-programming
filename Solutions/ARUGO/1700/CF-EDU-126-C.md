```

The final height isn't necessarily the tallest height, but it's either tallest height or tallest height+1.

This is one the case where it matters

7
1 1 1 1 1 1 2

One would give 11, and another one would give 9

To solve this, we can binary search the answer, since with a given day, it's either we used all of the water, or we skip some.

The idae is to binary search the number of days, and greedily fill all the days with water with height 2 floor(day/2), and then see if we can fill the remaining with water with height 1 ceil(day/2)

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

bool valid(ll height, ll day, vll& a){
    ll cnt1 = ceil(day/2.0), cnt2 = day/2;
    ll remaining = 0;
    for(auto& i : a){
        ll diff = height-i;
        remaining += diff - (min(cnt2,diff/2)*2);
        cnt2 -= min(cnt2, diff/2);
    }
    return (cnt1 >= remaining);
}
 
void solve(){
    int n;
    cin >> n;

    vll a(n);
    for(auto& i :a) cin >> i;

    ll mx =0;
    for(auto& i :a) mx = max(i, mx);

    ll lo = 0, hi = LONG_LONG_MAX;
    while (hi > lo){
        ll mid = lo + (hi-lo)/2;   
        if (valid(mx, mid, a) || valid(mx+1, mid, a)){
            hi = mid;
        }else lo = mid+1;
    }
    cout << lo << '\n';
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