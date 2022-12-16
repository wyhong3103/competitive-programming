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
    vector<pll> a(n);
    for(int i{}; i < n ; i++){
        cin >> a[i].fir;
        a[i].sec = i+1;
    }
    
    sort(all(a));
 
 
    vector<pll> res;
    for(int i{1}; i < n; i++){
        ll val = a[i-1].fir - (a[i].fir % a[i-1].fir);
        res.pb({a[i].sec, val});
        a[i].fir += val;
    }
 
    cout << sz(res) << '\n';
    for(auto& i : res) cout << i.fir << ' ' << i.sec << '\n';
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