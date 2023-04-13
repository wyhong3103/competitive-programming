```

dp[i][j] = max increasing edges length s.t the last edge connects to node i and last edge has weight of j

We can do a DAG like DP, we process all the edges from smallest one, because that would be acyclic, as we always process smallest one before largest first, finally we can get the longest.

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

struct Edge{
    int f,t,w;
    
    operator <(Edge& y) const{
        return (y.w > w);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    vector<map<int,int>> dp(n);

    for(int i{}; i < n; i++) dp[i][0] = 0;

    vector<Edge> edges;
    for(int i{}; i < m; i++){
        int f,t,w;
        cin >> f >> t >> w;
        f--;t--;
        edges.pb({f,t,w});
    }

    sort(all(edges));

    int res = 0;
    for(auto& i : edges){
        int mx = (--dp[i.f].lower_bound(i.w))->sec;
        
        dp[i.t][i.w] = max(dp[i.t][i.w], (--dp[i.t].lower_bound(i.w))->sec);
        dp[i.t][i.w] = max(dp[i.t][i.w], mx + 1);

        res = max(dp[i.t][i.w], res);
    }
    cout << res;

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