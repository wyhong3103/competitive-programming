```

given n and m

ai <= m

bi <= m as well

gcd(b1...bi) = ai

find number of b arrays

b1 = a1 must

Observations

1. it must be a non-increasing array

bc if ai > ai+1

previous gcd must be ai-1, and there's no possible way we can increase gcd!

Previous gcd must be ai-1, and current gcd must be ai

2. ai must be a divisor for ai-1

previous gcd, must be ai-1, current gcd transition from the previous one, so it must be one of them


So how many number x is there such that gcd(ai-1, x) = ai?

We have noticed that prime factorization of ai-1, must consist of ai

ai-1 = ai * ... * ....

we can find number of divisor pretty easily with prime factorization!

But how do we even prime factorize, if every number is almost 1e9!?

One thing to keep note is, we need to keep ai, so we can divide ai-1/ai

by doing the above on every number, we can notice that the number will get really small very soon.

That way we can prime factorize it!

We're currently looking for x, x = ai * .... * ....

let's forget about ai for a sec

Notice that whatever prime is in x cannot exist in ai-1, because then gcd would vary!

So the idea is find the total number that is not a multiple of every prime in (ai-1/ai) from 1 to m/a[i] (make sure we don't exceed the limit).

We can do that with PIE.

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

const int MOD = 998244353;

ll gcd(ll a, ll b){
    return (!b ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b){
    return (a / gcd(a,b)) * b;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    
    vll a(n);
    for(auto& i : a) cin >> i;


    bool ok = 1;
    ll total = 1;
    for(int i{1}; i < n; i++){
        if (a[i-1] < a[i] || a[i-1] % a[i] != 0) ok = 0;
        if (!ok) break;

        //prime factorization
        ll cur = a[i-1]/a[i];
        set<ll> primes;
        for(int j{2}; j * j <= cur; j++){
            if (cur % j == 0) primes.insert(j);
            while (cur % j == 0){
                cur /= j;
            }
        }
        if (cur > 1) primes.insert(cur);

        vll primes_arr;
        for(auto& i : primes) primes_arr.pb(i);

        //PIE
        ll total_num = 0;
        for(int j{1}; j < (1 << sz(primes_arr)); j++){
            ll cur_number = 1;
            for(int k{}; k < sz(primes_arr); k++){
                if (j & (1 << k)) cur_number = lcm(cur_number, primes_arr[k]);
            }
            if (__builtin_popcountll(j) % 2 == 0) total_num -= m/(a[i] * cur_number);
            else total_num += m/(a[i] * cur_number);
        }
        total = (total * ((m/a[i])-total_num)) % MOD;
    }

    if (ok) cout << total << '\n';
    else cout << 0 << '\n';
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