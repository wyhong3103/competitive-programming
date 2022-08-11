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

const int MAX = 5005;
vector<pi> adj[MAX];

void dfs(int node, int prev, int k, int& count){
    for(auto& i : adj[node]){
        if (i.fir != prev){
        	//Do not visit a path, if it's relevance is smaller than K, since every otther node's relevance after it will be at most this value, so it will not be considered as wells 
            if (i.sec < k) continue;        
            count++;
            dfs(i.fir, node, k, count);
        }
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    
    for(int i{}; i < n-1; i++){
        int f, t, r;
        cin >> f >> t >> r;
        adj[f].pb({t,r});
        adj[t].pb({f,r});
    }
    
    for(int i{}; i < q; i++){
        int k, v;
        cin >> k >> v;
        int count = 0;
        dfs(v, -1, k, count);
        cout << count << '\n';
    }
}

int main(){
    setio("mootube");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```