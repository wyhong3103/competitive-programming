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
const int MOD = 1e9 + 7;

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

    //total node, prev node
    vll dp(n);
    dp[0] = 1;
    for(auto& i : order){
        for(auto& j : adj[i]){
            dp[j] = (dp[i] + dp[j]) % MOD;
        }
    }
    cout << dp[n-1];
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