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

const int MAX = 2e5+5;
vi adj[MAX];
bool vis[MAX];
int ans[MAX];

int dfs(int node){
    vis[node] = 1;
    int count = 0;
    for(auto& i : adj[node]){
        if (!vis[i]){
            count += dfs(i);
            count++;
        }
    }
    ans[node] = count;
    return count;
}

void solve(){
    int n;
    cin >> n;
    for(int i{}; i < n-1; i++){
        int h;
        cin >> h;
        h--;
        adj[h].pb(i+1);
        adj[i+1].pb(h);
    }
    
    dfs(0);
    for(int i{}; i < n; i++){
        cout << ans[i] << ' ';
    }
    
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```

Uhh, a DP way of doing it?
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

const int MAX = 2e5+5;
vi adj[MAX];
int ans[MAX];

void dfs(int node, int prev){
    ans[node] = 1;
    for(auto& i : adj[node]){
        if (node != i){
            dfs(i, node);
            ans[node] += ans[i];
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i{}; i < n-1; i++){
        int h;
        cin >> h;
        h--;
        adj[h].pb(i+1);
    }
    
    dfs(0, 0);
    for(int i{}; i < n; i++){
        cout << ans[i]-1 << ' ';
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
```