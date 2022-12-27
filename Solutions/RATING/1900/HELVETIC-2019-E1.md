```

Time limit is quite loose.

Binary Search on the weight + Kruskal.

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

struct Edge{
    ll f, t, w, p;
    bool operator<(const Edge& y) const {
        if (w == y.w){
            //priority
            if (p != y.p) return p > y.p;
            else return make_pair(f,t) > make_pair(y.f, y.t);
        }
        return w < y.w;
    }
};

const int MX = 1e5+5;

struct DSU{
    int ranking[MX];
    int parent[MX];
        
    int get(int a){
        return parent[a] = (parent[a] == a ? parent[a] : get(parent[a]));
    }

    bool merge(int a, int b){
        a = get(a);
        b = get(b);
        
        if (a == b) return false;

        if (ranking[a] == ranking[b]) ranking[a]++;

        if (ranking[a] > ranking[b]){
            parent[b] = a;
        }else{
            parent[a] = b;
        }
        return true;
    }
};

void solve(){   
    int n, m;
    cin >> n >> m;
    
    Edge target;
    cin >> target.f >> target.t >> target.w;
    target.p = 1;

    set<Edge> edges;

    for(int i{1}; i < m; i++){
        Edge temp;
        cin >> temp.f >> temp.t >> temp.w;
        edges.insert(temp);
    }


    auto good = [&](ll mid){
        target.w = mid;
        edges.insert(target);
        bool ok = 0;
        DSU dsu;
        for(int i{1}; i <= n; i++) dsu.parent[i] = i;
        for(auto& i : edges){
            if (dsu.merge(i.f, i.t)) {
                ok |= i.f == target.f && i.t == target.t;
            }
        }

        edges.erase(target);
        return ok;
    };
    
    ll lo = 0, hi = 1e9;
    while (hi > lo){
        ll mid = lo + (hi-lo+1)/2;
        if (good(mid)){
            lo = mid;
        }else hi = mid-1;
    }
    cout << lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```