```

Greedy on tree problem.

The idea is to

leave every subtree with 2 single branched children.

if one of the chilren is double branched, we need to destruct it and connect it to one of the single branched leaf node

We will first look for a single branched child for each subtree's root. (We will eventually have to reduce it down to <= 2 single branched child). If it doesn't exist, we need to destruct one of the double branched child and make it single branched.

Every double branched child will eventually get connected to it's parent's single branched leaf, because of the property of bamboo.

So basically, we're trying to make every subtree <= 2 single branched children, if it's the root of the tree, we stop there, else it can be connected in a way such that we destruct the connection between the node and it's parent, then left leaf get connected to parent's single branched leaf

how is this optimal??

Every children here are either single branched or double branched, because of the way we solve this problem with subtree.

1. Every root node with > 2 children, have to reduce it down to == 2 (bamboo)
2. Always best to leave it as 2, because if it's connected to other above, we simply need to remove the edge and add it to the leaf of the current node. That would only cost 1, while removing it to 1, cost 1, if it's connected to above and not <= 2, it might even + 1 again. reduced.
3. at each root, we need to reduce it down to <= 2 children, find at least one single branched start merging all the twos

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

void dfs(int node,int prev, vector<vi>& res, vector<vi>& adj, vector<pi>& child, vector<pi>& leaf){
    child[node].fir = -1;
    child[node].sec = -1;
    leaf[node].fir = -1;
    leaf[node].sec = -1;

    for(auto& i : adj[node]){
        if (i == prev) continue;
        dfs(i, node, res, adj, child, leaf);
    }

    //Try to find single branched child, best if we can find two
    for(auto& i : adj[node]){
        if (i == prev) continue;
        if (leaf[i].fir >= 0 && leaf[i].sec == -1 && leaf[node].fir == -1){
            child[node].fir = i;
            leaf[node].fir = leaf[i].fir;        
        }else if (leaf[i].fir >= 0 && leaf[i].sec == -1 && leaf[node].sec == -1){
            child[node].sec = i;
            leaf[node].sec = leaf[i].fir;        
        }
    }

    //reduce one of the double branched node to single branch
    if ((child[node].fir == -1 && sz(adj[node]) >= 2) || (prev == -1 && child[node].fir == -1)){
        if (adj[node][0] == prev) swap(adj[node][0], adj[node][1]);
        child[node].fir = adj[node][0];
        res.pb({child[adj[node][0]].sec, adj[node][0], leaf[adj[node][0]].fir, child[adj[node][0]].sec});
        leaf[node].fir = leaf[adj[node][0]].sec;
    }

    //start merging the branches!
    if (child[node].fir != -1){
        for(auto& i : adj[node]){
            if (i == prev || i == child[node].fir || i == child[node].sec) continue;
            res.pb({i, node, leaf[i].fir, leaf[node].fir});
            if (leaf[i].sec != -1) leaf[node].fir = leaf[i].sec;
            else leaf[node].fir = i;
        }
    }

    //leaf node
    if (child[node].fir == -1){
        child[node].fir = node;
        leaf[node].fir = node;
    }
}

void solve(){
    int n;
    cin >> n;

    vector<vi> adj(n);
    vector<vi> res;
    vector<pi> child(n);
    vector<pi> leaf(n);

    for(int i{}; i < n-1; i++){
        int f,t ;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    dfs(0, -1, res, adj, child, leaf);
    cout << sz(res) << '\n';
    for(auto& i : res){
        for(auto& j : i)
        cout << j+1 << ' ';
        cout << '\n';
    }
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