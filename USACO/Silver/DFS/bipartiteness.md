Using set.
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MAX = 1e5 + 5;
set<int> adj[MAX];
bool vis[MAX];
bool color[MAX];
pi cnt;


void dfs(int node){
    vis[node] = true;
    if (color[node]) cnt.fir++;
    else cnt.sec++;
    
    for(auto& i : adj[node]){
        if (!vis[i]){
            color[i] = !color[node];
            dfs(i);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].insert(t);
        adj[t].insert(f);
    }
    dfs(0);

    ll ans = 0;
    for(int i{}; i < n; i++){
        ans +=  (color[i] ? cnt.sec : cnt.fir);
        ans -=  sz(adj[i]);
        for(auto& j : adj[i]){
            adj[j].erase(i);
        }
        if (color[i]){
            cnt.fir--;
        }else{
            cnt.sec--;
        }
    }
    cout << ans;
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```

Alternative, faster , and more efficient, using combinatorics, red count * blue count - connected edges
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MAX = 1e5 + 5;
vi adj[MAX];
bool vis[MAX];
bool color[MAX];
pi cnt;


void dfs(int node){
    vis[node] = true;
    if (color[node]) cnt.fir++;
    else cnt.sec++;
    
    for(auto& i : adj[node]){
        if (!vis[i]){
            color[i] = !color[node];
            dfs(i);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }
    dfs(0);

    ll ans = (ll)cnt.fir * cnt.sec - (n-1);
    cout << ans;
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```