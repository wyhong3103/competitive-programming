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
const int ME = __lg(MX) + 5;
vi adj[MX];
int up[MX][ME];

void dfs(int node, int prev){
    if (node) up[node][0] = prev;
    for(auto& i : adj[node]){
        if (i != prev) dfs(i, node);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i{1}; i < n; i++){
        int p;
        cin >> p;
        p--;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    memset(up, -1, sizeof(up));

    dfs(0, -1);

    //preprocess
    for(int i{1}; i < ME; i++){
        for(int j{1}; j < n; j++){
            if (up[j][i-1] != -1) up[j][i] = up[up[j][i-1]][i-1];
        }        
    }

    while(q--){
        int x, k;
        cin >> x >> k;
        x--;
        int node = x;
        for(int i{}; i < ME; i++){
            if (node != -1 && k & (1 << i)) node = up[node][i];
        }
        cout << (node == -1 ? -1 : node+1) << '\n';
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