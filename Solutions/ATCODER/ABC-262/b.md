There might be a better way to do this, but im doing this purely for speed.
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
 
 
set<int> adj[100];
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].insert(t);
        adj[t].insert(f);
    }
 
    set<set<int>> s;
    for(int i{}; i < n; i++){
        if (sz(adj[i]) >= 2){
            for(auto& j : adj[i]){
                for(auto& k : adj[i]){
                    if (k == j) continue;
                    if (adj[k].count(j) && adj[k].count(i) && adj[j].count(k) && adj[j].count(i)){
                        s.insert({i, j, k});
                    }
                }
            }
        }
    }
 
    cout << sz(s);
 
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