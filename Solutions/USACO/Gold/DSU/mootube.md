```
Problem

It is basically a tree, every edge has a weight

relevance of node a & b is the minimum weight along the path from a to b, vice versa

since it's a tree, so the above value is always unique

given q queries

we are to find the number of nodes that has relevance >= k from node v

basically with weight k, how many node can i travel to, from node v, such that along any path the weight on the path must be >= k


Approach

sort all the queries according to the weight, and then start adding the edge in order, from bigger to smaller, and then with dsu, simply get the component size

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


const int MX = 1e5+5;
int comp_sz[MX];
int parent[MX];
    
int dsu_get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a]));
}

void dsu_union(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);
    
    if (a == b) return;

    if (comp_sz[a] > comp_sz[b]){
        parent[b] = a;
        comp_sz[a] += comp_sz[b];
    }else{
        parent[a] = b;
        comp_sz[b] += comp_sz[a];
    }
}

struct Edge{
    int w, f, t;
};

struct Query{
    int w, k, i;
};

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i{}; i < n; i++){
        parent[i] = i;
        comp_sz[i] = 1;
    }

    vector<Edge> edges(n-1);
    for(auto& i :edges){
        cin >> i.f >> i.t >> i.w;
        i.f--; i.t--;
    }

    sort(all(edges), [](Edge& a, Edge& b){
        if (a.w == b.w){
            return a.f > b.f;
        }
        return a.w > b.w;
    });
    
    vector<Query> query(q);
    for(int i{}; i < q; i++){
        cin >> query[i].w >> query[i].k;
        query[i].k--;
        query[i].i = i;
    }

    sort(all(query), [](Query& a, Query& b){
        if (a.w == b.w){
            return a.k > b.k;
        }
        return a.w > b.w;
    });
    
    vi res(q);
    int at = 0;
    for(int i{}; i < q; i++){
        for(int j{at}; j < n-1; j++){
            if (edges[j].w >= query[i].w){
                dsu_union(edges[j].f, edges[j].t);
            }else break;
            at++;
        } 
        res[query[i].i] = comp_sz[dsu_get(query[i].k)]-1;
    }

    for(auto& i : res) cout << i << '\n';
}

int main(){
    setio("mootube");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```