My first graph/tree problems, ay! Felt pretty good. <br>
This problem is about finding the highest degree of a node + 1, we don't want the cow to complain, that's why we need to fulfill their requirement and spend less money at the same time.
<br>
Link to problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=894

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
    }


void solve(){
    int n;
    cin >> n;
    vector<int> adj(n);
    fill(all(adj),0);
    int ans{};
    for(int i{}; i < n-1; i++){
        int to, end;
        cin >> to >> end;
        adj[to-1]++;
        adj[end-1]++;
        ans = max({ans, adj[to-1], adj[end-1]});
    }
    cout << ans+1;
    
}

int main(){
    setIO("planting");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
 
    return 0;
}


```