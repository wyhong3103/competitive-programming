```

Basically, we could sort of find the best edges first (it's unnecessary we could straight up do kruskal's, but that's what i did), by sorting the element, starting with the minimal element, the minimal element as the potential edge weight that could connect up nodes.

Iterate the sorted element, go L and R connects up every gcd(x, cur_min) = cur_min, if an element is already chosen before it, we should consider it and break afterward.

The idea is

x x x x x x 
	y y y y y y y y


We can see GCD as a segment,

And in this case,

Let's say x < y, 

if gcd(x,y) = x

The above would never happen, because 

gcd(y, z) = y

gcd(x,z) = x (x < y)

The smaller can take over the segment.

But it's rather a different case if y is outside of the segment x where it's unreachable from x, in this case 

x x x x x x x
		y y y y y y y y

This is possible, but unnecessary , the only necessary part is

x x x x x x x
		    y y y y y y

The one that connects up two segment, as the other overlapping element, is already connected.

By doing this, we got ourselves all the optimal edges, and considering the adjacent edges that is weighted p. We can use kruskal to find the mst.
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

void dsu_union(int a, int b, vi& parent, vi& ranking){
    a = dsu_get(a, parent);
    b = dsu_get(b, parent);
    
    if (ranking[a] == ranking[b]) ranking[a]++;

    if (ranking[a] > ranking[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}

struct Edge{
    int f, t;
    ll w;
    bool operator<(const Edge& y){
        return y.w > w;
    }
};

ll gcd(ll a, ll b){
    return (!b ? a : gcd(b, a % b));
}


void solve(){
    ll n, p;
    cin >> n >> p;

    vll a(n);
    for(auto& i : a) cin >> i;
    vi parent(n);
    vi ranking(n);
    
    vi order(n);
    for(int i{}; i < n; i++) order[i] = i;

    sort(all(order), [&](int x, int y){
        return (a[x] < a[y]);
    });

    vector<Edge> edges;

    vector<bool> chosen(n);

    for(int i{}; i < n; i++){
        if (i < n-1) edges.pb({i, i+1, p});
        if (chosen[order[i]]) continue;
        //if it couldn't be process by lower element, then no way it's geting processed later
        chosen[order[i]] = 1;
        ll cur = a[order[i]];
        for(int l{order[i]-1}; l >= 0; l--){
            if (gcd(cur, a[l]) == cur){
                edges.pb({l, order[i], a[order[i]]});
                if (chosen[l]) break;
                chosen[l] = 1;    
            }else break;
        } 

        for(int r{order[i]+1}; r < n; r++){
            if (gcd(cur, a[r]) == cur){
                edges.pb({r, order[i], a[order[i]]});
                if (chosen[r]) break;
                chosen[r] = 1;    
            }else break;
        } 
    }

    for(int i{}; i < n; i++) parent[i] = i;
    sort(all(edges));

    ll sm = 0;
    for(auto& i : edges){
        if (dsu_get(i.f, parent) != dsu_get(i.t, parent)){
            dsu_union(i.f, i.t, parent, ranking);
            sm += i.w;
        }
    }
    cout << sm << '\n';
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