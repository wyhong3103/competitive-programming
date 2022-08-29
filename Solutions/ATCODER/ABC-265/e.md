```

We got 3 different moves to make at each location. And we can make 300 moves in total, we are to count the total number of paths and we cannot ever cross path with an obstacle.

Total number of paths are relatively small = 302 C 300 (n+r-1 C r) ~ 45000

Why are we doing this??

Say move 1 = A, move 2 = B = move 3 = C

A serios of paths of 3 would be

AAA
BBB
CCC
ABC
AAB
...


Notice that, order doesn't matter in this case, you can do all you want with the order, you're still going to end up in the same location.

So the idea is to use r-combinations from a set of n elements to calculate the total number of paths, and proving the size of n is relatively small.

So right now, we can DP on it.

Just like path on grid, on each move i, we transition from all location we ended up in move i-1, and make sure we don't cross path with an obstacle.


dp[n][x,y] = number of paths ended in [x,y] with moves n

for each move, [a, b]

dp[n+1][x+a, y+b] += dp[n][x,a] % MOD

In this situation, we can't use a DP array, but we can use a map to store the index.

######### 

BOTTLENECK THAT FAILED MY CODE AT FIRST

- Checking whether a location exist and initialize it. 
	- This is so unnecessary, I thought it would prevent undefined behavior by doing this, but I am wrong, this is a bottleneck.

- Saving all unnecessary dp states, notice that at each state, we only need the current state(n) and the previous state(n-1), by storing extra states (those that are way before n-1) actually slowed down our code. This I can't explain, but now I do understand that it slows down our code.


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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pi> moves(3);
    for(auto& i : moves) cin >> i.fir >> i.sec;

    set<pi> obstacles;
    while(m--){
        pi coord;
        cin >> coord.fir >> coord.sec;
        obstacles.insert(coord);
    }
        
    map<pi,int> dp;
    pi origin = {0,0};
    dp[origin] = 1;
    
    for(int i{1}; i <= n; i++){
        map<pi,int> new_dp;
        for(auto& j : dp){
            for(auto& k : moves){
                pi new_lo = {j.fir.fir+k.fir, j.fir.sec+k.sec};
                if (obstacles.count(new_lo)) continue;
                new_dp[new_lo] = (new_dp[new_lo] + j.sec) % MOD;
            }
        }
        swap(dp, new_dp);
    }

    ll res = 0;
    for(auto& i : dp){
        res = (res + i.sec) % MOD;
    }

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