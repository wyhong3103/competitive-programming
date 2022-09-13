```
DP on DAG

basically for each node, store every possible number of steps we can take to reach it. At the end, we would have every possible steps we can use to reach the end vertice.

on each queries, we are to find whether the sum of steps on each universe can be x, simply iterate through every possible step in any universe, let it be i, then check x-i on the other universe see if it exists.
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

const int MX = 1e3;
vi adj[MX];
bool vis[MX];

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
    int n1,n2, m1, m2;
    cin >> n1 >> n2 >> m1 >> m2;
    

    vector<vector<bool>> dp(n1, vector<bool> (max(n1,n2)+1));
    vector<vector<bool>> dp1(n2, vector<bool> (max(n1,n2)+1));

    for(int i{}; i < 2; i++){
        for (int j{}; j < (!i ? n1 : n2); j++) adj[j].clear();
        memset(vis, 0, sizeof(vis));

        for(int j{}; j < (!i ? m1 : m2); j++){
            int f,t;
            cin >> f >> t;
            f--;t--;
            adj[f].pb(t);
        }
        
        deque<int> order;
        dfs(0, order);

        //total node, prev node
        auto& dp_temp = (!i ? dp : dp1);
        dp_temp[0][0] = 1;
        for(auto& j : order){
            for(auto& k : adj[j]){
                for(int l{}; l < (!i ? n1 : n2); l++){
                    if (dp_temp[j][l]){
                        dp_temp[k][l+1] = 1;
                    }
                }
            }
        }
    }

    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;
        bool ok = 0;
        for(int i{}; i <= max(n1,n2); i++){
            if (x-i >= 0 && x-i <= max(n1,n2) && dp[n1-1][i] && dp1[n2-1][x-i]) ok = 1;
        }
        cout << (ok ? "Yes" : "No") << '\n';
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