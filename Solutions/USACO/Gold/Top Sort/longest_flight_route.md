DP on DAG.
```

Process the node in top sorted order.

dp[i] = maximal number of cities we can travel before reaching node i

dp transition (in top sorted order)

for every node j that has an edge from node i

dp[j] = max(dp[j], dp[i]+1) 

We also need to store the previous city for each state.
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

const int MX = 1e5;
vi adj[MX];
bool vis[MX];
bool processing[MX];

void dfs(int node, deque<int>& order){
    if (vis[node]){
        return;
    }
    vis[node] = 1;

    for(auto& i : adj[node]){
        dfs(i, order);
    }

    order.push_front(node);
}


void solve(){
    int n, m;
    cin >> n >> m;
    
    for(int i{}; i < m; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
    }
    
    deque<int> order;
    dfs(0, order);

    if (!vis[n-1]) cout << "IMPOSSIBLE";
    else{
        //total node, prev node
        vector<pi> dp(n);
        dp[0] = {1, -1};
        for(auto& i : order){
            for(auto& j : adj[i]){
                if (dp[i].fir+1 > dp[j].fir){
                    dp[j] = dp[i];
                    dp[j].fir++;
                    dp[j].sec = i;
                }
            }
        }
        cout << dp[n-1].fir << '\n';
        vi res;
        int cur = n-1;
        while (cur != -1){
            res.pb(cur);
            cur = dp[cur].sec;
        }
        for(int i{sz(res)-1}; i >= 0; i--) cout << res[i]+1 << ' ';
        
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