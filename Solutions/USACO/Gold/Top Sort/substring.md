```
DP on DAG

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

const int MX = 3e5;
vi adj[MX];
bool vis[MX];
bool processing[MX];

void dfs(int node, deque<int>& order, bool& ok){
    if (vis[node]){
        ok &= !processing[node];
        return;
    }
    processing[node] = 1;
    vis[node] = 1;
    for(auto& i : adj[node]){
        dfs(i, order,ok);
    }
    processing[node] = 0;
    order.push_front(node);
}

void solve(){
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    for(int i{}; i < m; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
    }

    bool ok = 1;
    deque<int> order;
    for(int i{}; i < n; i++){
        if (!vis[i]){
            dfs(i, order, ok);
        }
    }
    if (!ok){
        cout << -1;
    }else{
        int mx = 0;
        vector<vi> dp(n, vi(26));
        for(auto& i :order){
            dp[i][s[i]-'a']++;
            for(auto& j : adj[i]){
                for(int k{}; k < 26; k++){
                    dp[j][k] = max(dp[j][k], dp[i][k]);
                }
            }
            for(int j{}; j < 26; j++){
                mx = max(mx, dp[i][j]);
            }
        }
        cout << mx;
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