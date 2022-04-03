Basic DFS

```cpp
        #include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

bool visited[100000];
vector<int> adj[100000];

void dfs(int node){
    if (visited[node]) return;

    visited[node] = true;
    for(auto& i : adj[node]){
        dfs(i);
    }
}


void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans;
    for(int i{}; i < n; i++){
        if(!visited[i]){
            ans.push_back(i+1);
            dfs(i);
        }
    }

    cout << ans.size()-1 << '\n';
    if (ans.size() > 1){
        for(int i{1}; i < ans.size(); i++){
            cout << ans[i-1] << ' ' << ans[i] << '\n';
        }
    }
}

int main(){
//    setIO("factory");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
}


```