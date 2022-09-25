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
 
     ll mn = LONG_LONG_MAX;
     for(int i{}; i <= n-3 ; i++){
        mn = min(abs(a[i+1]-a[i]) + abs(a[i+2]-a[i+1]), mn);
     }
 
     cout << mn << '\n';
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