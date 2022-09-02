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


const int MX = 2e5+5;
int comp_sz[MX];
int parent[MX];
    
int dsu_get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a]));
}

void dsu_union(int a, int b, int& total){
    a = dsu_get(a);
    b = dsu_get(b);
    
    if (a == b) return;

    if (comp_sz[a] > comp_sz[b]){
        parent[b] = a;
        comp_sz[a] += comp_sz[b];
    }else{
        parent[a] = b;
        comp_sz[b] += comp_sz[a];
    }
    //Every time the above operation happens, there will be one less component
    total--;
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < n; i++){
        parent[i] = i;
        comp_sz[i] = 1;
    }

    vector<vi> adj(n);
    for(int i{}; i < m; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    
    vi orders(n);
    for(auto& i : orders){
        cin >> i;
        i--;
    }

    vi res(n);
    set<int> exist;

    int total = 0;
    for(int i{n-1}; i >= 0; i--){
    	//One new component
        total++;
        for(auto& j : adj[orders[i]]){
            if (!exist.count(j)) continue;
            dsu_union(orders[i], j, total);
        }
        res[i] = (total == 1);
        exist.insert(orders[i]);
    }

    for(auto& i : res){
        cout << (i ? "YES" : "NO") << '\n';
    }

}

int main(){
    setio("closing");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```