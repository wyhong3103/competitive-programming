```

I do not solve this problem during contest, I also did not solve it on my own, but I'd like to learn it. (It's pretty math heavy.)

We're given a, b, d.

We need to find an x

0 <= x < 2^60

such that

(a | x) % d == 0
(b | x) % d == 0

Or report that x doesn't exist!

Let's focus on the part where x doesn't exist first!

X doesn't exist iff a or b has smaller lsb than d.

lsb - least significant bit

Why is that?

Let's take a look back at multiplication of binary numbers.

  1001
x  101
_______
  1001
 00000
100100
______
101101

The above is 9 * 5 = 45

Notice that, there is (no way) never a 1 could come earlier than the original number!

Now we have proven that lsb(d) > min(lsb(a), lsb(b)) is an impossible case, 

Otherwise it always exist. Why?

##################################

Let's denote c = a | b

x must be a superset of c (c is in x)

So how do we find an number x such that c is a superset of it and it is divisible by d?

Notice that we can have x < 2^60!!

that means, always, there will be 30 extra bits at the end! Which will never be used by c at all!

Let's denote y as the extra 30 bits. So right now we need to find a y such that

(y * (2^30) + c) mod d = 0 mod d

y * (2^30) mod d = -c mod d

y = -c mod d * inv(2^30, d)

Wow, seemed so trivial!

But here's the thing , inverse might not always exist in this case because when d is a power of 2, 2^30 and 2 is not coprime!

However, we can use a trick to make d as an odd number(always!)

Notice that c and d has a common divisor of (lsb(d) >> 1)

We can divide d and c by it, and have d as an odd number!

Let's denote that by d' and c'.

(y * (2^30) + c') mod d' = 0 mod d'

y * (2^30) mod d' = -c' mod d'

y = (-c' mod d' * inv(2^30, d')) mod d'

Now it always exist!

We can use extended euclidean algorithm to compute the inverse!

Finally X is (y * (2^30) + c) >> (lsb(d) >> 1)
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

ll binpow(ll n, ll p){
    if (!p) return 1;
    ll sq = binpow(n, p / 2);
    sq = (sq * sq);
    return (p % 2 ? sq * n : sq);
}

ll ex_gcd(ll a, ll b, ll& x, ll& y){
    if (!b){
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = ex_gcd(b, a % b, x1, y1);

    x = y1, y = x1 - (y1 * (a/b));
    return d;
}

ll inv(ll a, ll b){
    ll x, y;
    ex_gcd(a, b, x, y);
    return ((x % b) + b) % b;
}

void solve(){
    ll a, b ,d;
    cin >> a >> b >> d;
    
    ll c = a | b;

    if (__builtin_ctz(c) < __builtin_ctz(d)) cout << -1 << '\n';
    else{
        ll shift = __builtin_ctz(d);
        //d is always odd
        d >>= shift;
        c >>= shift;
        
        //(x * (2^30) + c) mod d/2^shift = 0 mod d/2^shift
        //x * (2^30) mod d' = ((-c mod d') + d') mod d'
        //x = (c') mod d' * inv(2^30, d)

        ll x = (((((-c) % d) + d) % d) * inv(1LL << (30),d)) % d;
        ll ans = (x * (1LL << (30))) + c;
        ans <<= shift;
        cout << ans << '\n';
    }
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