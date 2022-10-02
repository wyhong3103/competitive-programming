```

Had the right idea at first. That we only need to split K-1 nodes out in order to find the maxi min edge between the nodes.

Anyway, I've decided to generate all the edge beween nodes (N^2) and sort them (N^2 log N^2), and then by using kruskal, to remove all the minimal edge weight (by merging two node into one component) until the total number of component goes below k, and then we take the previous edge weight, as that is the answer.

But the above is too slow for this problem, it has strict time complexity.

Honestly, the method I was using wasn't really a MST algorithm. I haven't consider properly.

Let me explain the AC approach.

First off, in an optimal way of dividing them into K groups, we can notice that each cluster itself is interally a MST, because that guaranteed us the edge weight between this cluster and other cluster is maximized. As we're putting all the minimal edge weight in a cluster (which wouldn't be considered as an edge).

So the idea is to find the MST, and split K-1 nodes out (which is the K-1 nodes with maximal edge weight in the MST). And by doing this the answer is naturally K-1-th largest edge weight. You might be tempted to think that whenever we put it out of the current cluster, the extra new edge might be the maximal, but no, remember this is MST we're talking about, the minimal weight on the edge, so if it's being put out it will be the minimal as well. 

Due to the strict time complexity, we need to do this in exact O(N^2), which can be done by Prim's Algorithm in Dense Graph. Strict time complexity doesn't even allow us to create an adjacency matrix!
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

const int MX = 7505;
const ll MOD = 2019201997;
const ll X = 2019201913;
const ll Y = 2019201949;

void solve(){
    int n, k;
    cin >> n >> k;
    
    vll min_e(n, LONG_LONG_MAX);
    vector<bool> selected(n);
    min_e[0] = 0;

    vll edges;

    for(int i{}; i < n; i++){
        int v = -1;
        for(int j{}; j < n; j++){
            if (!selected[j] && (v == -1 || min_e[v] > min_e[j])){
                v = j;
            }
        }

        selected[v] = 1;
        edges.pb(min_e[v]);

        for(int i{}; i < n; i++){
            min_e[i] = min(min_e[i], ((min(v+1, i+1) * X) % MOD + (max(v+1, i+1) * Y)  % MOD) % MOD);
        }
    }    

    sort(all(edges));

    cout << edges[n-(k-1)];
}

int main(){
    setio("walk");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```