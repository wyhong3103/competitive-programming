DSU.
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
 
const int MX = 2005;
pi parent[MX][MX];
int ranking[MX][MX];
 
pi dsu_get(pi at){
    return parent[at.fir][at.sec] = (parent[at.fir][at.sec] == at ? at : dsu_get(parent[at.fir][at.sec]));
}
 
void dsu_union(pi a, pi b, int& total){
    a = dsu_get(a);
    b = dsu_get(b);
    if (a == b) return;
 
    if (ranking[a.fir][a.sec] == ranking[b.fir][b.sec]) ranking[a.fir][a.sec]++;
 
    total--;
    if (ranking[a.fir][a.sec] > ranking[b.fir][b.sec]){
        parent[b.fir][b.sec] = parent[a.fir][a.sec];
        ranking[a.fir][a.sec]++;
    }else{
        parent[a.fir][a.sec] = parent[b.fir][b.sec];
        ranking[b.fir][b.sec]++;
    }
}
 
vi dr = {-1,-1,0,0,1,1};
vi dc = {-1,0,-1,1,0,1};
 
void solve(){
    int n;
    cin >> n;
    
    for(int i{}; i < MX; i++){
        for(int j{}; j < MX; j++){
            parent[i][j] = {i,j};
        }
    } 
 
    set<pi> black;
    int total = n;
    for(int i{}; i < n; i++){
        pi at;
        cin >> at.fir >> at.sec;
        at.fir += 1001;
        at.sec += 1001;
        black.insert(at);
        
        for(int j{}; j < 6; j++){
            pi temp = {at.fir + dr[j], at.sec + dc[j]};
            if (black.count(temp)){
                dsu_union(at, temp, total);
            }
        }
    }
    cout << total;
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