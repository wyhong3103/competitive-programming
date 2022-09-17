```

Problem simplification:

We're given a string S, and we need to modify it in such a way that the string consist of subsegment that have at least K consecutive and same character. To change character i to j, it requires a[i][j]. a[i][j] != a[j][i], this is a weighted graph.

First and foremost, we can find the shortest distance between all pairs of characters by using floyd-warshall algorithm.

Because this is a directed graph,so the assignment would be

dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

We're doing KIJ order, but given this is a directed graph, and for safety reasons, we repeated this algorithm 4 times.

Now the DP part.

Note the contraint first, N <= 1e5, K <= N, M <= 26

This is quite similar to a problem we have done before, basically, assigning subsegments that have at least K length.

dp[i][j] = minimal cost needed to have character j ending at index i, guaranteed that it is always an optimal substructure (final answer, that means with this state, the K letters before it is definitely character J, take a look at the transition to know more)

Base case : dp[0][j] = 0, 0 <= j < m

dp transition,

if i > K, we can transition from the last dp state (continue with letter j, extend it, because we can have more than K consecutive characters in a subsegment)

dp[i][j] = min(dp[i][j], dp[i-1][j] + dist[s[i]-'a'][j]), 

only if i > K, because any states that is within K, is an invalid state, as there isn't a solution for subsegment shorter than K.

Or

We can form a new subsegment with length of K, and we can only do it, if i-K == 0 or i-K >= K, because we're starting our first dp state from dp[K][j], we cannot transition from any states > 0 & < K.

dp[i][j] = min(dp[i][j], dp[i-K][l] + prefix_sum[j][i-1] - prefix_sum[j][i-1-K]) (Take good care of indexing)

l and j both stands for the character we're using, this is because we aren't necessary transition from j character, we need to pair up every character to transition from.

The cost of changing a subsegment can be computed using prefix sum. Since there is only 26 characters, we can store a prefix sum array of the cost to change the entire string to the same character for each M characters.
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

void solve(){
    int n, m, K;
    cin >> n >> m >> K;

    string s;
    cin >> s;


    vector<vi> dist(m, vi (m));
    
    for(int i{}; i < m; i++){
        for(int j{}; j < m; j++){
            cin >> dist[i][j];
        }
    }

    for(int t{}; t < 4; t++){
        for(int k{}; k < m; k++){
            for(int i{}; i < m; i++){
                for(int j{}; j < m; j++){
                    if (i == j) continue;
                    //this is a directed graph!
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    vector<vll> cost(m, vll(n, 0));
    for(int i{}; i < m; i++){
        for(int j{}; j < n; j++){
            cost[i][j] += dist[s[j]-'a'][i];
            if (j) cost[i][j] += cost[i][j-1];
        }
    }
    
    //min cost
    vector<vll> dp(n+1, vll (m, {INT_MAX}));

    for(int j{}; j < m; j++) dp[0][j] = 0;

    for(int i{K}; i <= n; i++){
        for(int j{}; j < m; j++){
            dp[i][j] = min(dp[i][j], (i == K ? INT_MAX : dp[i-1][j] + dist[s[i-1]-'a'][j]));
            if (i-K == 0 || i-K >= K){
                for(int k{}; k < m; k++){
                    dp[i][j] = min(dp[i][j], dp[i-K][k] + (cost[j][i-1] - (i-1-K < 0 ? 0 : cost[j][i-1-K])));
                }
            }
        }
    }

    ll res = LONG_LONG_MAX;
    for(int i{}; i < m; i++) res = min(dp[n][i], res);
    cout << res;
}
 
int main(){
    setio("cowmbat");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```