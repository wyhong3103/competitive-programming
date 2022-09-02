```

We can easily binary search on the maximal minimum width wormhole we need.

A very important fact is that

The wormhole can always be sorted iff every misplaced cow is connected to it's actual location.

So this became a connectivity problem.

We can use DSU to union all the wormhole that has width >= mid. And then check for every element if isn't at its place , see if the element and its actual location is in a same connected component.

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
    
    if (a == b) return;
    if (ranking[a] == ranking[b]) ranking[a]++;

    if (ranking[a] > ranking[b]){
        parent[b] = a;
        
    }else{
        parent[a] = b;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vi a(n);
    for(auto& i : a){
        cin >> i;
        i--;
    }

    vector<pair<int,pi>> edges(m);
    for(auto& i : edges){
        cin>> i.sec.fir >> i.sec.sec >> i.fir;
        i.sec.fir--;
        i.sec.sec--;
    }
    sort(all(edges));

    bool is_sorted = 1;
    for(int i{}; i < n; i++){
        if (a[i] != i){
            is_sorted = 0; 
        }
    }
    if (is_sorted){
        cout << -1;
        return;
    }

    int at = m;
    int lo = 0, hi = m-1;
    while (hi>lo){
        int mid = lo + (hi-lo+1)/2;

        vi parent(n);
        vi ranking(n);
        for(int i{}; i < n; i++){
            parent[i] = i;
        }

        for(int i{mid}; i < at; i++){
            dsu_union(edges[i].sec.fir, edges[i].sec.sec, parent, ranking);
        }

        bool ok = 1;
        for(int i{}; i < n; i++){
            if (a[i] != i && dsu_get(a[i],parent) != dsu_get(i, parent)){
                ok = 0; 
            }
        }

        if (ok){
            lo = mid;
        }else hi = mid-1;
    }

    cout << edges[lo].fir;
}

int main(){
    setio("wormsort");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```