```
The idea is to move the monsters & players simultaneously, until all of the grids are covered with their tracks.

If there is a cell where the monster & player reached at the same time, that square belongs to the monster.

After this, we can do a BFS on the grid once again, and see if there exist a boundary cell belongs to the player and then simply prints out the answer.

```
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

struct Coord{
    int r, c;
};

vi dr = {0, 0, 1, -1};
vi dc = {1, -1, 0, 0};

void solve(){
    int h, w;
    cin >> h >> w;
    
    vector<string> grid(h);
    for(auto& i : grid) cin >> i;

    //{dist, occupier} 1 = A, -1 = M
    vector<vector<pi>> occupied(h, vector<pi> (w));
    queue<Coord> q;
    Coord start;
    for(int i{}; i < h; i++){
        for(int j{}; j < w; j++){
            if (grid[i][j] == 'A'){
                occupied[i][j] = {0, 1};
                start = {i,j};
            }
            else if (grid[i][j] == 'M') occupied[i][j] ={0,-1};
            else continue;
            q.push({i,j});
        }
    }

    while (!q.empty()){
        Coord cur = q.front();q.pop();
        for(int i{}; i < 4; i++){
            if (cur.r+dr[i] < 0 || cur.r+dr[i] >= h || cur.c+dc[i] < 0 || cur.c+dc[i] >= w) continue;
            if (grid[cur.r+dr[i]][cur.c+dc[i]] != '#'){
                if (!occupied[cur.r+dr[i]][cur.c+dc[i]].sec){
                    occupied[cur.r+dr[i]][cur.c+dc[i]] = {occupied[cur.r][cur.c].fir+1,occupied[cur.r][cur.c].sec};
                    q.push({cur.r+dr[i], cur.c+dc[i]});
                }else if (occupied[cur.r][cur.c].sec == -1 && occupied[cur.r+dr[i]][cur.c+dc[i]].sec == 1 && occupied[cur.r+dr[i]][cur.c+dc[i]].fir == occupied[cur.r][cur.c].fir+1){
                    occupied[cur.r+dr[i]][cur.c+dc[i]].sec = -1;
                }
            }
        }
    }
    

    Coord dest = {-1,-1};
    vector<vi> dir(h, vi (w));
    dir[start.r][start.c] = -1;
    q.push(start);
    while (!q.empty()){
        Coord cur = q.front(); q.pop();
        if (cur.r == 0 || cur.c == 0 || cur.r == h-1 || cur.c == w-1){
            if (occupied[cur.r][cur.c].sec == 1){
                dest = cur;
            }
        }
        for(int i{}; i < 4; i++){
            if (cur.r+dr[i] < 0 || cur.r+dr[i] >= h || cur.c+dc[i] < 0 || cur.c+dc[i] >= w) continue;
            if (grid[cur.r+dr[i]][cur.c+dc[i]] != '#' && occupied[cur.r+dr[i]][cur.c+dc[i]].sec == 1 && !dir[cur.r+dr[i]][cur.c+dc[i]]){
                dir[cur.r+dr[i]][cur.c+dc[i]] = i+1;
                q.push({cur.r+dr[i], cur.c+dc[i]});
            }
        }
    }
    if (dest.r == -1){
        cout << "NO";
        return;
    }
    
    cout << "YES" << '\n';
    string res = "";
    Coord cur = dest;
    while (dir[cur.r][cur.c] != -1){
        switch(dir[cur.r][cur.c]){
            case 1:
                res += 'R';
                cur.c--;
                break;
            case 2:
                res += 'L';
                cur.c++;
                break;
            case 3:
                res += 'D';
                cur.r--;
                break;
            case 4:
                res += 'U';
                cur.r++;
                break;
        }
    }
    cout << sz(res) << '\n';
    for(int i{sz(res)-1}; i >= 0; i--){
        cout << res[i];
    }
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