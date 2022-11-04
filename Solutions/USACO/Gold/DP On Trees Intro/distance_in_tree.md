```

We could keep track of how many nodes that are in subtrees of i and is with distance j from node i, with dp on tree.

Once we had that information.

We could calculate how many made up a pair of (u,v) such that distance between u and v is exactly k.

There are 2 situtations.

1 is when node i (the root of the current subtree) is one of the endpoint, the total node that can pair up with this node is simply dp[i][k].

Another situation is when node i (the root of the current subtree) is LCA of u and v. 

How to calculate this??

Let vi.....vn be children of i.


Notice that if two of the end points are at different branch of i, one of them can have distance j from node i, and one of them can have distance k-i. 

How to calculate this effectively?

Let xi ... xn be the total number of nodes that has distance j from i that xi = dp[vi][j-1 (-1 because we're counting from the children instead of the root node)]. and yi be the dp[vi][k-j-1]

If we are to let vi be the one with longer distance, we can pair up vi with any other children, vi+1...vn with distance = k-j-1

And that is simply yi * (xi+1 , xi+2 .... xn). (Combinatorics)

And then we can also let xi+1 be the one with longer distance

And it's yi+1 (xi, xi+2 ... xn)

Notice that it's like sliding window! We subtract xi from the total sum, and then get yi and multiply them, and then add it back!

We can do the above for all i, 1 <= i <= floor((k-1)/2) (prevent overcounting)

But that's not the case when distance for both branch is equal. When they're equal we only need to subtract xi from total sum, we do not need to add it back. This is to prevent overcounting.

And the sum of all of that is the answer.
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

const int MXN = 5e4 + 5;
const int MXK = 501;
vi adj[MXN];
ll dp[MXN][MXK];
ll ans;

void dfs(int node, int prev, int k){
    dp[node][0] = 1;

    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node, k);
        }
    }

    for(auto& i : adj[node]){
        if (i != prev){
            for(int j{}; j < k; j++){
                dp[node][j+1] += dp[i][j];
            }
        }
    }

    for(int i{1}; i <= ((k-1)/2); i++){
        ll total = 0;
        for(auto& j : adj[node]){
            if (j == prev) continue;
            total += dp[j][i-1];
        }
        for(auto& j : adj[node]){
            if (j == prev) continue;
            total -= dp[j][i-1];
            ans += dp[j][(k-i)-1] * total;
            total += dp[j][i-1];
        }
    }

    //special case for k/2
    if (k % 2 == 0){
        ll total = 0;
        for(auto& j : adj[node]){
            if (j == prev) continue;
            total += dp[j][(k/2)-1];
        }
        for(auto& j : adj[node]){
            if (j == prev) continue;
            total -= dp[j][(k/2)-1];
            ans += dp[j][(k/2)-1] * total;
        }
    }
    ans += dp[node][k];
}

void solve(){
    int n, k;
    cin >> n >> k;

    for(int i{}; i < n-1; i++){
        int f,t ;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    dfs(0, -1, k);

    cout << ans;

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