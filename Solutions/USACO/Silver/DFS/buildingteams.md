Bipartiteness check
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MAX = 1e5 + 5;
vi adj[MAX];
bool vis[MAX];
bool color[MAX];


bool dfs(int node){
    vis[node] = true;
    
    for(auto& i : adj[node]){
        if (!vis[i]){
            color[i] = !color[node];
            if (!dfs(i)) return false;
        }else if (color[i] == color[node]){
            return false;
        }
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    for(int i{}; i < n; i++){
        if (!vis[i] && !dfs(i)){
            cout << "IMPOSSIBLE" << '\n';
        }
    }

    for(int i{}; i < n; i++){
        cout << color[i]+1 << ' ';
    }
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```