```

An easy problem.

Basically, we can perceive fences as intermediate nodes, laser as starting point and barn as destination. We want to find the shortest path to reach the barn.

The neighbour of node i, is nodes that have the same x/y axis.

By doing a simple shortest path BFS, we can easily get the answer.

But we have to be careful when dealing with the visited nodes.

We're going to get TLE if we're doing naive approach which is literally trying to visit every node on the same x/y axis and checked if it has been visited or no.

A worst case scenario is the 100,000 nodes lined up on the same x/y axis. It's going to be N^2 if we naively visit each one of them.

One observation is that, whenever we're able to reach a node on particular x/y axis, every node on the same axis can be optimally visited by that node. So, on each x/y axis, if every got into one of the node on it, each node can be visited by it, as we do it, we can remove it from the adjacency list, because there's no need to check them as they're for sure getting visited by the first node on that x/y axis. So, we can pop our adjacency list if we've already visited that node.

And we can use a distance map(bst) to store the distance. -1 if unvisited.

If we ever align with the barn then we found our answer.

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


void solve(){
    int n;
    cin >> n;

    pi laser, barn;
    cin >> laser.fir >> laser.sec >> barn.fir >> barn.sec;


    map<int,vector<pi>> adj_x;
    map<int,vector<pi>> adj_y;
    map<pi, int> dist;
    dist[laser] = 0;
    while(n--){
        pi lo;
        cin >> lo.fir >> lo.sec;
        adj_x[lo.fir].pb(lo);
        adj_y[lo.sec].pb(lo);
        dist[lo] = -1;
    }
    
    queue<pi> q;
    q.push(laser);
    
    int res = INT_MAX;

    while (!q.empty()){
        pi cur = q.front(); q.pop();
    
        if (cur.fir == barn.fir || cur.sec == barn.sec){
            res = dist[cur];
            break;
        }

        while(!adj_x[cur.fir].empty()){
            pi i = adj_x[cur.fir].back();
            if (dist[i] == -1){
                dist[i] = dist[cur]+1;
                q.push(i);
            }
            adj_x[cur.fir].pop_back();
        }
        while(!adj_y[cur.sec].empty()){
            pi i = adj_y[cur.sec].back();
            if (dist[i] == -1){
                dist[i] = dist[cur]+1;
                q.push(i);
            }
            adj_y[cur.sec].pop_back();
        }
    }

    cout << (res == INT_MAX ? -1 : res);
}

int main(){
    setio("lasers");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```