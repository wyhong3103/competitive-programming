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
    int n;
    cin >> n;
 
    vi a(n), b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
 
    int p = -1;
    for(int i{}; i < n; i++){
        if (a[i] != b[i]) p = i;
    }
 
    int l = p, r = p;
    for(int i{p+1}; i < n; i++){
        if (b[i] >= b[i-1]) r = i;
        else break;
    }
 
    for(int i{p}; i >= 1; i--){
        if (b[i] >= b[i-1]) l = i-1;
        else break;
    }
 
    cout << l+1 << ' ' << r+1 << '\n';
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