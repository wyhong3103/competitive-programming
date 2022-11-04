```
each vertex has l and r <= 1e9

we need to assign ai such that li <= ai <= ri to each vertex i, and to maximize sum of |ai - aj| for every edge(i, j)


it is always optimal to place either on L or R

situation 1

we have to point, one >= R, another one <= L

it doesn't matter where we place it, diff of both still the same

situation 2

we have point inside [L,R]

it's definitely best to place it at border!

situation 3

we have point inside[L,R] and outside [L,R]

puting in border produce optimal as well
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

void dfs(int node, int prev, vector<pll>& a, vector<vi>& adj, vector<vll>& dp){
    for(auto& i : adj[node]){
        if (i == prev) continue;
        dfs(i, node, a, adj, dp);
    }

    for(auto& i : adj[node]){
        if (i == prev) continue;
        //at L
        dp[node][0] += max(abs(a[node].fir - a[i].fir) + dp[i][0], abs(a[node].fir - a[i].sec) + dp[i][1]);
        //at R
        dp[node][1] += max(abs(a[node].sec - a[i].fir) + dp[i][0], abs(a[node].sec - a[i].sec) + dp[i][1]);
    }
}

void solve(){
    int n;
    cin >> n;

    vector<vi> adj(n);
    vector<vll> dp(n, vll(2));

    vector<pll> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;

    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    dfs(0, -1, a, adj, dp);

    cout << max(dp[0][0], dp[0][1]) << '\n';
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