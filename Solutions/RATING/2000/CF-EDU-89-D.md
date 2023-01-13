```

Fast prime factorization in log n with sieve.

partition prime divisors into two groups, and then sum of product of two grp is defeinitely coprime with a.

Proof

For any prime number p_i of prime divisors for a, it's obvious that p_i | a, and product of first group, d1, (without loss of generality) d1 mod p_i = 0 mod p_i, and d2 mod p_i != 0 mod p_i. So, (d1 + d2) mod p_i != 0 mod p_i. So, gcd(d1+d2, a) = 1.

We have to use all the prime numbers, so that, there is always one of the group is divisible by p_i but not the other one. that guarantees d1 + d2 mod p_i != 0.

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

const int MX = 1e7 + 5;
int sieve[MX];

void gen_sieve(){
    for(int i{2}; i < MX; i++){
        if (sieve[i]) continue;
        for(int j{2*i}; j < MX; j+=i){
            sieve[j] = i;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    
    gen_sieve();

    vi f(n);
    vi s(n);

    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        map<int,int> pf;
        while (sieve[x]){
            pf[sieve[x]]++;
            x /= sieve[x];
        }
        pf[x]++;
        f[i] = -1;
        s[i] = -1;
        if (sz(pf) > 1){
            for(auto& j : pf){
                if (f[i] == -1) f[i] = j.fir;
                else{
                    s[i] = (s[i] == -1 ? j.fir : s[i] * j.fir);
                }
            }
        }
    }

    for(int i{}; i < n; i++) cout << f[i] << ' ';
    cout << '\n';
    for(int i{}; i < n; i++) cout << s[i] << ' ';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}



```