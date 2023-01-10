```

The idea is simple

Find the dimater of the tree, and then find the branch that extends the most in diameter.
	

	x
	|
x - x - x - x - x
	|
	x

Flatten the tree like above, (diameter), ans = 2 * diamater + 2 * longest branch extend from diameter


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

const int MX = 2e5 + 5;
vi adj[MX];

void dfs(int node, int prev, pi& dep, pi& deepest){
    deepest = max(deepest, dep);
    for(auto& i : adj[node]){
        if (i != prev){
            dep.fir++;
            dep.sec = i;
            dfs(i, node, dep, deepest);
            dep.fir--;
            dep.sec = node;
        }
    } 
}

void dfs2(int node, int prev, int target,vi& temp, vi& flatten){
    if (node == target) flatten = temp;

    for(auto& i : adj[node]){
        if (i != prev){
            temp.pb(i);
            dfs2(i, node, target, temp, flatten);
            temp.pop_back();
        }
    } 
}

void dfs3(int node, int prev, set<int> used, int& depth, int& mx){
    for(auto& i : adj[node]){
        if (i != prev && !used.count(i)){
            depth++;
            mx = max(mx, depth);
            dfs3(i, node, used, depth, mx);
            depth--;
        }
    } 
}

int solve(){
    pi ft;
    pi dep;
    pi deepest;
    dfs(0, -1, dep, deepest);
    ft.fir = deepest.sec;
    dep = {};
    deepest = {};
    dfs(ft.fir, -1, dep, deepest);
    ft.sec = deepest.sec;

    vi temp;
    vi flatten;
    temp.pb(ft.fir);
    dfs2(ft.fir, -1, ft.sec, temp, flatten);

    int ans = deepest.fir * 2;

    int mx = 0;
    for(int i{1}; i < (int)sz(flatten)-1; i++){
        set<int> used;
        used.insert(flatten[i+1]);
        used.insert(flatten[i-1]);

        int depth = 0;
        dfs3(flatten[i], -1, used, depth, mx);
    }
    ans += mx * 2;

    return ans;
    
}

int build(int N, std::vector<int> A, std::vector<int> B) {
	for (int i{}; i < N-1; i++){
		adj[A[i]].pb(B[i]);
		adj[B[i]].pb(A[i]);
	}

	return solve();
}

```