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
 
    pll x{0, INT_MAX};
 
    bool ok = 1;
 
    for(int i{1}; i < n; i++){
        if (a[i] > a[i-1]){
            ll lo = a[i-1], hi = a[i];
            while (hi > lo){
                ll mid = lo + (hi-lo+1)/2;
                if (abs(mid-a[i]) >= abs(mid-a[i-1])){
                    lo = mid; 
                }else hi = mid-1;
            }
 
            if (min(x.sec, hi) - x.fir < 0){
                ok = 0;
            }else{
                x.sec = min(x.sec, hi);
            }
        }else if (a[i] < a[i-1]){
            ll lo = a[i], hi = a[i-1];
            while (hi > lo){
                ll mid = lo + (hi-lo)/2;
                if (abs(mid-a[i]) >= abs(mid-a[i-1])){
                    hi = mid;
                }else lo = mid+1;
            }
 
            if (x.sec - max(x.fir, lo) < 0){
                ok = 0;
            }else{
                x.fir = max(x.fir, lo);
            }
        }
    }
 
    cout << (ok ? x.fir : -1) << '\n';
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