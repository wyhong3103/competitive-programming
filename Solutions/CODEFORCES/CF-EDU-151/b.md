```

Maximal intersection

Both shortest path (destination is Z) involve taking A.x-Z.x steps on horizontal, A.y-Z.y steps on vertical

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    pll a, b, c;
    cin >> a.fir >> a.sec;
    cin >> b.fir >> b.sec;
    cin >> c.fir >> c.sec;
 
    cout << abs(a.fir - b.fir >= 0 && a.fir - c.fir >= 0 ? a.fir-max(b.fir, c.fir) : (a.fir - b.fir <= 0 && a.fir - c.fir <= 0 ? a.fir-min(b.fir, c.fir) : 0))
    +
    abs(a.sec - b.sec >= 0 && a.sec - c.sec >= 0 ? a.sec-max(b.sec, c.sec) : (a.sec - b.sec <= 0 && a.sec - c.sec <= 0 ? a.sec-min(b.sec, c.sec) : 0)) + 1 << '\n';
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