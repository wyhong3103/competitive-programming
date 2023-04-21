```

Start from the largest bit, try to excluse every edge that has this bit, if after excluding we could still form a tree, then we remove all edges with that bit associated.

with kruskal's to form the spanning tree.

This would work, becuse we excluded every large bit that we could

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
struct Edge{
    ll f,t,w;
};
 
int get(int a, vi& parent){
    return (parent[a] == a ? a : get(parent[a], parent));
}
 
void dsumerge(int a, int b, vi& parent, vi& score, int& comp){
    a = get(a, parent);
    b = get(b, parent);
 
    if (a == b) return;
 
    comp--;
    if (score[a] > score[b]){
        parent[b] = a;
        score[a]+=score[b];
    }else{
        parent[a] = b;
        score[b]+=score[a];
    }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<Edge> edges(m);
    for(auto& i : edges){
        cin >> i.f >> i.t >> i.w;
        i.f--;i.t--;
    }
 
    ll sm = 0;
    for(int i{30}; i >= 0; i--){
 
        vector<Edge> temp;
        for(auto& j : edges){
            if (!(j.w & (1LL << i))){
                temp.pb(j);
            }
        }
 
        vi parent(n);
        for(int j{}; j < n; j++) parent[j] = j;
        vi score(n, 1);
        int comp = n;
 
        for(auto& j : temp){
            dsumerge(j.f, j.t, parent, score, comp);
        }
        
        if (comp == 1) edges = temp;
        else{
            sm += (1LL << i);
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