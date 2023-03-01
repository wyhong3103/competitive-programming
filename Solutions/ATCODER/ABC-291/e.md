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
 
const int MX = 2e5 + 5;
set<int> adj[MX];
bool vis[MX];
 
void dfs(int node, deque<int>& q){
    if (vis[node])  return;
    vis[node] = 1;
 
    for(auto& i : adj[node]){
        dfs(i, q);
    }
 
    q.push_front(node);
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    for(int i{}; i < m; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].insert(t);
    }
 
    deque<int> q;
    for(int i{}; i < n; i++){
        if (!vis[i]) dfs(i, q);
    }
 
    vi p;
    for(auto& i : q){
        p.pb(i);
    }
 
    bool ok = 1;
    for(int i{}; i < n-1; i++){
        ok &= adj[p[i]].count(p[i+1]);
    }
 
    if (ok){
        cout << "Yes" << '\n';
        vi res(n);
        for(int i{}; i < n; i++) res[p[i]] = i;
 
        for(auto& i :res) cout << i+1 << ' ';
    }else cout << "No";
 
 
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