```

I have overcomplicated this problem! We can simply generate a sequence based on LCM and then verify it.

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
 
ll gcd(ll a, ll b){
    return (!b ? a : gcd(b, a % b));
} 
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
 
    bool ok = 1;
 
    vi b(n+1);
    b[0] = a[0];
    for(int i{1}; i < n; i++){
        b[i] = lcm(a[i], a[i-1]);
    }
    b[n] = a[n-1];
 
    for(int i{}; i < n; i++){
        if (a[i] != gcd(b[i], b[i+1])) ok = 0;
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