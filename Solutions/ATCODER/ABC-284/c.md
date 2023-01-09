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
 
 
const int MX = 105;
 
struct DSU{
    int ranking[MX];
    int parent[MX];
    int total;
        
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
        total--;
        return true;
    }
};
 
void solve(){
    int n, m;
    cin >> n >> m;
    
    DSU dsu;
    dsu.total = n;
    for(int i{}; i < n; i++){
        dsu.parent[i] = i;
    }
    
    for(int i{}; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        dsu.merge(f, t);
    }
    cout << dsu.total;
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