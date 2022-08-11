So the idea is basically about finding every nodes that are involved in a cycle. And it's pretty simple, we just have to dfs on every node and see if it reaches itself from other node, if it does, it's in a cycle. Notice that we have to reset the visit array everytime we done a dfs. So the time complexity is O(N^2).
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

vi adj[25];
bool vis[25];
bool cycle[25];

void dfs(int node, int start){
    vis[node] = true;
    for(auto& i : adj[node]){
        if (i == start){
            cycle[node] = true;
        }
        if (!vis[i]){
            dfs(i, start);
        }
    }
}


void solve(){
    int n, k;
    cin >> n >> k;

    for(int i{}; i < k; i++){
        int f, t, s1, s2;
        cin >> f >> t >> s1 >> s2;
        f--;t--;
        if (s1 > s2){
            adj[f].pb(t);
        }else{
            adj[t].pb(f);
        }
    }

    for(int i{}; i < n; i++){
        dfs(i, i);
        memset(vis,0, sizeof(vis));
    }

    int count = 0;
    for(int i{}; i < n; i++){
        if (cycle[i]) count++;
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