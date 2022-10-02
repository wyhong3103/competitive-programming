```
There is no need to change the minimum at all! I guess it came from the idea that if we ever need to change the minimum, that means we need extra divide, but a better thing we can do is to divide it more time.

Just divide every element into k pieces and then make sure it's lower than <= min * 2.

We need binary search to know how much time do we need to divide.

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
 
    sort(all(a));
 
    ll total = 0;
    for(int i{1}; i < n; i++){
        ll lo = 1, hi = a[i];
        while (hi > lo){
            ll mid = lo + (hi-lo)/2;
            if ((a[i]/mid) + (a[i] % mid ? 1 : 0) >= a[0]*2){
                lo = mid+1;
            }else hi = mid;
        }
        total += lo-1;
    }
    cout << total << '\n';
    
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