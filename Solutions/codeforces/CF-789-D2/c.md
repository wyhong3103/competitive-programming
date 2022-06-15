A recursive problem, involved a little memoization.
```
So at each seconds(n), infection happens, either to the left or the right, it's not always optimal to always delete the branch with more children, for several reasons. (Check out test case sample 3).

So there's really nothing that you can be greedy with.

So the idea is to simply recursively find the solution, and there will be no repeated state, so a recursive solution works in O(N) time, and we can memoize the number of children of each node, so that we won't compute the same thing over and over again.
```

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
 
const int MAX = 3e5;
vi adj[MAX];
int memo_child[MAX];
 
int count_child(int node, int prev){
    if (memo_child[node] != -1) return memo_child[node];
    int& cnt = memo_child[node] = 1;
    for(auto& i : adj[node]){
        if (i != prev){
            cnt += count_child(i, node);
        }
    }
    return cnt;
}
 
int dfs_infect(int node, int prev){
    vector<pi> choice;
    for(auto& i : adj[node]){
        if (i != prev){
            choice.pb({i, count_child(i, node)}); 
        }
    }  
    int mx = 0;
 	
 	//If only one child, there's no need for infection
    if (sz(choice) == 1){
        return choice[0].sec-1;
    }else if (sz(choice) == 2){
        //infect right
        mx = max(mx, dfs_infect(choice[0].fir, node) + (choice[1].sec-1));
 
        //infect left
        mx = max(mx, dfs_infect(choice[1].fir, node) + (choice[0].sec-1));
    }
 
    return mx;
}
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
 
        memset(memo_child, -1, sizeof(memo_child));
 
        for(int i{}; i < n-1; i++){
            int fr,to;
            cin >> fr >> to;
            fr--;to--;
            adj[fr].pb(to);
            adj[to].pb(fr);
        }
 
        cout << dfs_infect(0, -1) << '\n';
 
        for(int i{}; i < n; i++){
            adj[i].clear();
        }
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
 
```