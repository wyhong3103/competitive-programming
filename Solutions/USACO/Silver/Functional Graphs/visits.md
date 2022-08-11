The idea of this problem is pretty straightfoward, it's basically a functional/sucessor graph. And if you paid attention to the problem statement, you will realize that we would only not be able to get moos ing a cycle, only one of the node in the cycle won't be able to get moos. The permutation/order of visit doesn't really matter, because the optimal answer is simply the sum of every moos but excluding the minimum in a cycle. This is the tricky part , we have to identify the cycle, and it's minimum.
```
The way I do is fairly simple, but not memory efficient, I've intialized 4 arrays each takes up O(N) space complexity, next_node, next_val, is of course essential, and a visited array, a considered array.

As the name would suggest next_node, next_val, visited is pretty obvious, but considered array, is something we need because, we would only considered a cycle when a cell hasn't been considered and it's been visited. It's the indicator that we're in a cycle.

When that happens, we will toggle a varibale called has_cycle, the moos value for every node that is in the cycle, will be considered, and we will add them into the sum. And remove the min at the end.

That's basically the idea, and for nodes that aren't in the cycle, we simply need to add up all the moos value along the path we visit during DFS, until we hit a node that is visited(either considered or not considered, if it's not considered then that mean we're in a cycle)
```
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

const int MXN = 1e5 + 5;
int next_node[MXN];
int next_val[MXN];
bool considered[MXN];
bool vis[MXN];

void dfs(int node, ll& sm, int& mn, int& has_cycle){
    if (vis[node]){
        if (!considered[node]){
            has_cycle = node;
        }
        return;
    }

    sm += next_val[node];
    vis[node] = 1;

    dfs(next_node[node], sm, mn, has_cycle);

    if (has_cycle >= 0){
        mn = min(mn, next_val[node]);
    }
    considered[node] = 1;

    //Back to the beginning node
    if (node == has_cycle){
        has_cycle = -1; 
    }
}


void solve(){
    int n;
    cin >> n;
    for(int i{}; i < n; i++){
        int t, v;
        cin >> t >> v;
        t--;
        next_node[i] = t;
        next_val[i] = v;
    }

    ll ans = 0;
    for(int i{}; i < n; i++){
        if (!vis[i]){
            ll sm = 0;
            int mn = INT_MAX;
            int has_cycle = -1;
            dfs(i, sm, mn, has_cycle);
            //If mn != INT_MAX, that means cycle is found
            if (mn != INT_MAX) sm -= mn;
            ans += sm;
        }
    }
    
    cout << ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```