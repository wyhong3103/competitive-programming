```

At first I thought it would be a satisfiability problem, spent time thinking on stupid ideas.

Afterward, I realized that we could actually just connect the nodes as the order in dfs first (as the order will be executed exactly the same in dfs, because it's the first node it will encounter when it dfs on the node).

After that, we work on the BFS array, doing some stupid 2 pointer thing, trying to create assign edges to the node as the level increases and all. It's just stupid really.

After a few minutes, I realized that we could totally just add all the nodes to the first node according to the order. But still got a WA, because of the case where there is no solution.

There is no solution if bfs[1] != dfs[1] , make sense actually.


Ad hoc problem I would say. One-hit observation.
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
    int n;
    cin >> n;

    vi bfs(n);
    for(auto& i : bfs) cin >> i;
    vi dfs(n);
    for(auto& i : dfs) cin >> i;
    
    if (bfs[1] != dfs[1]){
        cout << -1;
        return;
    }

    vector<pi> res;
    for(int i{}; i < n-1; i++){
        res.pb({dfs[i], dfs[i+1]});
    }
    for(int i{2}; i < n; i++){
        res.pb({bfs[0], bfs[i]});
    }

    cout << sz(res) << '\n';
    for(auto& i : res) cout << i.fir << ' ' << i.sec << '\n';
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