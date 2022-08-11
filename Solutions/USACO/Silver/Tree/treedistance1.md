The idea of this problem is pretty simple, and it doesn't require DP on Tree, (which freaked me out during that time, beacuse I know nothing about DP on Tree). So we essentially just have to find the diameter of the tree, and it's end points. With the end points we simply do a bfs/dfs and store the distance from the node to every other node, we must do it on both end points.
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
 
const int MAX = 2e5 + 5;
vi adj[MAX];
// distance from end point 1
int dist[MAX];
//distance from end point 2
int dist1[MAX];

void search_end(int node, int prev, int dst, pi& bst){
    if (dst > bst.fir){
        bst.fir = dst;
        bst.sec = node;
    }
    for(auto& i : adj[node]){
        if (i != prev){
            search_end(i, node, dst+1, bst);
        }
    }
}

void find_dist(int node, int prev, int dst, bool ops){
    (ops ? dist : dist1)[node] = dst;
    for(auto& i : adj[node]){
        if (i != prev){
            find_dist(i, node, dst+1, ops);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i{}; i < n-1; i++){
        int f, t;
        cin >>f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }
    
    //searching end points
    pi endpoints{};
    pi bst{};
    search_end(0,-1,0,bst);
    endpoints.fir = bst.sec;
    bst = {};
    search_end(endpoints.fir,-1,0,bst);
    endpoints.sec = bst.sec;

    //finding distnace from end points to every node
    find_dist(endpoints.fir, -1, 0, 1);
    find_dist(endpoints.sec, -1, 0, 0);

    for(int i{}; i < n; i++){
        cout << max(dist[i], dist1[i]) << ' ';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```