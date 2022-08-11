```
First ever bitmask dp.

The naive approach is to test the permutations of every node and see if there exist such a path, and that would take O(n!n)

But with bitmask DP, we could reduce the time complexity to O(2^n * n^2)

We are to find the number of hamiltonian path that starts from 1 to n.

DP state = [subset S, i-th node as the last visisted node] 
DP value = number of ways to reach the i-th node and having all other node in subset S visited

DP transition = dp[s][i] = dp[s][i] + (dp[s^(1 << i)][j] * adj[j][i]) , j is an element of subset S ^ (1 << i), adj[j][i] is the number of edges from a to b.

Few things to take note of:

We cannot transition from other node to node 1, because we must start from node 1.

We must end at node n, so there is no need to transition from other subset to n, rather than subset (1 << (n-1))-1. if we are to transition from other node to n in other set, we will get TLE.

For some reasons, we would get overflow without using long long dp array even though we've modded it.
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

int adj[20][20];
ll dp[1<<20][20];
const ll MOD = 1e9+7;

void solve(){
    int n, m;
    cin >> n >> m;
    
    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f][t]++;
    }

    dp[1][0] = 1;
    for(int i{}; i < (1 << (n-1)); i++){
        for(int j{1}; j < n; j++){
            if ((1 << j) & i){
                for(int k{}; k < n; k++){
                    if (!adj[k][j] || !((1 << k)&(i^(1<<j)))) continue;
                    //only if there's a connection from k to j
                    dp[i][j] = (dp[i][j] + ((dp[i^(1 << j)][k] * adj[k][j]) % MOD)) % MOD;
                }
            }
        }
    }

    for(int i{}; i < n; i++){
        if (!adj[i][n-1]) continue;
        dp[(1<<n)-1][n-1] = (dp[(1<<n)-1][n-1] + ((dp[((1 << (n-1))-1)][i] * adj[i][n-1]) % MOD)) % MOD;
    }


    cout << dp[(1<<n)-1][n-1];
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