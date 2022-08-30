Tricky question, time limit is 6 seconds, didn't notice that.
```

I initially did a simple binary search on the sorted rectangles but it doesn't work. 


Say we got

{2,3}, {2,4}, {3,1}, {4,5},{4,6}

And query, hs = {1,1}, hb = {10,10}

Seemingly every rectangles fit, so we could simply binary search the beginnig and the end. But no, {3,1} doesn't work.

So the idea is to split them apart, iterate through the corresponding height that fits, and then binary search on the width, with prefix sum.


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
    int n, q;
    cin >> n >> q;
 
    vector<vi> a(1001);
    for(int i{}; i < n; i++){
        pi r;
        cin >> r.fir >> r.sec;
        a[r.fir].pb(r.sec);
    }
    for(int i{}; i < 1001; i++){
        sort(all(a[i]));
    }
 
    vector<vll> prefix(1001);
    for(int i{1}; i < 1001; i++){
        ll sm = 0;
        for(auto& j : a[i]){
            sm += j * i;
            prefix[i].pb(sm);
        }
    }
 
    while(q--){
        pi hs, hb;
        cin >> hs.fir >> hs.sec >> hb.fir >> hb.sec;
 
        ll sm = 0;
        for(int i{hs.fir+1}; i < hb.fir; i++){
            if (!sz(a[i])) continue;
 
            int lo = 0, hi = sz(a[i])-1;
            while ( hi > lo){
                int mid = lo + (hi-lo)/2;
                if (a[i][mid] > hs.sec){
                    hi = mid;
                }else lo = mid+1;
            }
            int f = lo;
 
            lo = 0, hi = sz(a[i])-1;
            while ( hi > lo){
                int mid = lo + (hi-lo+1)/2;
                if (a[i][mid] < hb.sec){
                    lo = mid;
                }else hi = mid-1;
            }
            
            int t = lo;
            if (f <= t && a[i][f] > hs.sec && a[i][t] < hb.sec){
                sm += prefix[i][t]-(!f ? 0 : prefix[i][f-1]);
            }
        }
        cout << sm << '\n';
    }
 
 
 
 
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