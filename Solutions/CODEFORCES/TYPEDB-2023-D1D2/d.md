```

if can end game from original seq,

	if current node, i is reachable from 1,

		ans += n + 1 (out of bounds) + size[cur component] - total nodes that can reach i (we want to avoid creating cycle) + (total nodes that can end game - size[cur component])

	else,

		// if the current node is unreachable from 1, we can basically set it to anywhere and still win

		ans += 2*n+1

else,

	if current node, i is reachable from 1,

		ans += n + 1 (out of bounds) + total nodes that can end game

	else do nothing


The above is fairly obvious, it's just that we need to implement properly.

We can find all the components that are connected (though its directed but it doesn't matter, if a node can win the game, every node that can reach the node can also win the game) using DSU and keep track of its size & whether it can win.

To find the nodes that can reach i, we do dp. Find top sort order, and then count the total nodes before node i.

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



int get(int a, vi& parent){
    return parent[a] = (parent[a] == a ? parent[a] : get(parent[a], parent));
}

bool merge(int a, int b, vi& parent, vi& ranking, vi& size, vi& win){
    a = get(a, parent);
    b = get(b, parent);
    
    if (a == b) return false;

    if (ranking[a] == ranking[b]) ranking[a]++;

    if (ranking[a] > ranking[b]){
        parent[b] = a;
        size[a] += size[b];
        win[a] |= win[b];
    }else{
        parent[a] = b;
        size[b] += size[a];
        win[b] |= win[a];
    }
    return true;
}

// to generate topsort order
void dfs(int node, vi& nxt, deque<int>& order, set<int>& vis){
    if (vis.count(node)) return;
    vis.insert(node);
    if (nxt[node] != -1){
        dfs(nxt[node], nxt, order, vis);
    }
    order.push_front(node);
}

//find nodes that are reachable
void dfs2(int node, vi& nxt, vi& reachable, set<int>& vis){
    if (vis.count(node)) return;
    vis.insert(node);
    reachable[node] = 1;
    if (nxt[node] != -1){
        dfs2(nxt[node], nxt, reachable, vis);
    }
}

void solve(){
    int n;
    cin >> n;

    vi parent(n);
    for(int i{}; i < n;i++) parent[i] = i;
    vi ranking(n);
    vi size(n, 1);
    vi win(n);

    vi nxt(n);
    //if point to -1 then winning state

    for(int i{}; i < n; i++){
        int t;
        cin >> t;
        if (i+t >= n || i+t < 0){
            nxt[i] = -1;
            win[get(i, parent)] = 1;
        }
        else{
            nxt[i] = i+t;
            merge(i, i+t, parent, ranking, size, win);
        }
    }

    vi bf(n);
    //number of nodes that can reach it
    vi dp(n, -1);
    vi reachable(n);
    deque<int> order;
    set<int> vis;
    dfs2(0, nxt, reachable, vis);

    if (win[get(0, parent)]){
        vis.clear();
        for(int i{}; i < n; i++){
            if (get(0, parent) == get(i, parent) && !vis.count(i)){
                dfs(i, nxt, order, vis);
            }
        }

        for(auto& i : order){
            if (dp[i] == -1) dp[i] = 0;
            if (nxt[i] != -1 && dp[nxt[i]] == -1) dp[nxt[i]] = 0;
            if (nxt[i] != -1) dp[nxt[i]] += dp[i] + 1;
        }
    }


    int possible = 0;
    set<int> selected;
    for(int i{}; i < n; i++){
        int p = get(i, parent);
        if (win[p] && !selected.count(p)){
            possible += size[p];
            selected.insert(p);
        }
    }

    ll total = 0;
    for(int i{}; i < n; i++){
        if (win[get(0, parent)]){
            if (reachable[i]){
                total += n+1 + (size[get(i, parent)] - dp[i] - 1) + (possible-size[get(i, parent)]);
            }else{
                total += 2*n + 1;
            }
        }else{
            if (reachable[i]){
                total += n+1 + possible;
            }
        }
    }   

    cout << total << '\n';
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