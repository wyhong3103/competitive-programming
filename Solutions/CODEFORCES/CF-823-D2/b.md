```

This problem can be bitonic/monotonic, depends on how you look at it.


Bitonic - ternary search on the location

Monotonic - binary search on the min time needed

So basically, min time needed is the maximum of (abs(xi-x) + ti) across all i.

time >= abs(x[i]-x) + t[i]

We basically need to find the least time that fulfil the above condition then with the least time we can tell where it is located.

With time, x[i], time, t[i] how do know if there exist an x that fulfil the condition?

Let's rearrange the equility

time >= abs(x[i]-x) + t[i]

time >= (x[i]-x) + t[i] ,  time >= -(x[i]-x) + t[i]

time - t[i] - x[i] >= -x , time >= -x[i] + x + t[i]

time - t[i] - x[i] >= -x , time >= -x[i] + x + t[i]

- time + t[i] + x[i] <= x, time + x[i] - t[i] >= x

- time + t[i] + x[i] <= x <= time + x[i] - t[i] 

With the above equation, we know the range of every possible X for i.

By doing a rectangular intersection trick across all i, if the final area is non-negative, that mean there exist an x for all i.
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
    int n;
    cin >> n;
 
    vll a(n);
    for(auto& i : a) cin >> i;
 
    vll t(n);
    for(auto& i : t) cin >> i;
 
    auto good = [&](long double ti){
        long double cur_l = 0;
        long double cur_r = 1e12;
        for(int i{}; i < n; i++){
            long double l = a[i]-ti+t[i];
            long double r = ti-t[i]+a[i];
            cur_l = max(cur_l, l);
            cur_r = min(cur_r, r);
        }
 
        return cur_r-cur_l >= 0;
    };
 
    long double lo = 0, hi = 1e12;
    for(int i{}; i < 120; i++){
        long double mid = lo + (hi-lo)/2; 
        if (good(mid)) hi = mid;
        else lo = mid;
    }
 
    long double cur_l = 0;
    long double cur_r = 1e12;
    for(int i{}; i < n; i++){
        long double l = a[i]-lo+t[i];
        long double r = lo-t[i]+a[i];
        cur_l = max(cur_l, l);
        cur_r = min(cur_r, r);
    }
 
    cout << setprecision(8) << fixed;
    cout << cur_l << '\n';
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