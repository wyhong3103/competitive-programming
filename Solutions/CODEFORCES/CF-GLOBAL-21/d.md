2 pointers to construct the graph, then bfs to find the shortest path.
```
The fact that only when min(i,j) = a[i] and max(i,j) = a[j] / min(i,j) = a[j] and max(i,j) = a[i] fulfilled , only we can add an edge between i and j

Now let's split it into a few different cases

When the current relation is maximum to minimum (p1 is maximum, p2 is minimum)
- If found a smaller element than a[p2], add an edge to p1 and p2
- If found a larger element than a[p1], set p1 to the current minimum node, change the current relation to min to max, add an edge to p1 and p2

When the current relation is minimum to maximum (p1 is minimum, p2 is maximum)
- If found a larger element than a[p2], add an edge to p1 and p2
- If found a smaller element than a[p1] , set p1 to the current to the current maximum node, change the current relation to max to min, add an edge to p1 and p2

If the new maximum/minimum is the absolute minimum/maximum of an array
- If we found the global minimum, we should change our relation to min to max, and set p1 to the global minimum, and p2 to the next element, and reset the maximum element as 0, because if we found a global minimum, there's no point that we continue searching for a smaller element than that, so we set it as p1, and the reason we reset the maximum is because we're basically starting from the global minimum, and every element that is bigger than it should be considered
- same thing geos to maximum

Also, notice that , we don't need to use an adjacent list, we only need to store the furthest node we can go from each node i, this is because if we can go to a further node, we didn't need to consider the node before it, because there is no way that the previous node have a path further than the node
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
 

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i{}; i < n; i++){
        cin >> a[i];
    }

    vi dist(n);
    vi adj(n);
    fill(all(dist), -1);
    fill(all(adj), -1);

    set<int> remain;
    for(int i{1}; i <= n; i++) remain.insert(i);


    int p1 = 0, p2 = 1;
    //mn, max, mx to mn or mn to mx
    pi mn {a[p1], 0};
    pi mx {a[p1], 0};
    int currel = (n >= 2 ? (a[p1] < a[p2]) : 0) ;
    remain.erase(a[p1]);

    while (p2 < n){
        if (a[p2] > mx.fir){
            mx.fir = a[p2];
            mx.sec = p2;
        }else if (a[p2] < mn.fir){
            mn.fir = a[p2];
            mn.sec = p2;
        }
        remain.erase(a[p2]);
        adj[p2-1] = max(adj[p2-1], p2);

        if (!currel){
            //mx to mn
            if (a[p1] != mx.fir){
                //to mn to mx
                p1 = mn.sec; 
                adj[p1] = max(adj[p1], p2);
                currel = 1;
            }else if (a[p2] == mn.fir && p1 != p2-1){
                adj[p1] = max(adj[p1], p2);
            }
        }else{
            //mn to mx
            if (a[p1] != mn.fir){
                //to mx to mn
                p1 = mx.sec; 
                currel = 0;
                adj[p1] = max(adj[p1], p2);
            }else if (a[p2] == mx.fir && p1 != p2-1){
                adj[p1] = max(adj[p1], p2);
            }
        }

        if (!sz(remain)) break;
        else if (mn.sec == p2 && mn.fir < (*remain.begin())){
            p1 = mn.sec;
            mx.fir = 0;
            currel = 1;
        }else if (mx.sec == p2 && mx.fir > (*(--remain.end()))){
            p1 = mx.sec;
            mn.fir = INT_MAX;
            currel = 0;
        }
        p2++;
    }

    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()){
        int s = q.front(); q.pop();
        if (dist[adj[s]] != -1) continue;
        dist[adj[s]] = dist[s]+1;
        q.push(adj[s]);
    }
    
    cout << dist[n-1] << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
```

Or prefix min/max array, then binary search on it