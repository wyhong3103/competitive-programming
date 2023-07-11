Play with the operations for a while, you will realize that you will always only be able to merge element with the same parity. So the answer is just $max(\text{max sum of subset of even indexed element}, \text{max sum of subset of odd indexed element})$. If none of the element is positive, the answer is the maximal element.

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
 
    vll a(n);
    for(auto& i : a) cin >> i;
 
    ll mx = -LONG_LONG_MAX;
    for(int i{}; i<n ; i++){
        mx = max(mx, a[i]);
    }
    if (mx < 0){
        cout << mx << '\n';
        return;
    }
 
    ll sm = 0;
    for(int i{}; i < n; i+=2){
        if (a[i] > 0) sm += a[i];
    }
 
    mx = sm;
    sm = 0;
    for(int i{1}; i < n; i+=2){
        if (a[i] > 0) sm += a[i];
    }
    mx = max(mx, sm);
    cout << mx << '\n';
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