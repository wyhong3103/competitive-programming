```

We're basically given a forest!

For each tree, we do a dp on tree, to find the best j courses we can get from the current tree!

dp[i][j] = best j courses we can get from subtree i, including course i

After that, we can do a knapsack for each tree, each tree has x items (x = size of the tree from the root), but we can only select one of them! 

knapsack[i][j] = best value we can achieve while only selecting first i trees and with j courses

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

const int MXN = 305;
const int MXM = 305;
vi adj[MXN];
int credit[MXN];
int n, m;
int dp[MXN][MXM];

void rec(int root, int at, int total, int cnt){
    if (at == sz(adj[root])){
        dp[root][cnt+1] = max(dp[root][cnt+1], total+credit[root]);
        return;
    }

    for(int i{}; i < m; i++){
        if (dp[adj[root][at]][i] == -1) return;
        rec(root, at+1, total+dp[adj[root][at]][i], cnt+i);
    }
}

void dfs(int node){
    dp[node][1] = credit[node];
    for(auto& i : adj[node]){
        dfs(i);
    }
    rec(node, 0, 0, 0);
}

void solve(){
    cin >> n >> m;

    vi root;

    memset(dp, -1, sizeof(dp));
    for(int i{}; i < n; i++){
        dp[i][0] = 0;
        int f, c;
        cin >> f >> c;
        if (f){
            adj[f-1].pb(i);
        }else{
            root.pb(i);
        }
        credit[i] = c;
    }

    
    for(auto& i : root) dfs(i);

    vector<vi> knapsack(sz(root)+1, vi(m+1));

    vector<vector<pi>> item(sz(root));

    for(int i{}; i < sz(root); i++){
        for(int j{}; j <= m; j++){
            item[i].pb({j, dp[root[i]][j]});
        }
    }

    int mx = 0;
    for(int i{1}; i <= sz(root); i++){
        for(int j{}; j <= m; j++){
            knapsack[i][j] = max(knapsack[i][j], knapsack[i-1][j]);
            for(auto& k : item[i-1]){
                if (j - k.fir >= 0){
                    knapsack[i][j] = max(knapsack[i][j], knapsack[i-1][j-k.fir] + k.sec);
                }
            }
        }
        mx = max(mx, knapsack[i][m]);
    }
    cout << mx;
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