Implementation heavy.
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
 
 
vi dr = {1, -1, 1, -1, 1, -1, 0, 0};
vi dc = {1, -1, -1, 1, 0, 0, 1, -1};
 
 
 
bool valid(set<pi> l, vector<string>& grid){
    bool ok = 1;
    for(auto& i : l){
        for(int dir{}; dir < 4; dir++){
            pi new_lo = {i.fir+dr[dir], i.sec+dc[dir]};
            if (new_lo.fir < 0 || new_lo.sec < 0 || new_lo.fir >= sz(grid) || new_lo.sec >= sz(grid[0]) || l.count(new_lo)) continue;
            if (grid[new_lo.fir][new_lo.sec] == '*') ok = 0;
        }
    }
 
    return ok;
}
 
void dfs(int i, int j, vector<string>& grid, vector<vector<bool>>& vis, set<pi>& l){
    if (i < 0 || j < 0 || i >= sz(grid) || j >= sz(grid[0]) || grid[i][j] == '.' || vis[i][j]) return;
    
    vis[i][j] = 1;
    l.insert({i,j});
    for(int dir{4}; dir < 8; dir++){
        dfs(i+dr[dir], j+dc[dir], grid, vis, l);
    }
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<string> grid(n);
    for(auto& i :grid) cin >> i;
 
    vector<vector<bool>> vis(n, vector<bool> (m));
 
    bool ok = 1;
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (grid[i][j] == '*' && !vis[i][j]){
                set<pi> l;
                dfs(i, j, grid, vis, l);
                if (sz(l) != 3) ok = 0;
                else{
                    set<int> r;
                    set<int> c;
                    for(auto& k : l){
                        r.insert(k.fir);
                        c.insert(k.sec);
                    }
                    if (sz(r) != 2 && sz(c) != 2) ok = 0;
                    ok &= valid(l, grid);
                }
            }
        }
    }
 
    cout << (ok ? "YES" : "NO") << '\n';
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