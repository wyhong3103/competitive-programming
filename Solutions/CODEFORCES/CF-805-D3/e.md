Did not solve in actual contest, i don't even remember that bipartite exist. Anyways, it's simply bipartite graph matching. Tricky part is to construct the edges. Node a and node b have an edge iff they share a same number.
```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
bool dfs(int node, vector<bool>& vis, vector<set<int>>& adj, vector<bool>& color){
    vis[node] = true;
 
    for(auto& i : adj[node]){
        if (!vis[i]){
            vis[i] = true;
            color[i] = !color[node];
            if (!dfs(i, vis, adj, color)){
                return false;
            }
        }
        else if (color[i] == color[node]){
            return false;
        }
    }
    return true;
}
 
void solve(){
    int n;
    cin >> n;
 
    bool ok = 1;
    vector<vi> dominoes(n);
    for(int i{}; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        if (a == b) ok = 0;
        else if (sz(dominoes[a]) >= 2 || sz(dominoes[b]) >= 2) ok = 0;
        dominoes[a].pb(i);
        dominoes[b].pb(i);
    }
    if (!ok){
        cout << "NO" << '\n';
    }else{
        vector<set<int>> adj(n);
        vector<bool> vis(n);
        vector<bool> color(n);
 
        for(auto& i : dominoes){
            for(int j{}; j < sz(i); j++){
                for(int k{j+1}; k < sz(i); k++){
                    adj[i[j]].insert(i[k]);
                    adj[i[k]].insert(i[j]);
                }
            }
        }
 
        bool ok = 1;
        for(int i{}; i < n; i++){
            if (!vis[i]){
                ok &= dfs(i, vis, adj, color);
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
```