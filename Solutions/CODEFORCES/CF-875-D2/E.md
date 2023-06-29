```

Hyperregular Bracket Sequence

Obvious case:

The string is not valid iff any of the RBS interval is odd length

If every interval is disjoint, total number of ways that is valid is just

C_a0/2 * C_a1/2 * ... C_an/2 * C(n-sum(ai)/2)

ai is the length of the ith interval

intersection between two intervals cannot be an odd number as well, because that would have for the interval on the left, it has more left bracket at the end. Say

[ a ( b ] c )

b definitely has more left bracket, because its odd length, and a definitely has more as well. So a + b would definitely bigger than half, hence proving that it is impossible.

Each intersectionn has to be a valid parenthesis sequence as well.

What about

[ b (a) b ]

a would have to be a RBS and (b - a) would also have to be a RBS

Let's denote a group as a subsequence of elements that has to be a RBS.

Based on the above, we can conclude that index i and index j belongs to the same group iff they are covered by the same subset of intervals. The idea is for each overlapping, either partial or full, we can break them down to different groups. And for each group we broke down, they will be further broken down if there is any extra interval that covers it. And the final answer is simply for product of number of RBS arrangements of each group. Any odd length interval make the answer 0. 

To find the number of index belongs to groups, for every group. We can do XOR Hashing + Difference Array.

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
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
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}

void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i ) %MOD;
    }
}

ll ncr(ll n, ll r){
    ll num = (fact[n] * modpow(fact[n-r], MOD-2)) % MOD;;
    ll denom = fact[r];
    return (num * modpow(denom, MOD-2)) % MOD;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vll diff(n);

    for(int i{}; i <= k; i++){
        ll M = (1LL << 61) - 1;
        ll P = uniform_int_distribution<ll>(0, M - 1)(rng);
        if (!i){
            diff[0] = P;
        }else{
            int l, r;
            cin >> l >> r;
            l--;
            diff[l] ^= P;
            if (r < n) diff[r] ^= P;
        }
    }

    map<ll,int> mp;
    ll cur = 0;
    for(int i{}; i < n; i++){
        cur ^= diff[i];
        mp[cur]++;
    }

    //C_n = 1 / n+1 binom(2n, n)
    ll total = 1;
    for(auto& i : mp){
        if (i.sec % 2) total = 0;
        total = (total * ((ncr(i.sec, i.sec/2) * modpow(i.sec/2 + 1, MOD-2)) % MOD) ) % MOD;
    }

    cout << total << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    gen_fact();
    while(t--){
        solve();
    }
    return 0;
}

```