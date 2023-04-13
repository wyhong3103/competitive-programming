```
We are to find the subset of items that give gcd(l[i], l[j], ..., l[n]) == 1

Notice that, in order to make gcd = 1, only the prime number matters, 2*2*2 can just be represented in 2, 2 * 2 * 3 in 2 * 3

just the product of the distinct prime numbers, since that is what make gcd = 1

There is only 50 million prime number below 1e9

It is seemingly doable (it is)

Actually, we dont even need to do prime fatorization,


Maximum number of divisor for a number below 1e9 is 1344

https://gist.github.com/dario2994/fb4713f252ca86c1254d

total gcd candidate (higher bound) = 1344 * 300

(because a gcd must be one of the divisor of the number, and total distinct divisor is just 300 * 1344)

total computations = 1344 * 300 * 300 ~ 2e8, which would pass the TL
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

ll gcd(ll a, ll b){
    return (!b ? a : gcd(b, a % b));
}

void solve(){
    int n;
    cin >> n;

    vll l(n);
    for(auto& i : l) cin >> i;
    vll c(n);
    for(auto& i : c) cin >> i;

    for(int i{}; i < n; i++){
        set<ll> s;
        for(int j{2}; j * j <= l[i]; j++){
            if (l[i] % j == 0) s.insert(j) ;
            while (l[i] % j == 0) l[i] /= j;
        }
        if (l[i] > 1) s.insert(l[i]);

        ll m = 1;
        for(auto& j : s) m *= j;

        l[i] = m;
    }

    map<ll, ll> dp;
    dp[l[0]] = c[0];

    for(int i{1}; i < n; i++){
        map<ll,ll> dp2;
        for(auto& j : dp){
            dp2[j.fir] = min((dp2.count(j.fir) ? dp2[j.fir] : LONG_LONG_MAX), j.sec);
            dp2[gcd(j.fir, l[i])] = min((dp2.count(gcd(j.fir, l[i])) ? dp2[gcd(j.fir,l[i])] : LONG_LONG_MAX), j.sec + c[i]);
        }
        dp2[l[i]] = min(dp2.count(l[i]) ? dp2[l[i]] : LONG_LONG_MAX, c[i]);
        swap(dp, dp2);
    }

    cout << (!dp.count(1) ? -1 : dp[1]);
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