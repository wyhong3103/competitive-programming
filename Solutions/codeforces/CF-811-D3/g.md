```
This is fairly simple, we simply need an array to keep track of the prefix sum of a, and we can find all of this with a dfs.

The next dfs, we can have an array of prefix value taken, to reach the i node. And simply binary search the array to get the length of prefix such that the value of the prefix <= sum_a[i].
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
 
 
void dfs_a(int node, int prev, ll sm,vector<vi>& adj, vector<pll>& val, vll& sm_a){
    sm_a[node] = sm;
    for(auto& i : adj[node]){
        if (i != prev){
            dfs_a(i, node, sm+val[i].fir, adj, val, sm_a);
        }
    }
}
 
void dfs_b(int node, int prev,ll cur ,vll& sm, vector<vi>& adj,vector<pll>& val,vll& sm_b, vll& sm_a){
    sm_b[node] = upper_bound(all(sm),sm_a[node])-sm.begin();
    for(auto& i : adj[node]){
        if (i != prev){
            sm.pb(cur+val[i].sec);
            dfs_b(i, node,cur+val[i].sec,sm, adj, val, sm_b, sm_a);
            sm.pop_back();
        }
    }
}
 
void solve(){
    int n;
    cin >> n;
 
    vector<vi> adj(n);
    vector<pll> val(n);
    vll sm_a(n);
    vll sm_b(n);
 
    for(int i{1}; i < n; i++){
        int p, a, b;
        cin >> p >> a >> b;
        p--;
        adj[i].pb(p);
        adj[p].pb(i);
        val[i].fir = a;
        val[i].sec = b;
    }
 
    dfs_a(0,-1,0, adj, val, sm_a);
 
    vll sm;
    dfs_b(0,-1,0,sm, adj, val, sm_b, sm_a);
    for(int i{1}; i < n; i++) cout << sm_b[i] << ' ';
    cout << '\n';
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