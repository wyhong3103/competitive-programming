This problem is about identifying the number of nodes that are in a cycle. We could easily done this with floyd's algorithm, but I am trying to do it with dfs, which is a little handy, because for the past few functional graph problems, I've done it with floyd's algorithm instead of a dfs. 
```
Anyways here's the explanation.

So basically I set the array in_cycle as 0, an unidentified state, if we ever visit a visited node that is with this state, then that means a cycle, so we will set the 'cycle' variable as the index of that node, and on the way back our recursive dfs, every node after the node, is going to identify as in_cycle = 1,if we are in that node again, we're going to set the variable 'cycle' to -1, so that it stops identifying node as in_cycle.

The reason why I need this state thing is that ,in a situation, where we have, 

2 1 1 3

The cycle is going to be identified first, before the other node(node that aren't in the cycle). Whenever we're visiting from those node, we might bumped into those cycle, and we need to be able to identify whether the node should be considered as in a cycle or not, appparently no, because the visited node, has in_cycle state = 1. So we're going to set the 'cycle' variable as -1, so every node's in_cycle state after that is going to set as -1.

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

const int MAX = 1e5 + 5;
int next_node[MAX];
bool vis[MAX];
int in_cycle[MAX];
int cycle;

void dfs(int node){
    if (vis[node]){
    	//If we are visiting a visited node and unidentified node, then it's a cycle
        if (in_cycle[node] == 0) cycle = node;
        else cycle = -1;
        return;
    }
    vis[node] = 1;
    dfs(next_node[node]-1);
    if (cycle >= 0){
        in_cycle[node] = 1;
    }else{
        in_cycle[node] = -1;
    }
    if (node == cycle){
        cycle = -1;
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i{}; i < n; i++){
        cin >> next_node[i];
    }

    for(int i{}; i < n; i++){
        if (!vis[i]){
            cycle = -1;
            dfs(i);
        }
    }

    int res = 0;
    for(int i{}; i < n; i++){
        if (in_cycle[i] == 1){
            res++;
        }
    }
    cout << res;
}

int main(){
    setio("shuffle");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```