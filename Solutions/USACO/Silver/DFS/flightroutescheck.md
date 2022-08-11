I did not solve this, I kind of think of it in the wrong way, I kept thinking toward the direction of connected components, because of one video I've seen about kosaraju conected etc etc. Turned out it's way easier than that! Basically the idea is to travel from the first node to every other node, and test if you could travel from 1 back to every other node with reversed edges, that means edges u to v , to v to u. If you can can travel from both way and reached every other node then we can basically reached every other node from 1(every node).
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
vi adjback[MAX];
bool vis[MAX];


void dfs(int node, int x){
    vis[node] = true;
    for(auto& i : (x ? adjback[node] : adj[node])){
        if (!vis[i])
            dfs(i, x);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adjback[t].pb(f);
    }

    dfs(0,0);

    for(int i{}; i < n; i++){
        if (!vis[i]){
            cout << "NO" << '\n';
            cout << 1 << ' ' << i+1;
            return;
        }
    }

    memset(vis, 0, sizeof(vis));
    dfs(0,1);
    
    for(int i{}; i < n; i++){
        if (!vis[i]){
            cout << "NO" << '\n';
            cout << i+1 << ' ' << 1;
            return;
        }
    }

    cout << "YES";

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```