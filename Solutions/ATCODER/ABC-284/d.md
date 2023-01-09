```

N is guaranteed to be divisible by p^2 * q, we can iterate every prime number that is below 1e7.

The reason is, worse case scenario for N is that it's lowest prime number is 1e6, 1e6 ^ 3 ~ 1e18

Otherwise,there will always be a smaller prime number, and we can iterate every prime number to find the bigger one.

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
 
const int MX = 1e7+5;
int sieve[MX];
vll primes;
 
void gen(){
    for(int i{2}; i < MX; i++){
        if (sieve[i]) continue;
        primes.pb(i);
        for(int j{2 * i}; j < MX; j += i){
            sieve[j] = 1;
        }
    } 
}
 
void solve(){
    ll n;
    cin >> n;
    
    for(auto& i : primes){
        if (n % i == 0) {
            if (n % (i * i) == 0) cout << i << ' ' << n / (i * i) << '\n';
            else{
                ll p = 0;
                
                ll lo = 2, hi = INT_MAX;
 
                while (hi > lo){
                    ll mid = lo + (hi-lo+1)/2;
                    if (mid * mid <= (n/i)) lo = mid;
                    else hi = mid-1;
                }
                p = lo;
 
                cout << p << ' ' << i << '\n';
            }
            return;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    gen();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```