```

Obvious solution is to do dynamic programming, transition for duplication and insertion is simple

But what about deletion??

You might be tempted to use Segment Tree to get the minimal value needed to do deletion from dp[j] to reach i, s.t j > i. But it is too slow! (Similar to the segment tree we used in Pizzeria Queries from CSES)

Notice that we can also try using a set! Storing {total cost to delete until 0, index}

First let's prove that

If between dp[j] and dp[k], k > j, if dp[k] < dp[j] AND dp[k] + k * x <= dp[j] + j * x, then it is always optimal to use k to reach any i, s.t i <= j

Imagine for dp[k], we only do deletions until j, if at that point, dp[k] <= dp[j], it is guaranteed that this property will remian for any further deletions, because the deletion cost needed after that for both j and k is the same. So basically, we can decide which is optimal to use by looking at the total cost needed to delete until index 0 for both dp[j] and dp[k].

if the minimal total cost of deletion to reach 0 is z, total cost to reach i is simpy z - i * x

BUT, set is too slow!

We need something faster!

Let's introduce monotonic deque,

Notice that, we will always prioritize using the smallest cost of deletion, so we always want the front of the queue to have the optimal value

And we want to make sure that the front index is always > i.

As for the back, it is guaranteed that every cost of the back will be bigger than front, otherwise, front is just not the optimal value.

The same needed to be applied to every element. So you can kind of see the shape of a monotonic deque.

Let's say the front is already at optimal, how do we guarantee that the monotonicity of the deque remain? If the new dp value we want to add to the queue is smaller than any of the back we pop them off before adding it.

This way we can do our DP in O(N), which can pass the TL pretty effortlessly.

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

void solve(){
    ll n, in, du;
    cin >> n >> in >> du;

    deque<pll> q;    

    vll dp(n+5, LONG_LONG_MAX);
    dp[0] = 0;
    dp[1] = in;

    for(int i{1}; i <= n; i++){
        while (!q.empty() && q.front().sec < i) q.pop_front();
        
        if (!q.empty()) dp[i] = min(dp[i], q.front().fir - i * in);
        dp[i+1] = min(dp[i]+in, dp[i+1]);
       
        pll cur = {dp[i] + du + 2*i*in, 2*i};
        //monotonic queue
        while (!q.empty() && q.back().sec >= cur.fir) q.pop_back();
        q.pb(cur);
    }

    cout << dp[n];
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