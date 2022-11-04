```

DP state

dp[i][j] = total number of ways to paint the subtree of barn i such that barn i is colored in j

DP transition

We can start by setting dp[i][j] for all j as 1 if it's unpainted initially or else we only set dp[i][painted] as 1

To transition

Say current j is x, we want the product of every (sum(dp[child(i)][y]) such that y != x)

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

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
vi adj[MX];
ll dp[MX][3];
int painted[MX];

void dfs(int node, int prev){
    if (painted[node] == -1){
        dp[node][0] = 1;
        dp[node][1] = 1;
        dp[node][2] = 1;
    }else dp[node][painted[node]] = 1;

    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node);
        }
    }
    
    for(int i{}; i < 3; i++){
        if (!(painted[node] == -1 || painted[node] == i)) continue;
        for(auto& j : adj[node]){
            if (j != prev){
                ll total = 0;
                for(int k{}; k < 3; k++){
                    if (i == k) continue; 
                    total += dp[j][k];
                }
                dp[node][i] = (dp[node][i] * total) % MOD;
            }
        }
    }
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

    memset(painted, -1, sizeof(painted)) ;
    for(int i{}; i < k; i++){
        int b, c;
        cin >> b >> c;
        b--;c--;
        painted[b] = c;
    }

    dfs(0, -1);

    cout << (dp[0][0] + dp[0][1] + dp[0][2]) % MOD;

}

int main(){
    setio("barnpainting");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
 


```