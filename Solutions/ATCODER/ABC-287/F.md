```

I TLE'd with my original code (not optmized, a lot of reinitialization), but the transition and state are the same.

DP State

dp[i][j][k] = number of ways to form a subgraph with exactly k components with node i as the root, root is taken (if j == 1) otherwise no (j == 0)

DP transition

The DP transition is almost like a knapsack-like transition.


If we take the root node

knapsack[i][1][j] += dp[c][1][k] * dp[i][1][j-k+1] 

If we are to take children node, we will join up the root node and the children, hence number of components = j-k+1

knapsack[i][1][j] += dp[c][0][k] * dp[i][1][j-k] 

If we do not take the children node, number of components = j + k


If we do not take the root node

knapsack[i][0][j] += dp[c][1][k] * dp[i][0][j-k]
knapsack[i][0][j] += dp[c][0][k] * dp[i][0][j-k]


Proving time complexity, O(N^2)

Let's see the pseudocode of our transition

for c in children of i:
	if (c != parent):
		for j from 0.....number of descendents for i:
			for k from 0....number of descendents for c:
				// transition
	

It's not hard to see that the code above take N^2 in total, not including the computing children state yet.

Let nd[i] be the number of descendents of node i

The transition above is basically,

nd[i] * nd[c1] + nd[i] * nd[c2] .... + nd[i]*nd[cx], and nd[i] = nd[c1] + nd[c2] + ... + nd[cx] + 1

so basically we have

(nd[i]) * (nd[i]-1) ~ nd[i]^2

Now we have proved that the code above takes O(N^2) s.t N is the number of descendent of node i.

If each node takes O(number of descendents^2) to compute the state transitions, the total complexity including the children computation would be

(nd[i])^2 + sum((nd[ci]^2)) for every children c of i


nd[i]^2 >= nd[ci]^2 + nd[ci+1]^2 + .... 

cus nd[i] is basically the sum of every ci,

and we know that

a^2+b^2 <= (a+b)^2, because (a+b)^2 = a^2 + b^2 + 2ab


(nd[i])^2 + sum((nd[ci]^2)) for every children c of i <= (nd[i])^2 + (nd[i])^2, because of the above

hence we conclude, the entire function (including computing children state) takes O(N^2), where N is the number of children.
```
```

A more formal proof

Pseudocode of the transition

for children c of root i:
  for j in 0...number of descendants of i:
    for k in 0...number of descendants of c:
       // transition

The above alone (not including computation of children is O(number of descendents^2)

Proof:

Let nd[i] be the number of descendants of node i,

The total steps
= nd[i] * nd[c_j] + nd[j] * nd[c_j+1] + ...
= nd[i] * (nd[c_j] + nd[c_j+1] + ... )
= nd[i] * (nd[i] - 1)
= nd[i]^2 - nd[i]
<= nd[i] ^ 2

Hence the TC is O(nd[i]^2)

Now to include the children's computation,

We will first assume it to be O(nd[c]^2) by induction,

So from inductive hypothesis, the total steps for children computation is
nd[c_j]^2 + nd[c_j+1]^2 + .... 

total steps for self + children computation 

= nd[i]^2 (which we have proven above) + sum(nd[c_j]^2) for every children j

<= nd[i]^2 + nd[i]^2 
since sum(nd[c_j])^2 >= sum(nd[c_j]^2), and nd[i]^2 >= sum(nd[c_j])^2,

<= 2 * (nd[i]^2)

which would still makes it O(nd[i]^2)


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
 
const int MX = 5005;
const int MOD = 998244353;
vi adj[MX];
 
vector<vll> dfs(int node, int prev){
    
    vector<vll> dp(2, vll (2));
    dp[0][0] = 1;
    dp[1][1] = 1;

    int sz = 2;
    for(auto& i : adj[node]){
        if (i == prev) continue;
        vector<vll> subtree = dfs(i, node);

        sz += sz(subtree[0]);
        
        vll knapsack(sz+1);
        vll knapsack1(sz+1);
        for(int j{}; j < sz(dp[0]); j++){
            for(int k{}; k < sz(subtree[0]); k++){
                //take
                knapsack[j+k] = (knapsack[j+k] + (dp[1][j] * subtree[0][k])) % MOD;
                if (j) knapsack[j+k-1] = (knapsack[j+k-1] + (dp[1][j] * subtree[1][k])) % MOD;

                //not take
                knapsack1[j+k] = (knapsack1[j+k] + (dp[0][j] * (subtree[0][k] + subtree[1][k]))) % MOD;
            }
        }
        swap(knapsack, dp[1]);
        swap(knapsack1, dp[0]);
    }
    
    return dp;
}
 
 
void solve(){
    int n;
    cin >> n;
 
    for(int i{}; i < n-1; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }


    vector<vll> dp = dfs(0, -1);
 
    for(int i{1}; i <= n; i++){
        cout << ((dp[0][i]+dp[1][i]) % MOD) << '\n';
    }
    
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