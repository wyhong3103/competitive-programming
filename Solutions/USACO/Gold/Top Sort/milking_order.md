```

Basically binary search the first X orders that is valid. We can't do this one by one, we would get TLE.

And with khan's algorithm and priority queue to get the lexicographically smallest order.
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


void solve(){
    int n, m;
    cin >> n >> m;

    vector<vi> obs(m);
    
    for(int i{}; i < m; i++){
        int mi;
        cin >> mi;
        for(int j{};j < mi; j++){
            int x;
            cin >> x;
            x--;
            obs[i].pb(x);
        }
    }

    auto good = [&](int mid){
        vector<vi> adj(n);
        vi indegree(n);
        for(int i{}; i <= mid; i++){
            for(int j{}; j < sz(obs[i])-1; j++){
                adj[obs[i][j]].pb(obs[i][j+1]);
                indegree[obs[i][j+1]]++;
            }
        }

        queue<int> q;
        for(int i{}; i < n; i++){
            if (indegree[i] == 0) q.push(i);
        }

        vi order;
        while (!q.empty()){
            int cur = q.front(); q.pop();
            order.pb(cur);
            for(auto& i : adj[cur]){
                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }
        }
        return sz(order) == n;
    };
    
    int lo = 0, hi = m-1;
    while (hi > lo){
        int mid = lo + (hi-lo+1)/2;
        if (good(mid)){
            lo = mid;
        }else hi = mid-1;
    }
    
    vector<vi> adj(n);
    vi indegree(n);
    for(int i{}; i <= lo; i++){
        for(int j{}; j < sz(obs[i])-1; j++){
            adj[obs[i][j]].pb(obs[i][j+1]);
            indegree[obs[i][j+1]]++;
        }
    }

    priority_queue<int, vi, greater<int>> pq;
    for(int i{}; i < n; i++){
        if (indegree[i] == 0) pq.push(i);
    }

    vi order;
    while (!pq.empty()){
        int cur = pq.top(); pq.pop();
        order.pb(cur);
        for(auto& i : adj[cur]){
            indegree[i]--;
            if (indegree[i] == 0) pq.push(i);
        }
    }
    
    for(int i{}; i < n-1; i++){
        cout << order[i]+1 << ' ';
    }
    cout << order[n-1]+1;
}
int main(){
    setio("milkorder");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```