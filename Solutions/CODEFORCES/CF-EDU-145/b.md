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
    ll n;
    cin >> n;
 
    if (n == 1){
        cout << 0 << '\n';
        return;
    }
 
    ll lo = 1, hi = 1e10;
    while (hi > lo){
        ll mid = lo + (hi-lo)/2;
        if (mid * (mid + 1) + mid + 1 >= n){
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