```

The idea is to create a spiral

add edges to all pair that makes up n+1, and n+2

So rn we have created a spiral, each node has at most 2 edges.

fix a node i, and then query every i j, s.t j != i

With the distance to all node identified, we can first connect i to the node that has distance 1, and then for every node that has distance j and if there are 2 nodes that has distance j-1, we make a query to identify which node that has distance j-1 should the node with distance j connect to, this would take 1 query, and if there is another node with distance j, it simply connect to the one that has dist j-1 that is not connected. If there is only one node with distance j-1, we could just connect node with distance j to it.

Worst case is when our fixed node i, is a middle node, it would take n/2 query to connection between all nodes.

After identifying the spiral, we can output the 2 possible spiral

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

void dfs(int node, int prev, int at, vector<vi>& adj, vi& order, vi& perm){
    perm[node] = order[at++];
    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node, at, adj, order,perm);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    int temp;
    if (n == 2){
        cout << "! " << 1 << ' ' << 2 << ' ' << 2 << ' ' << 1 << '\n';
        cout.flush();
        cin >> temp;
        return;
    }

    cout << "+ " << n+1 << '\n';
    cout.flush();
    cin >> temp;
    cout << "+ " << n+2 << '\n';
    cout.flush();
    cin >> temp;
    
    vector<vi> dist(n+5);
    for(int i{2}; i <= n; i++){
        cout << "? " << 1 << ' ' << i << '\n';
        cout.flush();
        int x;
        cin >> x;
        dist[x].pb(i);
    }


    int head = 0;
    vector<vi> adj(n+5);

    for(auto& i : dist[1]){
        head = i;
        adj[1].pb(i);
        adj[i].pb(1);
    }

    for(int i{2}; i <= n; i++){
        if (!sz(dist[i])) break;
        head = dist[i][0];
        if (sz(dist[i-1]) == 1){
            adj[dist[i-1][0]].pb(dist[i][0]);
            adj[dist[i][0]].pb(dist[i-1][0]);
        }else{
            cout << "? " << dist[i][0] << ' ' << dist[i-1][0] << '\n';
            cout.flush();

            int x;
            cin >> x;
            if (x == 1){
                adj[dist[i-1][0]].pb(dist[i][0]);
                adj[dist[i][0]].pb(dist[i-1][0]);
                if (sz(dist[i]) > 1){
                    adj[dist[i-1][1]].pb(dist[i][1]);
                    adj[dist[i][1]].pb(dist[i-1][1]);
                }
            }else{
                adj[dist[i-1][1]].pb(dist[i][0]);
                adj[dist[i][0]].pb(dist[i-1][1]);
                if (sz(dist[i]) > 1){
                    adj[dist[i-1][0]].pb(dist[i][1]);
                    adj[dist[i][1]].pb(dist[i-1][0]);
                }
            }
        }
    }

    vi order;
    int p1 = 1, p2 = n;
    int x = 0;
    while(p1 <= p2){
        if (x % 2 == 0) order.pb(p1++);
        else order.pb(p2--);
        x++;
    }

    vi res1(n+1);
    dfs(head, -1, 0, adj, order, res1);
    vi res2(n+1);
    reverse(all(order));
    dfs(head, -1, 0, adj, order, res2);
    cout << "! ";
    for(int i{1}; i <= n; i++) cout << res1[i] << ' ';
    for(int i{1}; i <= n; i++) cout << res2[i] << ' ';
    cout << '\n';
    cout.flush();
    cin >> temp;
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