n-3 + 1 + 1 + 1, will always works, because gcd of any number with 1 , is 1, lcm of any number with 1 is 1 as well. So it's always optimal to do this.
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
 
using namespace std;
using vi = vector<int>;
using ll = long long;
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << n-3 << ' ' << 1 << ' ' << 1 << ' ' << 1 << '\n';
    }
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```