```

A mod X = m1
B mod X = m2

A-m1 mod X = 0
B-m2 mod X = 0

We need to do gcd(A-m1, B-m2) to get the largest integer that allows us to do this.

The smallest integer is definitely a factor of X.

Turned out any number <= 1e5, only has a couple hundred factors.

So we can naively get all factors of gcd(A-m1, B-m2). By doing prime factorization, and then generate the factors, get the minimal factors that is bigger than max(m1,m2).

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
 
const int MX = 1e6 + 5;
int sieve[MX];
 
void gen_sieve(){
    for(int i{2}; i < MX; i++){
        if (sieve[i]) continue;
        for(int j{2*i}; j < MX; j+=i){
            sieve[j] = i;
        }
    }
}
 
ll gcd(ll a, ll b){
    return (!b ? a : gcd(b, a % b));
}
 
void solve(){
    ll a, b, m1, m2;
    cin >> a >> b >> m1 >> m2;
 
    if (m1 > a || m2 > b){
        cout << -1 << '\n'; 
        return;
    }else if (m1 == a && m2 == b){
        cout << max(a,b)+1 << '\n';
        return;
    }else if (!m1 && !m2){
        cout << 1 << '\n';
        return;
    }
 
    ll g = gcd(a-m1, b-m2);
    unordered_map<int,int> pf;
    while (sieve[g]){
        pf[sieve[g]]++;
        g /= sieve[g];
    }
    pf[g]++;
 
    vector<pi> p;
    for(auto& i : pf){
        p.pb(i);
    }
 
    int mn = INT_MAX;
    vi factors = {1};
    for(auto& i : p){
        int cur = 1;
        int si = sz(factors);
        for(int j{}; j < i.sec; j++){
            cur *= i.fir;
            for(int k{}; k < si; k++){
                if (factors[k] * cur > max(m1, m2)){
                    mn = min(factors[k] * cur, mn);
                }
                factors.pb(factors[k] * cur);
            }
        }
    }
 
    cout << (mn == INT_MAX ? -1 : mn) << '\n';
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >>t;
    gen_sieve();
    while(t--){
        solve();
    }
    return 0;
}
```