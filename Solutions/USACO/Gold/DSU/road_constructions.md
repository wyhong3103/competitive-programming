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


const int MX = 1e5;
int comp_sz[MX];
int parent[MX];
    
int dsu_get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a]));
}

void dsu_union(int a, int b, int& mx, int& total){
    a = dsu_get(a);
    b = dsu_get(b);
    
    if (a == b) return;

    if (comp_sz[a] > comp_sz[b]){
        parent[b] = a;
        comp_sz[a] += comp_sz[b];
        mx = max(comp_sz[a], mx);
    }else{
        parent[a] = b;
        comp_sz[b] += comp_sz[a];
        mx = max(comp_sz[b], mx);
    }
    total--;
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i{}; i < n; i++){
        parent[i] = i;
        comp_sz[i] = 1;
    }

    int mx = 0;
    int total = n;
    while(m--){
        int a, b;
        cin >> a >> b;
        a--;b--;
        dsu_union(a, b, mx, total);
        cout << total << ' ' << mx << '\n';
    }
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