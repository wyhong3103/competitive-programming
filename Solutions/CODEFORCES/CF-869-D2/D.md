```

DFS Solution, find any cycle, we iterate through the order of the cycle, if we found a 2nd node that is the neighbor of node i, then we break! that is not the shortest cycle but that guarantees us to only using 2 nodes in the cycle, so that we could just another 2 on the extra edges 

```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
bool dfs(int node, int prev, vector<set<int>>& adj, vector<bool>& vis, vi& order, int root){
    if (vis[node]) return node == root;
 
    vis[node] = 1;
 
    for(auto& i : adj[node]){
        if (i == prev) continue;
        order.pb(i);
        if (dfs(i, node, adj, vis, order, root)){
            return true;
        }
        order.pop_back();
    }
    return false;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<set<int>> adj(n);
    for(int i{}; i < m; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].insert(t);
        adj[t].insert(f);
    }
 
 
    for(int i{}; i < n; i++){
        if (sz(adj[i]) >= 4){
            vector<bool> vis(n);
            vi order;
            if (dfs(i, -1, adj, vis, order, i)){
 
                set<int> used;
                vector<pi> edges;
                edges.pb({i, order[0]});
                for(int j{1}; j < sz(order); j++){
                    used.insert(order[j]);
                    used.insert(order[j-1]);
                    edges.pb({order[j-1], order[j]});
                    if (adj[i].count(order[j])){
                        edges.pb({i, order[j]});
                        break;
                    }
                }
                
 
                int cnt= 0;
                for(auto& j : adj[i]){
                    if (!used.count(j)){
                        edges.pb({i, j});
                        cnt++;
                    }
                    if (cnt == 2){
                        break;
                    }
                }
 
                cout << "YES" << '\n';
                cout << sz(edges) << '\n';
                for(auto& j : edges) cout << j.fir+1 << ' ' << j.sec+1 << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
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
```

Same method but BFS finding the shortest cycle

How to find the shortest cycle that has node i?

Do BFS from node i, and for every neighbor j of node i, mark the source of j as j, and then for every node j visit also mark the source as j. The first time we find a visited node that is not the previous node and has different source is the shortest cycle.

This is to prevent case like

       o
      /|
x--o-- |
      \|
       o

get falsefully identified as a cycle from x

(just realized this algorithm doesn't actually find the shortest cycle it has some flaws, but it is sufficient for this problem)

```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vi> adj(n);

    for(int i{}; i < m; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    
    for(int i{}; i < n; i++){
        if (sz(adj[i]) < 4) continue;

        vector<int> prev(n, -1);
        vector<int> src(n);
        
        queue<int> q;
        prev[i] = i;
        
        for(auto& j : adj[i]){
            src[j] = j;
            prev[j] = i;
            q.push(j);
        }

        int n1 = -1, n2 = -1;
        while (!q.empty() && n1 == -1){
            int cur = q.front(); q.pop();
            for(auto& j : adj[cur]){
                if (j != prev[cur]) {
                    if (prev[j] != -1 && src[j] != src[cur]){
                        n1 = cur, n2 = j;
                        break;
                    }
                    else if (prev[j] == -1){
                        prev[j] = cur;
                        src[j] = src[cur];
                        q.push(j);
                    }
                }
            }
        }

        if (n1 != -1){
            vector<pi> res = {{n1, n2}};
            set<int> used;
            int cur = n1;
            while (cur != i){
                res.pb({cur, prev[cur]});
                used.insert(cur);
                used.insert(prev[cur]);
                cur = prev[cur];
            }

            cur = n2;
            while (cur != i){
                res.pb({cur, prev[cur]});
                used.insert(cur);
                used.insert(prev[cur]);
                cur = prev[cur];
            }

            int cnt = 0;
            for(auto& j : adj[i]){
                if (!used.count(j)){
                    res.pb({i, j});
                    cnt++;
                }
                if (cnt == 2) break;
            }

            cout << "YES" << '\n';
            cout << sz(res) << '\n';
            for(auto& j : res) cout << j.fir+1 << ' ' << j.sec+1 << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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