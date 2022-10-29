Finally an interesting problem! Well, this problem requires a little observation. First the problem stated that every node has only one indegree, and every node has one outdegree. So it's fairly obvious the entire subway is a cycle, or multiple cycles. With two moves we can essentailly, connects up two largest cycle. And the number of ordered pairs is simply nP2 + n, n = number of node in a cycle, for every cycle.
```cpp
#include <bits/stdc++.h>
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
int adj[MAX];
//Comp = component, it stores the component size
int comp[MAX];
bool vis[MAX];

void dfs(int node, int& cnt){
    if (vis[node]) return;
    vis[node] = 1;
    cnt++;
    dfs(adj[node], cnt);
}

ll permutation(int n, int r){
    ll res = 1;
    for(int i{n}; i > n-r; i--){
        res *= i; 
    }
    return res;
}

void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n; i++){
        int t;
        cin >> t;
        t--;
        adj[i] = t;
    }
    
    int len = 1;
    for(int i{}; i < n; i++){
        if (!vis[i]){
            int cnt = 0;
            dfs(i, cnt);
            comp[len-1] = cnt;
            len++;
        }
    }

    sort(comp, comp+len, greater<int>());
    
    if (len == 1){
        cout << 1+permutation(comp[0],2);
    }{
        ll res = (comp[0]+comp[1]) + (permutation(comp[0]+comp[1],2));
        for(int i{2}; i < len; i++){
            res += permutation(comp[i], 2) + comp[i];
        }
        cout << res;
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```