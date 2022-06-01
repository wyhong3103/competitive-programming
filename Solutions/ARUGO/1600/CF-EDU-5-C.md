The idea is to compute all the connected component's size, and then just manually add the total to the cell that is '\*'. 
```cpp
#include <bits/stdc++.h>
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
//Store the index of the component for cell[i][j]
int comp[MAX][MAX];

string grid[MAX];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int n, m;

void dfs(int r, int c, int& cnt, int compindex){
    if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '*' || comp[r][c] != -1) return;
    comp[r][c] = compindex;
    cnt++;
    for(int i{}; i < 4; i++){
        dfs(r+dr[i], c+dc[i], cnt, compindex);
    }
}

void solve(){
    cin >> n >> m;

    vector<string> res(n);
    for(int i{}; i < n; i++){
        cin >> grid[i];
        res[i] = grid[i];
    }

    memset(comp,-1,sizeof(comp));

    //Store the size of each component
    vi sizecomp;
    vector<pi> wall;

    int cur = 0;
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (grid[i][j] == '.' && comp[i][j] == -1){
                int cnt = 0;
                dfs(i,j,cnt,cur);
                sizecomp.pb(cnt);
                cur++;
            }else if (grid[i][j] == '*') wall.pb({i,j});
        }
    }


    for(auto& loc : wall){
        int cnt = 0;
        //Avoid adding the same component
        set<int> used;
        for(int i{}; i < 4; i++){
            if (loc.fir+dr[i] < 0 || loc.sec+dc[i] < 0 || loc.fir+dr[i] >= n || loc.sec+dc[i] >= m || grid[loc.fir+dr[i]][loc.sec+dc[i]] == '*') continue;

            int compindex = comp[loc.fir+dr[i]][loc.sec+dc[i]];

            if (used.count(compindex)) continue;
            
            used.insert(compindex);
            cnt = (cnt + sizecomp[comp[loc.fir+dr[i]][loc.sec+dc[i]]]) % 10;
        }   
        res[loc.fir][loc.sec] = (char)('0' + ((cnt + 1) % 10));
    }

    for(auto& i :res) cout << i << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```