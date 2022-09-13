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

void dfs(int node, vi& order, int& found){
    if (vis[node]){
        if (processing[node]) found = node;
        return;
    }
    vis[node] = 1;
    processing[node] = 1;
    order.pb(node);

    for(auto& i : adj[node]){
        dfs(i, order, found);
        if (found >= 0) return;
    }

    processing[node] = 0;
    order.pop_back();
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
    
    int found = -1;
    vi order;
    for(int i{}; i < n; i++){
        if (!vis[i]) dfs(i, order, found);
        if (found >= 0) break;
    }

    if (found == -1){
        cout << "IMPOSSIBLE";    
    }else{
        bool prnt = 0;
        int cnt = 0;
        vi res;
        for(auto& i : order){
            if (i == found) prnt = 1;
            if (prnt){
                cnt++;
                res.pb(i+1);
            }
        }
        cnt++;
        res.pb(found+1);
        cout << cnt << '\n';
        for(auto& i :res) cout << i << ' ';
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