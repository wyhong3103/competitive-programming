We can simply see this as a graph, just by identifying the connected component, the reason is that, as long as it's connected, no matter that it's the most distant node or something, as long as it's connected, it will be identified as a connected component/tree.
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

const int MAX = 1e4 + 5;
vi adj[MAX];
bool vis[MAX];

void dfs(int node){
    vis[node] = 1;
    for(auto& i : adj[node]){
        if (!vis[i]){
            dfs(i);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i{}; i < n; i++){
        int h;
        cin >> h;
        h--;
        adj[h].pb(i);
        adj[i].pb(h);
    }
    
    int count = 0;
    for(int i{}; i < n; i++){
        if (!vis[i]){
            dfs(i);
            count++;
        }
    }
    cout << count;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```