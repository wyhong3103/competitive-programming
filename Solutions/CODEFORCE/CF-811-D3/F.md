A quite interesting problem.
```

First observation, 

d12 , d23, and d31 are all relative to each other. In order to form a valid graph, they all have to fulfill each other.

Which lead to the below,

Notice that there are only 2 ways to form the tree graph without forming a cycle, and maintaining the distance.

1 ---- 2 ---- 3


1 ----- x ------3
		|
		|
		2

And 1,2,3 can be any permutation of them.

Actually, the first way of forming is just the same as the secone one, only 2 is x right now, the length from 2 to center is 0.

In order to form a valid graph, they have to fulfill the system of equations below.

    x       z      
1 ----- x ------3
		|
    y	|
		2

x + y = d12
y + z = d23
x + z = d13

x,y,z have to be greater or equal to 0, and have to be an integer, the reason is that there can be no fractioned edges.

And after rearranging the equation.

x = (d12-d23+d13)/2
y = d12-x
z = d31-x

And then, we can simply start by forming the branch of each without the center node x.

If x = 0, then first node is the center node, same geos to y and z.

There will not be 2 distance equal to 0 if the equation is valid.

Then simply, connect all the branch to the center node, and print the answer.
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    bool ok = 0;
    
    vi dist(3);

    if ((a-b+c) % 2 == 0){
        dist[0] = (a-b+c)/2; 
        dist[1] = a-dist[0];
        dist[2] = c-dist[0];
        int sm = 0;
        bool ok_temp = 1;
        for(auto& i : dist){
            if (i < 0) ok_temp = 0;
            sm += i;
        }

        ok = (ok_temp && sm+1 <= n);
    }

    if (!ok){
        cout << "NO" << '\n';
        return;
    }

    vector<vi> adj(n);
    set<int> nodes;
    for(int i{3}; i < n; i++) nodes.insert(i);

    int center = -1;
    vi branch;
    for(int i{}; i < 3; i++){
        int cur = i;
        if (!dist[i]) center = i;
        while (dist[i]-1 > 0){
            if (nodes.empty()){
                ok = 0;
                break;
            }
            adj[cur].pb(*nodes.begin());
            cur = *nodes.begin();
            nodes.erase(cur);
            dist[i]--; 
        }
        if (center != i) branch.pb(cur);
    }
    
    if (center == - 1 && nodes.empty()) ok = 0;

    if (!ok){
        cout << "NO" << '\n';
        return;
    }else{
        if (center == -1){
            center = *nodes.begin();
            nodes.erase(center);
        }
        for(auto& i : branch){
            adj[center].pb(i);
        }
        while (!nodes.empty()){
            adj[0].pb(*nodes.begin());
            nodes.erase(adj[0].back());
        }
    }

    cout << "YES" << '\n';
    for(int i{}; i < n; i++){
        if (sz(adj[i])){
            for(auto& j : adj[i]) cout << i+1 << ' ' << j+1 << '\n';
        }
    }
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