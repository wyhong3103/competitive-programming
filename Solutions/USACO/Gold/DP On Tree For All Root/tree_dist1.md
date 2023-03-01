```

I previously bricked this problem bc of the implmentation error.

Code below is from solution on USACO Guide.

There is something to take note of,

First DFS function mainly focus on subtree DP.

Second DFS function has a p variable (answer for parent s.t the answer is not related to the current child). Basically in second DFS function, all value we could access will be valid, and we have to be careful with passing a new p to the next child!

I like how they implemented this kind of DP, I will adapt to this way.

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

const int MX = 2e5 + 5;
vi adj[MX];
int fir[MX];
int sec[MX];
int ans[MX];

void dfs(int node, int prev){
    for(auto& i : adj[node]){
        if (i != prev){
            dfs(i, node);
            if (fir[i] + 1 > fir[node]){
                sec[node] = fir[node];
                fir[node] = fir[i]+1;
            }else{
                sec[node] = max(sec[node], fir[i]+1);
            }
        }
    }
}

void dfs2(int node, int prev, int p){
    ans[node] = max(p, fir[node]);

    for(auto& i : adj[node]){
        if (i != prev){
            dfs2(i, node, max(p, (fir[node] == fir[i]+1 ? sec[node] : fir[node]))+1);
        }
    }
}


void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n-1; i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    dfs(0, -1);
    dfs2(0, -1, -1);

    for(int i{}; i < n; i++) cout << ans[i] << '\n';
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