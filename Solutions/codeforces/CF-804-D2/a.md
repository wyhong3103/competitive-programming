If n is odd, there is no way you can get an odd element. Let's see the cases below
```
n = 1

a = 1, b = 0, c = 0

a xor b = 1 XOR 0 = 1
a xor c = 1 XOR 0 = 1

1 + 1 = 2, the sum of them get you back an even element

say a = 1, b = 1, c = 0

a xor b = 0
a xor c = 1
b xor c = 1

again , even element
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
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int n;
    cin >> n;
    if (n % 2){
        cout << -1;
    }else{
        cout << n/2 << ' ' << n/2 << ' ' << 0 ;
    }
    cout << '\n';
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