```

We can do one operation, we choose two indices, and flip the bit. If they're adjacent , the cost is x, otherwise, y.

First it is proven that there is no way we can make a == b, if the differences is an odd number.

Each operation, we can only switch 2 number (make 2 differences). 1,1 -> 0,0 / 0,0 -> 1,1 / 0,1 -> 1,0 / 1,0 -> 0,1

That is why there is no way we can make this work.

x >= y, in this version.

Notice that, if y*2 <= x, there's no need to use X at all, X would only help to reduce the cost if we can make 2 adjacent element the same, but sometimes, this is not optimal.

Basically, we only need to use X if there's only one adjacent pair element that is different, otherwise, we can always use y to flip any two elements which is better because x >= y.

When there's only one pair element that is different, we use y*2 if y*2 <= x, otherwise X.

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
    ll n, x, y;
    cin >> n >> x >> y;

    string a, b;
    cin >> a  >> b;

    int cnt = 0;
    vector<bool> differ(n);
    for(int i{}; i < n; i++){
        if (a[i] != b[i]){
            cnt++;
            differ[i] = 1;
        }
    }

    if (cnt % 2){
        cout << -1 << '\n';
        return;
    }
    int cnt2 = 0;
    int at = 0;
    while (at < n-1){
        if (differ[at] && differ[at+1]){
            cnt2++;
            at+=2;
            continue;
        }
        at++;
    }
    if (cnt == 2 && cnt2 == 1) cout << (y*2 <= x ? 2*y : x) << '\n';
    else cout << (cnt/2) * y << '\n';
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