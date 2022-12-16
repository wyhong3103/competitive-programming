```
given x, y

gcd(x,y) = 1, is lucky

do x+1, y+1

if the new pair is lucky, then keep going until it ends

diff = |a-b|

if diff == 1, inf

diff >= 2, they will always stop, x*diff, (x+1)*diff exist

Find the earliest stop! 

Prime factorize diff, for every prime number find the stop, the number is the minimal stop

Why this work?

say diff = 3 * x

a, a + 3*x

gap is a multiple of 3, so we just have to land z on a multiple of 3,

earlist stop of divisor i is basically ceil(a/i) * i - a 
(land on earliest multiple of i that is bigger than a)
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
 
 
const ll MX = 5000;
int sieve[MX];
vi primes;
 
void gen(){
    for(int i{2}; i < MX; i++){
        if (sieve[i]) continue;
        primes.pb(i);
        for(int j{2*i}; j < MX; j+=i){
            sieve[j] = 1;
        }
    }
}
 
int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}
 
void solve(){
    ll a, b;
    cin >> a >> b;
 
    if (a >= b) swap(a, b);
 
    if (b-a == 1) cout << -1 << '\n';
    else if (gcd(a,b) != 1) cout << 0 << '\n';
    else{
        unordered_set<int> p;
        int diff = b-a;
        for(auto& i : primes){
            while(diff % i == 0){
                diff /= i; 
                p.insert(i);
            }
        }
 
        if (diff > 1) p.insert(diff);
 
        ll mn = LONG_LONG_MAX;
        for(auto& i : p){
        	// ceil(a/i) * i - a
            mn = min(mn, (ll)((a/i) + (a % i > 0)) * (ll)i - a);
        }
 
        cout << mn << '\n';
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