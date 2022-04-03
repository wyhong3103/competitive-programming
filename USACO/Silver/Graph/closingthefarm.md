DFS , Connected Component

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

    
    vector<int> order(n);
    for(auto& i: order) cin >> i;


    for(int i{}; i < n; i++){
        int count{};
        for(int j{}; j < n; j++){
            if(!visited[j]){
                count++;
                dfs(j);
            }
        } 
        cout << (count == 1 ? "YES" : "NO") << '\n';

        for(int b{}; b < n; b++){
            visited[b] = false;
        }

        for(int x{}; x <= i; x++){
            visited[order[x]-1] = true;
        }
    }
}

int main(){
    setIO("closing");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
}

```