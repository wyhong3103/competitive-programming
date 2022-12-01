```

Prime factorization of a = p^x*p^x1...
Primfactorization of m = p^y*p^y1...
gcd(a,m) = p^min(x,y)...

To make sure gcd(a+x, m) stays the same, we must make sure that the prime factorization of a+x ,p_i if power of p_i in a is < power of p_i in m, we do not raise it at all! Because that would change the gcd! Otherwise we can do whatever we want!

Also every a+x must be divisible by gcd(a,m)!

To do this, we can find prime factorization of every number, and find every prime number, p such that power of p in a < power of p in g. 

And then we could do PIE to find total such number!

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
    ll a, m;
    cin >> a >> m;
    
    map<ll, pll> prime_fact;
    
    ll temp_a = a, temp_m = m;
    for(ll i{2}; i * i <= temp_a; i++){
        while (temp_a % i == 0){
            temp_a /= i;
            prime_fact[i].fir++;
        }
    }
    if (temp_a > 1) prime_fact[temp_a].fir++;

    for(ll i{2}; i * i <= temp_m; i++){
        while (temp_m % i == 0){
            temp_m /= i;
            prime_fact[i].sec++;
        }
    }
    if (temp_m > 1) prime_fact[temp_m].sec++;

    ll d = 1;
    vll exclude;
    for(auto& i : prime_fact){
        if (i.sec.fir < i.sec.sec){
            exclude.pb(i.fir);
        }
        ll temp = min(i.sec.fir, i.sec.sec);
        while(temp--) d *= i.fir;
    }
    
    //PIE
    ll ans = (a+m-1)/d - (a/d);
    for(int i{1}; i < (1 << sz(exclude)); i++){
        ll cur = d;
        for(int j{}; j < sz(exclude); j++){
            if (i & (1 << j)){
                cur *= exclude[j];
            }
        }
        ans = (ans + ((__builtin_popcount(i) % 2 ? -1 : 1) * (((a+m-1)/cur)-(a/cur)) ));
    }
    cout << ans+1 << '\n';
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