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
    ll n, m, t;
    cin >> n >> m >> t;
 
    vll a(n-1);
    for(auto& i :a) cin >> i;
 
    vll bonus(n);
    while (m--){
        ll x, y;
        cin >> x >> y;
        x--;
        bonus[x] = y;
    }
 
    bool ok = 1;
    ll cur = 0;
    for(int i{}; i < n-1; i++){
        t += bonus[i];
        cur += a[i];
        if (cur >= t){
            ok = 0;
            break;
        }
    }
 
    cout << (ok ? "Yes" : "No");
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