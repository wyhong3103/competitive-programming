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
 
vi dr = {1, -1, 0, 0};
vi dc = {0, 0, 1, -1};
 
void dfs(int r, int c, int n, auto& vis, auto& grid, int& cnt, int cur){
    if (r < 0 || c < 0 || r >= n || c >= n || vis[r][c] || grid[r][c] != cur){
        return;
    }
 
    vis[r][c] = 1;
    cnt++;
    for(int i{}; i < 4; i++){
        dfs(r+dr[i], c+dc[i], n, vis, grid, cnt, cur);
    }
}
 
void solve(){
    int n;
    cin >> n;
 
    vector<vi> a(n, vi(n));
    vector<vi> vis(n, vi(n));
    for(auto& i : a){
        for(auto& j : i) cin >> j;
    }
 
    pi mx = {0, 0};
 
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            if (!vis[i][j] && a[i][j]){
                int cnt = 0;
                dfs(i, j, n, vis, a, cnt, a[i][j]);
                if (cnt > mx.sec){
                    mx = {a[i][j], cnt};
                }else if (cnt == mx.sec && a[i][j] == 2){
                    mx = {a[i][j], cnt};
                }
            }
        }
    }
 
    if (mx.fir == 1){
        cout << "MOH should focus on Covid-19" << '\n';
    }else{
        cout << "MOH should focus on Omicron" << '\n';
    }
 
 
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