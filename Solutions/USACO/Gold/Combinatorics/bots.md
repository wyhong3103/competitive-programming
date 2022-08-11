A fun problem, but got misled at the beginning.
```
My first approach

To literally count the number of ways to arrange x element, 0 <= x <= 2*n, by using n red and n blue.

While it is easy to count how many unique way to arrange 2*n elements, it's simply (2*n)!/(n!)*(n!), because of the repeated element, but it gets complicated as you go down. 

For example,

(2*n)-1 

There could be {n+1 red, n-1 blue} or {n-1 red, n+1 blue} and so on.

Second approach (AC)

Notice that it expands as a tree, as visualized in the problem statement, but at some point, there will only be one branch.

So the idea is calcaulte for each level, how many one branch node will there be?

It is obvious that, when the level is <= n (at n, not after n), every node will expands to 2 other node, this is because of the fact that when we're only using x elements (x <= n), we can still fill it with blue/red

But when x >= n, in some cases, red/blue will already be exhausted, so it would lead down to one path

So for cases where x <= n, total number of nodes in that level would simply be 2^x

Now for the case where x > n

Because we only want to look for the case where there will be a single path down (red/blue exhausted), so we will assume it's red being exhasuted first, since red and blue has the same number of moves, so we can simply * 2.

The idea is we do x!/(n!)((x-n)!), this gives us the total number of ways to arrange n reds and x-n blues, i.e, the number of path that will only have a single path down

And from here, the answer is very clear.

The node that will expands to two path, is exactly the number of node in the previous level - single path (red and blue).

So the answer for this level is simply, (total[x-1]-single)*2 + single.
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


const int MX = 2e6+5;
const int MOD = 1e9 + 7;
ll total[MX];
ll factorial[MX];

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;

    if (p%2) return (sq * n) % MOD;
    return sq;
}


void gen_fact(){
    factorial[0] = 1;
    for(int i{1}; i < MX; i++){
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

void solve(){
    int n;
    cin >> n;
    
    gen_fact();
    for(int i{}; i <= 2*n; i++){
        if (i > n){
            ll single = (factorial[i-1] * modpow((factorial[n] * factorial[(i-1)-n]) % MOD, MOD-2) * 2) % MOD;
            total[i] = ((2 * (total[i-1]-single+MOD) % MOD)+single) % MOD;
        }else{
            total[i] = modpow(2, i);
        }
    }

    ll res = 0;
    for(int i{}; i <= 2*n; i++) res = (res + total[i]) % MOD;

    cout << res;
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