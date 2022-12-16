```

We can DP on tree.

Observation

let c[i] = number of paths covering node i

1.

From root node, 1, c[1] is always k, because every path starts from it.

The sum of c[j] of every children j of root is k.

We can generalize this into

If root node i has c[i] then sum of all c[j] = c[i], s.t j is children of i

2.

Value c[i] of every sibling cannot differ more than 1!

So when we have c[i] at root i,

Let nc = number of children of i

when c[i] % nc != 0, there will be c[i] % nc children has c[j] = ceil(c[i]/nc) and the rest have floor(c[i]/nc)

We must do this when we have c[i] at root i!

We can choose not to distribute it to its children, but that is not optimal, optimal is to distribute c[i] to all the children.

3.

With 2nd observation, we can basically try to distribute ceil(c[i]/nc) and floor(c[i]/nc) to every children and then choose the most optimal way (i.e the way that gives us biggest sum), such that only c[i] % nc is given ceil(c[i]/nc) and the rest floor(c[i]/nc)

DP state

dp[i][j] = maximal value when i as a root and is given j paths

DP transition

At first, dp[i][j] = (a[i] * j)

After computing every dp[z][ceil(c[i]/nc)] and dp[z][floor(c[i]/nc)] for every children z of node i

We can do greedy to choose the most optimal way.

This is basically a pretty standard problem,

we're given array a and array b that is same length, we can only choose x from a, the rest from b, such that every element we choose from a and b doesn't have the same index.

The idea is, we sort them by difference, we start taking the one that has the biggest difference, that guarantee us not to lose a huge amount of value.

For this above, we might tempted to just greedily choose the largest to smallest in a/b, but that doesn't work! 

dp[i][j] += biggest sum by choosing c[i] % nc that select ceil(c[i]/nc), and the rest floor

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


ll dfs(int cur, ll k, vector<vi>& adj, vll& a, vector<map<ll,ll>>& dp){
    if (dp[cur].count(k)) return dp[cur][k];

    dp[cur][k] = (a[cur] * k);

    vll c;
    vll f;

    int child = sz(adj[cur]);

    if (!child) return dp[cur][k];

    ll x = k/child + ((k % child) > 0);

    for(auto& i : adj[cur]){
        c.pb(dfs(i, x, adj, a, dp));
        if (x > 1 && k % child){
            f.pb(dfs(i, x-1, adj, a, dp));
        }
    }

    if (k % child == 0){
        for(auto& i : c) dp[cur][k] += i;
    }else if (x == 1){
        //x == 1 case
        int cnt = 0;
        sort(all(c), greater<ll>());
        for(auto& i : c){
            dp[cur][k] += i;
            cnt++;
            if (cnt >= k % child) break;
        }
    }
    else{
        //greedy to make sure what we take is optimal
        vector<pll> diff;

        for(int i{}; i < child; i++){
            diff.pb({c[i]-f[i], i});
        }

        sort(all(diff), greater<pll>());

        int cnt = 0;
        for(auto& i : diff){
            if (cnt < k % child){
                dp[cur][k] += c[i.sec];
            }else{
                dp[cur][k] += f[i.sec];
            }
            cnt++;
        }
    }
    
    return dp[cur][k];
}
 
void solve(){
    ll n, k;
    cin >> n >> k;

    vector<vi> adj(n);

    for(int i{1}; i < n; i++){
        int p;
        cin >> p;
        p--;
        adj[p].pb(i);
    }

    vll a(n);
    for(auto& i : a) cin >> i;

    vector<map<ll,ll>> dp(n);

    dfs(0, k, adj, a, dp);

    cout << dp[0][k] << '\n';
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