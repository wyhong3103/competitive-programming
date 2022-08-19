A really silly problem.
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
    return (!b ? a : gcd(b, a%b));
}
 
void solve(){
   ll a, b, c, d;
   cin >> a >> b >> c >> d;
 
    ll x = gcd(a,b);
    ll y = gcd(c,d);
 
    a /= x;
    b /= x;
    c /= y;
    d /= y;
 
    if (a == c && b == d) cout << 0 << '\n';
    else if (!a || !c) cout << 1 << '\n';
    else if ((a * d) % (b * c) == 0 || (b*c)%(a*d) == 0) cout << 1 << '\n';
    else if (a == c && max(b,d) % min(b,d) == 0) cout << 1 << '\n';
    else if (b == d && max(a,c) % min(a,c) == 0) cout << 1 << '\n';
    else cout << 2 << '\n';
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