The idea is to basically trap every bad guy , and then start searching from the end point see if we can reach every good guy.
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

const int MAX = 55;

char grid[MAX][MAX];
bool vis[MAX][MAX];
int n, m;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

void dfs(int i, int j, int& count){
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#' || vis[i][j]) return;
    if (grid[i][j] == 'G'){
        count++;
    }
    vis[i][j] = 1;
    for(int k{}; k < 4; k++){
        dfs(i+dr[k], j+dc[k],count);
    }
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;

        //could've just been count
        vector<pi> good;
        vector<pi> bad;
        for(int i{}; i < n; i++){
            for(int j{}; j < m; j++){
                cin >> grid[i][j];
                if (grid[i][j] == 'B') bad.pb({i,j});
                else if (grid[i][j] == 'G') good.pb({i, j});
            }
        }
        for(auto& i : bad){
            for(int k{}; k < 4; k++){
                if (i.fir+dr[k]>= 0 && i.fir+dr[k] < n && i.sec+dc[k] >= 0 && i.sec+dc[k] < m){
                    grid[i.fir+dr[k]][i.sec+dc[k]] = '#';
                }
            }
        }

        int count = 0;
        dfs(n-1, m-1, count);
        memset(vis, 0, sizeof(vis));
        cout << (count == sz(good) ? "YES" : "NO" ) << '\n';
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```