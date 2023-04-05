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
vi adj[MX];
map<int,int> kcestor[MX];

void dfs(int node, int prev, vi& a){
    for(auto& i : kcestor[node]){
        if (i.fir > sz(a)) break;
        kcestor[node][i.fir] = a[sz(a)-i.fir];
    }

    a.pb(node);

    for(auto& i : adj[node]){
        if (i == prev) continue;
        dfs(i, node, a);
    }
    a.pop_back();
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i{1}; i <= n-1; i++){
        int p;
        cin >> p;
        p--;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    vector<pi> res;
    while(q--){
        int x, k;
        cin >> x >> k;
        x--;
        kcestor[x][k] = -2;
        res.pb({x, k});
    }
    vi a;
    dfs(0, -1, a);
    
    for(auto& i : res){
        cout << kcestor[i.fir][i.sec]+1 <<'\n';
    }
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