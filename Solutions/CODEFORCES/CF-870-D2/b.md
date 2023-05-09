```

In order for a[i] and a[n-i] to have the same remainder means the number can be represented as 

ax + b, cx + b

we can easily see that difference between a[i] and a[n-i] is just abs(ax-cx) = m * x

From the outest number to the innest, the one inside should correspond to the range of the one outside, so we find the gcd of them, at the end, the answer is just the gcd
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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
ll gcd(ll a, ll b){
    return (!b ? a :gcd(b, a % b));
}
 
void solve(){
    int n;
    cin >> n;
    vll a(n);
    for(auto& i :a) cin >> i;
 
    ll g = abs(a[0]-a[n-1]);
    for(int i{}; i < n/2; i++){
        g = gcd(g, abs(a[i]-a[n-i-1]));
    }
    
    cout << g << '\n';
    
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