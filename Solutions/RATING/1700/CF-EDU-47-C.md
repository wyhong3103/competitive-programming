```
maximal arithmetic mean!

for each m changes,

add n * x

add d * (dist)

n * x + (d * dist) + (d * dist) + (d * dist) ....

n * x + (sum of dist) * d

if d is negative, then at middle (minimize the value of d), use the natural sum formula to get both side of sum! when n is even we can stand at any of the middle point, else we just be at the middle point.

else n*(n-1)/2 (not including the first one)

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
    ll n, m;
    cin >> n >> m;

    ll total = 0;
    while(m--){
        ll x, d;
        cin >> x >> d;
        total += n * x;
        if (d >= 0) total += ((n * (n-1))/2) * d;
        else{
            ll half = (n)/2;
            if (n % 2 == 0){
                total += (((half * (half + 1))/2) * d) + (((half * (half - 1))/2) * d);
            }else{
                total += (half * (half + 1)/2) * d * 2;
            }
        }
    }
    cout << setprecision(7) << fixed;
    cout << ((double)total/n);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```