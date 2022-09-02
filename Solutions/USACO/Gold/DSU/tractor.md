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

void dsu_union(int a, int b, vi& comp_sz, vi& parent){
    a = dsu_get(a, parent);
    b = dsu_get(b, parent);
    
    if (a == b) return;

    if (comp_sz[a] > comp_sz[b]){
        parent[b] = a;
        comp_sz[a] += comp_sz[b];
    }else{
        parent[a] = b;
        comp_sz[b] += comp_sz[a];
    }
}

void solve(){
    int n;
    cin >> n;
    
    vector<vi> grid(n, vi(n));
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            cin >> grid[i][j];
        }
    }


    int lo = 0, hi = 1e6;
    while (hi > lo){
        int mid = lo + (hi-lo)/2;

        vi parent(n*n);
        for(int i{}; i < n*n; i++) parent[i] = i;
        vi comp_sz(n*n, 1);
        
        int mx = 0;
        for(int i{}; i < n; i++){
            for(int j{};j < n; j++){
                if (i > 0 && abs(grid[i-1][j]-grid[i][j]) <= mid){
                    dsu_union((i*n)+j, ((i-1)*n)+j, comp_sz, parent);
                }
                if (j > 0 && abs(grid[i][j-1]-grid[i][j]) <= mid){
                    dsu_union((i*n)+j, (i*n)+j-1, comp_sz, parent);
                }
                mx = max(mx,comp_sz[dsu_get((i*n)+j, parent)]);
            }
        }
        
        if (mx >= ((n*n)+1)/2){
            hi = mid;
        }else lo = mid+1;
    }

    cout << lo;
}


int main(){
    setio("tractor");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```