```

There will only be a right angle triangle iff 2 of the points form the diameter of the circle, i.e distance between 2 points is circumference / 2, and there exist another point.


My wrong approach : Trying to do complementary counting is a bad idea. I couldn't have figured out the total way to have right angle triangle within the expected time complexity.

After changing to direct counting with the same counting method.

Main observation, if a pair of points (that have distance = c / 2 OR form diameter) has the same color, there cannot exist another point with the same color.

Solution,

Let's eliminate the basic cases first,

When n == 1, answer is just m

When n is an odd number, there just can never be such a pair, so answer is just m^n

Now is the real deal, when n is an even number,


Let's classify a configuration into certain state first,

We classify a configuration as x state iff it has x pairs of points, and each x pair has different color (if we have {point 1, point 2}, {point 3, point 4}, point 1 and 2 / 3 and 4 have the same color, but 1 and 3 can never have the same color).

Turns out the total ways to have distinct configuration is just the sum of total configuration with 1..x states. 

For j state configuration,

We will have j pairs with j different colors. And the rest of the points must be of different color! Also for the rest of the unselected pairs need to be differnt color as well!, i.e if {1,2} is a pair, they cannot have the same color

The total color we can use for the unselected points (point that is not of the j pairs) is m-j.

Let p be the total pairs of point that form a diameter

We can randomly assign a color to a point that is not part of a pair. So total way to do that is (n-p*2) ^ (m-j)

For the unselected pair, we want to make sure two of the point in the pair has different color so, ((m-j) * (m-j-1)) ^ (p-j)

The product of them is the total configuration for a single j state. Because we have not considered selecting the different j pairs and selecting the color for them.

To select j pairs from p pairs, is simply C[p][j], to permute the differnet color we have, P[m][j]

So the total distinct config for j state is C[p][j] * P[m][j] * ((n-p*2) ^ (m-j)) * (((m-j) * (m-j-1)) ^ (p-j))

We can do the above to calculate every j from 0 to min(p, m)

We cannot exceed m because we would run out of different color to pair them.
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

const int MOD = 998244353;

const int MX = 3e5 + 5;
ll fact[MX];

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq *sq) % MOD;
    return (p % 2 ? n * sq : sq) %MOD;
}

void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

ll ncr(ll n, ll r){
    return (fact[n] * modpow((fact[n-r] * fact[r]) % MOD , MOD-2)) % MOD;
}

void solve(){
    ll n, m;
    cin >> n >> m;

    gen_fact();

    set<ll> s;

    ll c = 0;
    for(int i{}; i < n; i++){
        s.insert(c);
        ll temp;
        cin >> temp;
        c += temp;
    }
    
    if (n == 1){
        cout << m;
        return;
    }else if (c % 2){
        cout << modpow(m, n);
        return;
    }

    ll total = 0;
    ll p = 0;
    for(auto& i : s){
        if (s.count(i + c/2)){
            p++;
        }
    }


    for(int i{}; i <= min(p, m); i++){
        ll v = ((modpow(((m-i)*(m-i-1)) % MOD, p-i)) * modpow(m-i, n-p*2)) % MOD;
        total += (((ncr(p, i) * ((fact[m] * modpow(fact[m-i], MOD-2)) % MOD)) % MOD) * v) % MOD;
        total %= MOD;
    }

    cout << total;
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