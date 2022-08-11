This is a really cool DP problem! Let me explain the solution
```
Okay, it took me a while to figure out DP states with lucks of course, i still don't feel like i got the hang of DP yet.

anyway the DP state is [days] [node], [i-th days][j-th node] is going to be storing the maximum value we can gain if we were to end at node j in day i. 

Transition : dp[i+1][k] = max(dp[i][k], dp[i][j] + val[k]), dp[i+1][k] represent the state of the next day, k is a neighbour of j, val[k] is the value of the node. 

If the neighbour k is 0, then we will do ans = max(ans, dp[i][j] - (t+1)^2 * (c)), t+1 because we're only going to stop at k in the next day

I am doing iterative DP for this problem.

MAX T = 1000, actually I wasn't sure what's the maximum size of T, but this is how I came out of it,

MAX N = 1000, MAX VAL = 1000, say T = 1000, and we travelled through all 1000 nodes, the profit is going to be (1000*1000)(1000**2 *1 (c as 1 in the worst case)), 	we're going to get profit as 0, so most probably we won't even need to travel to the 1000th day
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
using pdb = pair<double,double>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

const int MXT = 1000;
const int MXN = 1000;
ll dp[MXT][MXN];
int val[MXN];
vi adj[MXN];
ll n, m, c;
ll ans = 0;

void solve(){
    cin >> n >> m >> c;

    for(int i{}; i < n; i++){
        int v;
        cin >> v;
        val[i] = v;
    }

    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].pb(t);
    }

    //All nodes are inaccessible at first, first node as an exception
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    
    for(int t{}; t < MXT; t++){
        for(int i{}; i < n; i++){
        	//Only access acecssible node
            if (dp[t][i] != -1){
                for(auto& j : adj[i]){
                    if (j == 0){
                        ans = max(dp[t][i] - ((t+1)*(t+1)*c), ans);
                    }
                    if (t+1 < MXT) dp[t+1][j] = max(dp[t+1][j], dp[t][i] + val[j]);
                }
            }
        }
    }

    cout << ans;
}
 
int main(){
    setio("time");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```