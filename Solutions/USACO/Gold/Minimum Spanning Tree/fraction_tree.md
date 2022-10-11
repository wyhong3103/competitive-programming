https://www.hackerrank.com/contests/w31/challenges/spanning-tree-fraction/editorial
```

We are to form a spanning tree and maximize sum(a)/sum(b)!


Notice that we can binary search this value!

sum(a)/sum(b) >= C

Let there be some C.


sum(a) >= C * sum(b)

sum(a) - (C * sum(b)) >= 0


We can let the above be the weight of the graph, and then simply binary search C and form the MST.

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
    
int dsu_get(int a, vi& parent){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a], parent));
}

bool dsu_union(int a, int b, vi& ranking, vi& parent){
    a = dsu_get(a, parent);
    b = dsu_get(b, parent);
    
    if (a == b) return false;

    if (ranking[a] == ranking[b]) ranking[a]++;

    if (ranking[a] > ranking[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
    return true;
}

struct Edge{
    int f, t, a, b;
};

ll gcd(ll a, ll b){
    return (!b ? a : gcd(b, a % b));
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for(auto& i : edges){
        cin >> i.f >> i.t >> i.a >> i.b;
    }

    double lo = 0, hi = 1e6;
    for(int i{}; i < 100; i++){
        double mid = lo + (hi-lo)/2;
        vector<pair<double, pi>> edges_temp;
        for(int i{}; i < m; i++){
            edges_temp.pb({edges[i].a-(edges[i].b * mid), {edges[i].f, edges[i].t}});
        }

        sort(all(edges_temp), greater<pair<double,pi>>());
        
        vi parent(n);
        vi ranking(n);
        for(int i{}; i < n; i++) parent[i] = i;

        double total = 0;
        for(auto& i :edges_temp){
            if (dsu_union(i.sec.fir, i.sec.sec, ranking, parent)) total += i.fir;
        }

        if (total >= 0){
            lo = mid;
        }else hi = mid;
    }

    vector<pair<double, pair<pi,int>>> edges_temp;
    for(int i{}; i < m; i++){
        edges_temp.pb({edges[i].a-(edges[i].b * lo), {{edges[i].f, edges[i].t}, i}});
    }

    sort(all(edges_temp), greater<pair<double,pair<pi,int>>>());
    
    vi parent(n);
    vi ranking(n);
    for(int i{}; i < n; i++) parent[i] = i;

    vi used;
    for(auto& i :edges_temp){
        if (dsu_union(i.sec.fir.fir, i.sec.fir.sec, ranking, parent)) used.pb(i.sec.sec);
    }

    pll total;
    for(auto& i : used) {
        total.fir += edges[i].a;
        total.sec += edges[i].b;
    }

    cout << total.fir/gcd(total.fir, total.sec) << '/' << total.sec/gcd(total.fir,total.sec);
    
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}


```