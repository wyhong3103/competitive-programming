```

One might be tempted to do BFS with priority queue starting from multiple sources with 0.

But this wouldn't be correct, because we're processing all the components simultaneously, the order might get messed up.

So how do we deal with it?

Notice that, if we are to only have the priority queue of one connected component at a time, we can process the order optimally, because the smallest one will definitely get connected before the larger one in the queue, since they are all in the same component.

The problem with processing all components simultaneously is that some small might not get connected and large will get connected, since they are from different component.

So this gave me an idea to process it by components.

This hinted us to use DSU with small to large merging on the queue.

The rest we need to do is just simulating it.

Small to large merging takes N log N (as we learned in DSU), and another log n for insertion and deletion from priority queue.

Total time complexity : O(N log^2 N)

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
    return parent[a] = (parent[a] == a ? a : get(parent[a], parent));
}

bool merge(int a, int b, vi& parent, vi& siz, vector<set<pi>>& q){
    a = get(a, parent);
    b = get(b, parent);

    if (a == b) return true;
    
    if (siz[a] > siz[b]){
        parent[b] = a;
        siz[a] += siz[b];
        for(auto& i : q[b]) q[a].insert(i);
    }else{
        parent[a] = b;
        siz[b] += siz[a];
        for(auto& i : q[a]) q[b].insert(i);
    }
    return true;
}


void solve(){
    int n, m;
    cin >> n >> m;
    
    vi a(n);
    for(auto& i : a) cin >> i;

    vector<vi> adj(n);
    for(int i{}; i < m; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    vi parent(n), siz(n);

    for(int i{}; i < n; i++){
        parent[i] = i;
        siz[i] = 1;
    }

    queue<int> mainq;
    vector<set<pi>> q(n);
    for(int i{}; i < n; i++){
        if (a[i] == 0) {
            mainq.push(i);
            q[i].insert({a[i], i});
        }
    }

    vector<bool> vis(n);

    while(!mainq.empty()){
        int cur = mainq.front(); mainq.pop();
        int p = get(cur, parent);
        while (sz(q[p]) && siz[p] >= q[p].begin()->fir){
            int mn = q[p].begin()->sec;
            q[p].erase(q[p].begin());
            if (vis[mn]) continue;
            merge(mn, p, parent, siz, q);

            vis[mn] = 1;

            for(auto& j : adj[mn]){
                if (!vis[j]){
                    q[p].insert({a[j], j});
                }else{
                    merge(j, p, parent, siz, q);
                }
            }
        }
    }

    cout << (siz[get(0, parent)] == n ? "YES" : "NO") << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

```