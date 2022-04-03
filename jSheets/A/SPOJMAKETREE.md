Topological Sort using DFS
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


bool vis[100001];
vector<int> adj[100001];
int order[100001];
int parents[100001];

void dfs(int node, int& index){
    vis[node] = true;

    for(auto& i : adj[node]){
        if (!vis[i]){
            dfs(i,index);
        }
    }

    order[index] = node;
    index--;
}


void solve(){
    int n, k;
    cin >> n >> k;
    
    for(int i{1}; i <= k; i++){
        int number;
        cin >> number;
        for(int j{}; j < number; j++){
            int c;
            cin >> c;
            adj[c].push_back(i);
        }
    }

    int index{n};
    for(int i{1}; i <= n; i++){
        if (!vis[i]){
            dfs(i,index);
        }
    }

    for(int i{1}; i < n; i++){
        parents[order[i]] = order[i+1];
    }

    for(int i{1}; i <= n; i++){
        cout << parents[i] << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```