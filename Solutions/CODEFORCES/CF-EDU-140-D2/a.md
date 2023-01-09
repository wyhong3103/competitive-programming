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
    vector<pi> a(3);
    for(auto& i : a) cin >> i.fir >> i.sec;
 
    bool ok = 1;
    for(int i{}; i < 3; i++){
        pi found;
        for(int j{}; j < 3; j++){
            if (i == j) continue;
            if (a[j].fir == a[i].fir) found.fir = 1;
            if (a[j].sec == a[i].sec) found.sec = 1;
        }
        ok &= !(found.fir && found.sec);
    }
    cout << (ok ? "YES" : "NO") << '\n';
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