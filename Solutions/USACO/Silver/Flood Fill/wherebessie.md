Unsolved
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

struct Rect{
    int tlx, tly, brx, bry;
};
char grid[20][20];
bool vis[20][20];
vector<Rect> ptl;
int n;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};


void dfs(int i, int j, Rect r, char c){
    if (i < r.tly || j < r.tlx || i > r.bry || j > r.brx || vis[i][j] || grid[i][j] != c) return;
    
    vis[i][j] = 1;

    for(int k{};k < 4;k++){
        dfs(i+dr[k], j+dc[k], r, c);
    } 
}

void validate(int h, int l, int r, int c){
    for(auto& i : ptl){
        int intersectx = min(i.brx, c+l-1) - max(i.tlx, c);
        int intersecty = min(i.bry, r+h-1) - max(i.tly, r);
        if (intersectx > 0 || intersecty > 0) return;
    }

    Rect rect = {r, c, r+h-1, c+l-1};
    map<char,int> mp;
    for(int i{r}; i < r+h; i++){
        for(int j{c}; j < c+l; j++){
            if (!vis[i][j]){
        if (r == 0 && c == 0 && h == 4 && l == 3){
            cout << i << ' ' << j << '\n';
        }
                if (!mp.count(grid[i][j])) mp[grid[i][j]] = 0;
                mp[grid[i][j]]++;
                dfs(i, j, rect, grid[i][j]);
            }
        }
    }

    if (sz(mp) == 2){
        pi cnt = {mp.begin()->sec, (++mp.begin())->sec};
        if (cnt.fir < cnt.sec) swap(cnt.fir,cnt.sec);
        if (cnt.fir >= 2 && cnt.sec == 1){
            ptl.pb(rect);
        }
    }
    
}

void search(int h, int l){
    for(int i{}; i <= n-h; i++){
        for(int j{}; j <= n-l; j++){
            validate(h, l, i, j);
            memset(vis, 0, sizeof(vis));
        }
    }
}

void solve(){
    cin >> n;

    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            cin >> grid[i][j];
        }
    }

    for(int i{n}; i >= 1 ;i--){
        for(int j{n}; j >= 1; j--){
            search(i,j);
            search(j,i);
        }
    }

    cout << sz(ptl);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
 


```