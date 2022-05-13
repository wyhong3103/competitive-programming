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

const int MAX = 1000;

char grid[MAX][MAX];
bool vis[MAX][MAX];
int n;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

void dfs(int r, int c,pi& count){
    if (vis[r][c] || r < 0 || c < 0 || r > n-1 || c > n-1 || grid[r][c] == '.') return;
    count.fir++;
    for(int i{}; i < 4; i++){
    	//If it's out of border or it's '.' then it's perimeter
        if (!(r+dr[i] >= 0 && r+dr[i] <= n-1 && c+dc[i] >= 0 && c+dc[i] <= n-1 && grid[r+dr[i]][c+dc[i]] == '#')){
            count.sec++;
        }
    }
    vis[r][c] = 1;
    for(int i{}; i < 4; i++){
        dfs(r+dr[i], c + dc[i], count);
    }
}

void solve(){
    cin >> n;

    for(int i{};i < n; i++){
        for(int j{}; j < n; j++){
            cin >> grid[i][j];
        }
    }


    pi ans{0,0};
    for(int i{};i < n; i++){
        for(int j{}; j < n; j++){
            if (!vis[i][j] && grid[i][j] == '#'){
                pi count{};
                dfs(i, j, count);
                if (count.fir > ans.fir){
                    ans = count;
                }else if (count.fir == ans.fir){
                    ans.sec = min(ans.sec, count.sec);
                }
            }
        }
    }
    cout << ans.fir << ' ' << ans.sec;
}

int main(){
    setio("perimeter");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```