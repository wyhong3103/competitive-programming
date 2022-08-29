```

There is only one source of laser point, it can be proven that the manhattan distance (shortest distance from (1,1) to (n,m)) will always work if there is no blocking.

Think of it this way


If this way is blocked
x x x x
	  x
	  x
	  x

No way this way is getting block as well, or else it's just straight up impossible.

x
x
x
x x x x



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
 
void solve(){
    int n,m,sx,sy,d;
    cin >> n >> m >> sx >> sy >> d;
 
    bool ok = 0;
    {
        bool temp_ok = 1;
        for(int i{1}; i <= n; i++){
            if (abs(i-sx) + abs(1-sy) <= d) temp_ok = 0;
        }
        for(int i{1}; i <= m; i++){
            if (abs(n-sx) + abs(i-sy) <= d) temp_ok = 0;
        }
        ok |= temp_ok;
    }
 
    {
        bool temp_ok = 1;
        for(int i{1}; i <= m; i++){
            if (abs(1-sx) + abs(i-sy) <= d) temp_ok = 0;
        }
        for(int i{1}; i <= n; i++){
            if (abs(i-sx) + abs(m-sy) <= d) temp_ok = 0;
        }
        ok |= temp_ok;
    }
 
    if (ok){
        cout << n+m-2 << '\n';
    }else cout << -1 << '\n';
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