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

const int MAX = 2e5;
vi adj[MAX];
bool vis[MAX];
int dist[MAX];

void bfs(int node, pi& mx){
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    dist[node] = 0;
    while (!q.empty()){
        int cur = q.front(); q.pop();
        for(auto& i : adj[cur]){
            if (!vis[i]){
                vis[i] = 1;
                dist[i] = dist[cur] + 1;
                if (dist[i] > mx.fir){
                    mx.fir = dist[i];
                    mx.sec = i;
                }
                q.push(i);
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    pi mx{};
    bfs(0, mx);
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    pi ans{};
    bfs(mx.sec, ans);
    cout << ans.fir;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```