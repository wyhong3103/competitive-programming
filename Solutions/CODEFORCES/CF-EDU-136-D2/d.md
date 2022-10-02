```

I do not solve this durinng contest, got terrified by it.....

Anyway, it is very simple (not by the look of it of course.)

So first, let's ask ourself what is the minimal cut needed in order to make the depth x.

Notice that, each time we make a cut, the subtree we cut is being connected to the root, and the depth of the subtree is depth of the current root of the subtree.

So that basically implied that cutting a subtree with max depth < x, is useless. Though it might reduce certain depth of a subtree, but an optimal choice to make the depth x, is by creating more subtree that is connected to the root directly that has depth of x.

Basically cutting the deepest subtree is the optimal move to do.

Now with this idea, it became obvious that the lower x we do, the more cut we need.

So here comes binary search.

For every subtree, (from leaf to root), if the max depth of one of the branch has depth == mid, we cut it, and add count, else we set the current depth of the subtree and that length, and then return it to the ancestor.

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

int dfs(int node, vector<vi>& adj, int& cnt, int mid){
    int depth = 0;
    for(auto& i : adj[node]){
        int sub_depth = dfs(i, adj, cnt, mid)+1;
        if (node != 0 && sub_depth >= mid){
            cnt++;
        }else depth = max(depth, sub_depth);
    }
    return depth;
}

void solve(){
    int n, k;
    cin >> n >> k;
    
    vector<vi> adj(n);
    for(int i{}; i < n-1; i++){
        int p;
        cin >> p;
        p--;
        adj[p].pb(i+1);
    }

    int lo = 1, hi = n;
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        int cnt = 0;
        dfs(0, adj, cnt, mid);
        if (cnt <= k){
            hi = mid;
        }else lo = mid+1;
    }

    cout << lo << '\n';
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