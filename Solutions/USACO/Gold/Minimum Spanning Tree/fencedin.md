TLE on TC 9, 10. I have no idea why.
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

const int MX = 2010 * 2010;
int ranking[MX];
int parent[MX];
    
int dsu_get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a]));
}

void dsu_union(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);
    
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


void solve(){
    ll A, B, n, m;
    cin >> A >> B >> n >> m;

    vi ver(n);
    vi hor(m);
    for(auto& i : ver) cin >> i;
    for(auto& i : hor) cin >> i;
    sort(all(ver));
    sort(all(hor));

    vector<Edge> edges;
    
    for(int j{}; j <= m; j++){
        for(int i{}; i <= n; i++){
            if (i){
                edges.pb({(j*(n+1)) + i, (j*(n+1)) + (i-1), (j == m ? B-hor[j-1] : (!j ? hor[j] : hor[j]-hor[j-1]))});
            }
            if (j){
                edges.pb({(j*(n+1)) + i, ((j-1)*(n+1)) + (i), (i == n ? A-ver[i-1] : (!i ? ver[i] : ver[i]-ver[i-1]))});
            }
        }
    }


    for(int i{}; i <= n; i++){
        for(int j{}; j <= m; j++) parent[(j*(n+1))+i] = (j*(n+1))+i;
    }

    sort(all(edges));

    ll sm = 0;
    for(auto& i :edges){
        if (dsu_get(i.f) != dsu_get(i.t)){
            dsu_union(i.f, i.t);
            sm += i.w;
        }
    }
    cout << sm;
}



int main(){
    setio("fencedin");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```
Doesn't work as expected.
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

const int MX = 2010 * 2010;
int ranking[MX];
int parent[MX];
    
int dsu_get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : dsu_get(parent[a]));
}

bool dsu_union(int a, int b){
    a = dsu_get(a);
    b = dsu_get(b);
        
    if (a == b) return false;

    if (ranking[a] == ranking[b]) ranking[a]++;

    if (ranking[a] > ranking[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
    return true;
}


void solve(){
    ll A, B, n, m;
    cin >> A >> B >> n >> m;

    vi ver(n);
    vi hor(m);
    for(auto& i : ver) cin >> i;
    for(auto& i : hor) cin >> i;
    sort(all(ver));
    sort(all(hor));

    vll ver_edge(n+1);
    vll hor_edge(m+1);

    for(int i{}; i < n; i++){
        ver_edge[i] = ver[i]-(!i ? 0 :ver[i-1]);
    }
    ver_edge[n] = A - ver[n-1];

    for(int i{}; i < m; i++){
        hor_edge[i] = hor[i]-(!i ? 0 : hor[i-1]);
    }
    hor_edge[m] = B - hor[m-1];
    
    for(int i{}; i <= n; i++){
        for(int j{}; j <= m; j++) parent[(j*(n+1))+i] = (j*(n+1))+i;
    }

    ll sm = 0;
    int p1 = 0, p2 = 0;
    while (p1 <= n || p2 <= m){
        if ((p1 <= n && ver_edge[p1] < hor_edge[p2]) || p2 > m){
            for(int i{}; i < m; i++){
                if (dsu_union((i*(n+1))+p1, ((i+1)*(n+1))+p1)){
                    sm += ver_edge[p1];
                }
            }
            p1++;
        }else{
            for(int i{}; i < n; i++){
                if (dsu_union((p2*(n+1))+i, ((p2)*(n+1))+i+1)){
                    sm += hor_edge[p2];
                }
            }
            p2++;
        }
    }
    cout << sm;
}



int main(){
    //setio("fencedin");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}



```