```

This problem is very implementation heavy!!!

Anyways, the idea is pretty simple. Binary search on the time mecho could eat honey pot before running, and use BFS to check the answer.



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

vi dr = {1, -1, 0, 0};
vi dc = {0, 0, 1, -1};


bool valid(int ans, int n, int s,pi m, vector<pi>& hives, vector<string>& grid){
    bool ok = 1;

    //1 = mecho, -1 = bee
    vector<vi> occupy(n, vi(n));
    vector<vi> dist(n, vi (n, -1));

    queue<pi> mecho;
    mecho.push(m);
    dist[m.fir][m.sec] = 0;
    occupy[m.fir][m.sec] = 1;

    queue<pi> bees;
    for(auto& i :hives){
        bees.push(i);
        dist[i.fir][i.sec] = 0;
        occupy[i.fir][i.sec] = -1;
    }

    while (!bees.empty()){
        pi cur = bees.front(); 
        if (dist[cur.fir][cur.sec] == ans){
            break;
        }
        bees.pop();


        for(int i{}; i < 4; i++){
            if (cur.fir+dr[i] < 0 || cur.fir+dr[i] >= n || cur.sec+dc[i] < 0 || cur.sec+dc[i] >= n) continue;
            if (occupy[cur.fir+dr[i]][cur.sec+dc[i]] >= 0 && grid[cur.fir+dr[i]][cur.sec+dc[i]] != 'T' && grid[cur.fir+dr[i]][cur.sec+dc[i]] != 'D'){
                if (cur.fir+dr[i] == m.fir &&  cur.sec+dc[i] == m.sec) ok = 0;
                occupy[cur.fir+dr[i]][cur.sec+dc[i]] = -1;
                dist[cur.fir+dr[i]][cur.sec+dc[i]] = dist[cur.fir][cur.sec]+1;
                bees.push({cur.fir+dr[i], cur.sec+dc[i]});
            }
        } 
    }
    

    

    int cur_time = ans+1;
    bool found = 0;
    

    while (!found && ok && !mecho.empty() && !bees.empty()){
        while (!mecho.empty()){
            pi cur = mecho.front();

            if (occupy[cur.fir][cur.sec] == -1){
                mecho.pop();
                continue;
            }
            if (dist[cur.fir][cur.sec] == (cur_time-ans)*s) break;
            mecho.pop();

            for(int i{}; i < 4; i++){
                if (cur.fir+dr[i] < 0 || cur.fir+dr[i] >= n || cur.sec+dc[i] < 0 || cur.sec+dc[i] >= n) continue;
                if (occupy[cur.fir+dr[i]][cur.sec+dc[i]] == 0 && grid[cur.fir+dr[i]][cur.sec+dc[i]] != 'T'){
                    occupy[cur.fir+dr[i]][cur.sec+dc[i]] = 1;
                    dist[cur.fir+dr[i]][cur.sec+dc[i]] = dist[cur.fir][cur.sec]+1;
                    mecho.push({cur.fir+dr[i], cur.sec+dc[i]});
                }
                if (grid[cur.fir+dr[i]][cur.sec+dc[i]] == 'D'){
                    found = 1;
                    break;
                }
            }
        }

        while (!bees.empty()){
            pi cur = bees.front(); 
            if (dist[cur.fir][cur.sec] == cur_time){
                break;
            }
            bees.pop();

            for(int i{}; i < 4; i++){
                if (cur.fir+dr[i] < 0 || cur.fir+dr[i] >= n || cur.sec+dc[i] < 0 || cur.sec+dc[i] >= n) continue;
                if (occupy[cur.fir+dr[i]][cur.sec+dc[i]] >= 0 && grid[cur.fir+dr[i]][cur.sec+dc[i]] != 'T' && grid[cur.fir+dr[i]][cur.sec+dc[i]] != 'D'){
                    occupy[cur.fir+dr[i]][cur.sec+dc[i]] = -1;
                    dist[cur.fir+dr[i]][cur.sec+dc[i]] = dist[cur.fir][cur.sec]+1;
                    bees.push({cur.fir+dr[i], cur.sec+dc[i]});
                }
            } 
        }

        cur_time++;
    }

    return (found && ok);
}


void solve(){
    int n, s;
    cin >> n >> s;

    vector<string> grid(n);
    for(auto& i : grid) cin >> i;

    vector<pi> hives;
    pi m;
    for(int i{}; i < n; i++){
        for(int j{};j < n; j++){
            if (grid[i][j] == 'M') m = {i,j};
            else if (grid[i][j] == 'H'){
                hives.pb({i,j});
            }
        }
    }

    int lo = 0, hi = n*n;
    
    while (hi > lo){
        int mid = lo + (hi-lo+1)/2;
        if (valid(mid, n, s, m, hives, grid)){
            lo = mid;
        }else hi = mid-1;
    }

    cout << (valid(lo,n,s,m,hives,grid) ? lo : -1);
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