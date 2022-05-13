One tricky problem, I've got all the necessary observations, answer is 2 ^ number of connected components that fit the description, because number of ways to assign a connected component is 2 , we can assign 2 different color,(seeds). But I have messed up the implementation in the very beginning. I shouldn't have to confuse about how should I assign the edge etc etc, while I can literally just make them bipartite or don't by just modifying the color assignment in dfs.
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
vector<pi> adj[MAX];
bool vis[MAX];
bool color[MAX];

bool dfs(int node){
    vis[node] = true;
    
    for(auto& i : adj[node]){
        if (!vis[i.fir]){
        	//If they are the same then assign the same color
            color[i.fir] = (i.sec == 'S' ? color[node] : !color[node]);
            if (!dfs(i.fir)) return false;
        }else if (color[i.fir] == color[node] && i.sec != 'S') return false;
    }
    return true;
}
void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        char c; int f, t;
        cin >> c >> f >> t;
        f--;t--;
        adj[f].pb({t,c});
        adj[t].pb({f,c});
    }

    int count = 0;
    for(int i{}; i < n; i++){
        if (!vis[i] && dfs(i)){
            count++;
        }
    }

    if (count){
        cout << 1;
        while (count--)cout<<0;
    }else cout << 0;
}
 
 
int main(){
    setio("revegetate");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```