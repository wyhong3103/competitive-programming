The idea of solving this problem is 
```
Sort the array

after sorted

a[n-1] + a[n-2] + a[n-3] should exist in the array, (notice that any 3 positive element would fail,because there is never an element that is bigger than that), same goes to a[0] a[1] a[2], when number is negative.

Because of some edge cases, it's best , if we also test a[0] + a[n-1] + a[n-2] , a[n-1] + a[0] + a[1]

for case like

-1 0 0 0 0 0 0 0 0 2

```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
    
    vector<ll> a(n);
    set<ll> number;
    for(auto& i : a){
        cin >> i;
        number.insert(i);
    }
 
    sort(all(a));
    if (number.count(a[n-1]+a[n-2]+a[0]) && number.count(a[0]+a[1]+a[n-1]) && number.count(a[n-1]+a[n-2]+a[n-3]) && number.count(a[0]+a[1]+a[2])) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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