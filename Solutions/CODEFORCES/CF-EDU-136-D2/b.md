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
 
    vi d(n);
    for(auto& i : d) cin >> i;
 
    vi a(n);
    a[0] = d[0];
 
    bool ok = 1;
    for(int i{1}; i < n; i++){
        int x = d[i]+a[i-1];
        int y = -(d[i]-a[i-1]);
        if (x != y && x >= 0 && y >= 0){
            ok = 0;
        }
        if (x >= 0) a[i] = x;
        if (y >= 0) a[i] = y;
    }
    if (ok){
        for(auto& i : a) cout << i << ' ';
    }else cout << -1;
    cout << '\n';
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