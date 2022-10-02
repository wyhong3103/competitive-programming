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
 
    vi a(n);
    for(int i{}; i < n; i++){
        cin >> a[i];
    }
 
    vll b(n);
    for(auto& i : b) cin >> i;
 
    vll cnt1;
    vll cnt2;
    for(int i{}; i < n; i++){
        if (a[i]){
            cnt2.pb(b[i]);
        }else cnt1.pb(b[i]);
    }
    sort(all(cnt1), greater<ll>());
    sort(all(cnt2), greater<ll>());
 
    ll res = 0;
    if (sz(cnt1) == sz(cnt2)){
        for(auto& i : cnt1) res += i*2; 
        for(auto& i : cnt2) res += i*2; 
        res -= min(cnt1.back(), cnt2.back());
    }else if (sz(cnt1) > sz(cnt2)){
        for(int i{}; i < min(sz(cnt1), sz(cnt2)); i++){
            res += cnt1[i] * 2;
            res += cnt2[i] * 2;
        } 
        for(int i{sz(cnt2)}; i < sz(cnt1); i++){
            res += cnt1[i];
        }
    }else{
        for(int i{}; i < min(sz(cnt1), sz(cnt2)); i++){
            res += cnt1[i] * 2;
            res += cnt2[i] * 2;
        } 
        for(int i{sz(cnt1)}; i < sz(cnt2); i++){
            res += cnt2[i];
        }
    }
    cout << res << '\n';
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