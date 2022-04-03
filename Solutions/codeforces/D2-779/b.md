This problem involves counting principle, so we are told to find the number of permutations that fits the condition gcd(1 * p1, 2 * p2....) > 1, well after observation, I noticed that, odd number of n would always be 0, for even number we can essentially switch all the places of even number to odd number, bc that would essentially turn all odd number to even number, and the gcd must be bigger than 1. So how do we calculate that?
<br> 
```
Product Rule

1 2 3 4 5 6 7 8
_ _ _ _ _ _ _ _

4 4 3 3 2 2 1 1 

At the first index, we can choose 4 even numbers, and the second index, we can choose 4 odd numbers, but when it comes to third index, we only left 3 even numbers, so on and so forth.

```
This essentially formed a pattern, the answer is essentially the square of factorial of n / 2 

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 

 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n % 2 != 0) cout << 0 << '\n';
        else{
            ll ans{1};
            ll MOD = 998244353;
            for(int i{1}; i <= (n/2); i++){
                ans = ((ans%MOD) * (i)) % MOD; 
            }
            ans = ((ans%MOD) * (ans%MOD)) % MOD; 
            cout << ans << '\n';
        }
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```
Did some extra modular arithmetic there, it's extra, but I just want to make sure things go right