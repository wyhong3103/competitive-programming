```

Notice that everytime we do a graph traversal, there's only 2 situatios we will ever encounter a node we have visited
- It's the previous node
- It's a cycle

But here we need BFS in order to determine the shortest cycle, as DFS couldn't do that.

Observation

Let's take a look at an odd length cycle first

	o--o
	| / 
	o/

Start from any arbitary node, note that at one point when the nodes meet each other again, they're going to have a distance 1

	0--1
	| /
	1/

So, first observation, if we ever encounter a node with the same distance as us, that means we're in a cycle, and that is the shortest path of that cycle, which is (1+1)+1.

But what about an even length cycle?

	o--o
	|  |
	o--o

Start from any arbitary node,

	0--1
	|  |
	1--2

Notice that, a node with distance 1 will first head to the empty node and set it with distance 2 and then ends. And the next node with distance 1 is going to try to visit the node with distance 2. And that also means that we're in a cycle.

From the above observations, we can tell that we found a cycle of length dist[a]+dist[b]+1, when dist[b] >= dist[a], (a = current node, b = node we're trying to visit). The order of b and a matters, because we could possibly be visiting a previous node, if we're currently at a node with bigger distance trying to visit a node with distance-1.

It is impossible to do it in O(N) to find the length of the shortest cycle. Because everytime we do the above on a node, we're only going to know the length of the cycle that consist of that particular node. So we will do it in O(N^2).
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

const int MX = 2500;
vi adj[MX];
int dist[MX];

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    int res = INT_MAX;

    for(int i{}; i < n; i++){
        memset(dist, -1, sizeof(dist));
        queue<int> q;
        dist[i] = 0;
        q.push(i);
        while (!q.empty()){
            int cur = q.front(); q.pop();
            for(auto& i :  adj[cur]){
                if (dist[i] == -1){
                    dist[i] = dist[cur]+1;
                    q.push(i);
                }else if (dist[cur] <= dist[i]){
                    res = min(dist[i]+dist[cur]+1, res);
                }
            }
        }
    }

    cout << (res == INT_MAX ? -1 : res);
}
    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```