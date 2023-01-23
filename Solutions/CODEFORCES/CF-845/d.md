```

It's better to think of this problem in probability.


Let's first look at such a tree

  o
/ | \
o o o

Each node can be 1/0.

Out of every possible combinations, how many times would the root node get XOR of its children = 1?

Every node has half a probabilities to be 1 and another half to be 0.

In order for XOR to be 1, we got to have an odd number of 1.

With the above claim, we can make a (wild) guess that for n bits, number of times for the bits to have odd number of 1 is 2^n-1, another half is also even number!


  1
/   \
2    3
|  / | \
4  5 6  7

At t = 1,  node 4 5 6 7 is going to turn 0, and for node 1, 2 and 3, is going to be 1 for half of the time, 2^n-1. (based on our previous claim).

At t = 2, node 2 and 3 is going to turn 0, for node 1, half of the time is going to be 1 as well! This is because at t = 1, node 2 and 3 both have 2^n-1 times equal to 1. (which is half the probability)

Now we can see that, the answer is simply,

sum(2^n-1 * alive[i]), nodes that are alive (have not turned 0 at t = i)

This might be a little unclear (yes, it is). To really understand the proof, check out the editorial!

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

int dfs(int node, int prev, map<int,int>& cnt, auto& adj){
    int mx = -1;
    for(auto& i : adj[node]){
        if (i != prev){
            mx = max(mx, dfs(i, node, cnt ,adj)+1);
        }
    }

    mx = max(mx, 0);
    
    cnt[mx]++;
    
    return mx;
}

const int MOD = 1e9 + 7;
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? sq * n : sq) % MOD;
}

void solve(){
    int n;
    cin >> n;

    vector<vi> adj(n);

    for(int i{}; i < n-1; i++){
        int f,t;
        cin >> f >>t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    map<int,int> cnt;
    dfs(0, -1, cnt, adj);

    ll ans = 0;
    ll total = n;
    
    for(auto& i : cnt){
        ans = (ans + modpow(2, n-1) * total) % MOD;
        total -= i.sec;
    }
    cout << ans << '\n';
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