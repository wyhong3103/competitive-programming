Minimum is literally the number of buses with 6 tyres we can make, if there's left with 2 we can turn a 6 into a 4, and use another 4 to make a 4. If we're left with 4, we can basically make 1 more 4 tyred bus.
<br>
Maximum is the same, if we're left with 2, We can basically turn a 4 into a 6.
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll mn = n/6;
        ll mx = n/4;
 
        ll totalmn = mn*6;
        ll totalmx = mx*4;
        
        if (n <= 2 || (n-totalmn) % 2 != 0 || (n-totalmx) % 2 != 0) cout << -1;
        else{
            cout << mn+(n-totalmn >= 2 ? 1 : 0) << ' ' << mx;
        }
        cout << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```