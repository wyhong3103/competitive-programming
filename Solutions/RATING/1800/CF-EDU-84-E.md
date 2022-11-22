```

Abridged statement:

Given an integer n, we have every number that is length n and have digits 0-9

A block with length i is in a number if there exists i consecutive occurence of the same integer 

000122

we have a block of 3 that is 0
we have a block of 1 that is 1
we have a block of 2 that is 2

We need to find the total number of occurence for each block with length i, 1 <= i <= n for all possible numbers!

Solution

Imagine a case where you have a block of length 3

. . a x x x a . . . (anywhere in the middle)

x x x a . . . . . . (also for right)

Above are the 2 scenario where it could be placed at !

a != x, because we want to ensure that block x is exactly with length 3! And the . can be any number!

With the above 2 cases, we could count it.

For case 1,

We could have 10^(n-i-2) permutation of '.' (any number) outside, and 10 * 9 * 9 for the block and it's adjacent element.

So the total arrange for such is 

10^(n-i-2) * 10 * 9 * 9 

= 10^(n-i-1) * 81

Remember we could move the block!!

= 10^(n-i-1) * 81 * (n-i-1)

For case 2

10 * 9 for the block and it's adjacent number

10^(n-i-1) for the outer elements!

So...

10^(n-i-1) * 10 * 9

= 10^(n-i)*9

And we could do it for both side

= 10^(n-i)*9*2

simply don't care what the others could be! even though there could be another block of length i in some arrangement, it don't matter because it's going to be counted in another arrangement!
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

const int MX = 2e5 + 5;
const int MOD = 998244353;

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}

void solve(){
    ll n;
    cin >> n;

    for(int i{1}; i < n; i++){
        ll sm = 0;
        //middle case
        if (n-i-2 >= 0){
            sm += ((modpow(10, n-i-1) * 81 % MOD) * (n-i-1)) % MOD;
            sm %= MOD;
        }
        //side case
        if (n-i-1 >= 0){
            sm += (modpow(10, n-i) * 9 * 2) % MOD;
            sm %= MOD;
        }
        cout << sm << ' ';
    }
    cout << 10;
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