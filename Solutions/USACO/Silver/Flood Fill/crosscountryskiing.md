Binary Search + Flood Fill, could've solved it much faster if i know it's a binary search problem, sometimes, I have to really think deeper, and relating problems like minimal maximal with binary search.
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

const int MAX = 505;

int elev[MAX][MAX];
char grid[MAX][MAX];
bool vis[MAX][MAX];
int n, m;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

void dfs(int i, int j, int& count, int dist){
    if (grid[i][j] == '1'){
        count++;
    }
    vis[i][j] = 1;
    for(int k{}; k < 4; k++){
        if (i+dr[k] < 0 || j+dc[k] < 0 || i+dr[k] >= n || j+dc[k] >= m || vis[i+dr[k]][j+dc[k]] || abs(elev[i][j] - elev[i+dr[k]][j+dc[k]]) > dist){
            continue;
        }
        dfs(i+dr[k], j+dc[k], count ,dist);
    }
}

void solve(){
    cin >> n >> m;

    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            cin >> elev[i][j];
        }
    }

    int cnt = 0;
    pi loc;
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            cin >> grid[i][j];
            if (grid[i][j] == '1'){
                cnt++;
                loc = {i,j};
            }
        }
    }


    int lo = 0, hi = INT_MAX;
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        int count = 0;
        dfs(loc.fir, loc.sec, count, mid);
        memset(vis, 0, sizeof(vis));
        if (count == cnt){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    cout << lo;
}


int main(){
    setio("ccski");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```