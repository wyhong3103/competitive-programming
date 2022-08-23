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
 
void move(int i, int j, int& ok,vector<string>& grid,vector<vector<bool>>& vis, pi& res){
    if (i < 0 || j < 0 || i >= sz(grid) || j >= sz(grid[0])){
        ok = 0;
        return;
    }
    if (vis[i][j]){
        ok = -1;
        return;
    }
    vis[i][j] = 1;
    if (grid[i][j] == 'U'){
        move(i-1, j, ok, grid, vis, res);
    }else if (grid[i][j] == 'R'){
        move(i, j+1, ok, grid, vis, res);
    }else if (grid[i][j] == 'D'){
        move(i+1, j, ok, grid, vis, res);
    }else{
        move(i, j-1, ok, grid, vis, res);
    }
    if (ok == 0){
        res = {i, j};
        ok = 1;
    }else if (ok == -1){
        res = {-1,-1};
        ok = 1;
    }
}
 
void solve(){
    int h,w;
    cin >> h >> w;
 
    vector<string> grid(h);
    for(auto& i : grid) cin>> i;
 
    vector<vector<bool>> vis(h, vector<bool> (w));
    int ok = 1;
    pi res = {};
    move(0,0,ok,grid,vis,res);
 
    if (res.fir == -1){
        cout << -1;
    }else cout << res.fir+1 << ' ' << res.sec+1;
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