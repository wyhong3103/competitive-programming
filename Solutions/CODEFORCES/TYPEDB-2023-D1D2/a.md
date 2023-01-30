```
x^y * y + y^x * x = n

We need to find x and y that would fit the above.


For an even number, we can simply let x = 1, y = n/2

1^(n/2) * (n/2) + (n/2)^1 * 1 

= n/2 + n/2 = n

For an odd number, let's prove that it doesn't exist (prove sum will always be an even number)

Observation

1. a^b, if a is an odd number, a^b will always be an odd number, same goes to an even number

let x y be both an odd number,

odd * odd + odd * odd = odd + odd = even

if we have one of them as an even number

even * odd + odd * even = even + even = even
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
 
void solve(){
    ll n;
    cin >> n;
 
    if (n % 2) cout << -1 << '\n';
    else cout << 1 << ' ' << n/2 << '\n';
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