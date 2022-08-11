Made a mistake while doing this, I thought that we're looking for the rooms that Bessie can travel instead. So the idea is pretty simple, everytime we light up a room, we travel the whole grid again(by resetting the visisted). We need an extra array to keep track of which room we have been in and turned on the lights, so we don't stuck in an infinity loop.
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

const int MAX = 100;
bool grid[MAX][MAX];
bool vis[MAX][MAX];
bool turned[MAX][MAX];
vector<pi> swch[MAX][MAX];
int n, m;
int ans;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};


void dfs(int r, int c){
    if (r < 0 || c < 0 || r >= n || c >= n || !grid[r][c] || vis[r][c]) return;

    vis[r][c] = 1;
    if (!turned[r][c] && sz(swch[r][c])){
        for(auto& i : swch[r][c]){
            grid[i.fir][i.sec] = 1;
        }
        turned[r][c] = 1;
        memset(vis, 0, sizeof(vis));
        vis[r][c] = 1;
    }

    for(int i{}; i < 4; i++){
        dfs(r+dr[i], c+dc[i]);
    }
}

void solve(){
    cin >> n >> m;

    for(int i{}; i < m; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--;y--;a--;b--;
        swch[x][y].pb({a, b});
    }

    grid[0][0] = 1;
    dfs(0, 0);

    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            if( grid[i][j]) ans++;
        }
    }
    cout << ans;
}


int main(){
	setio("lightson");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```