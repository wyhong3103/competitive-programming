Forming a tree, and make a difference array, and print it.
<br>
[Problem](https://www.hackerrank.com/contests/codenection-2021-open-category-preliminary/challenges/assignment-interviews/problem)

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


const int MAX = 200005;

vi adj[MAX];
int diff[MAX];
int ans[MAX];
bool vis[MAX];

void dfs(int node, int cur){
    if (vis[node]) return;
    vis[node] = true ;
    cur += diff[node];
    ans[node] = cur;
    for(auto& i : adj[node]){
        dfs(i, cur);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    
    for(int i{}; i < n-1; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
        adj[t].pb(f);
    }

    for(int i{}; i < q; i++){
        int node, x;
        cin >> node >> x;
        node--;
        diff[node]+=x;
    }
    
    dfs(0,0);

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