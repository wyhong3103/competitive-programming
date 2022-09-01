```

My initial mistake

- Misread problem statement (If a cow ever collide into a haybale/wall, it skips the current command only! I thought it's skipping the next command. Also if a cow reached the goal, it stopped right there and ignore the further commands)
- Using map to store each state is just way too slow.

Sol

We're going to simulate this problem with BFS (To simulate the path, level by level, hence BFS).

For each state there is 4 things that are important that distinct it from other states. The location of bessie 1 (that started out facing upward), location of bessie 2 (that started out facing right), and the direction of both of the cows facing.

Each of this state takes x distance to reach such a state from the initial state.

To save this state, and access it in a very memory and time efficient way, we can use a 6 dimensional array to store it. (Way way faster than a map/hashmap). Honestly, to begin with, there's no reason why should we use a map, because every state is accessible with array indexing.


In hindsight, it's not as hard as it seems in the beginning lol!
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

vi dr = {-1, 0, 1, 0};
vi dc = {0, 1, 0, -1};

int dist[20][20][20][20][4][4];

bool valid(pi lo, int n, int dir, vector<string>& grid){
    if (lo.fir == 0 && lo.sec == n-1) return false;
    if ((lo.fir + dr[dir]) < 0 || (lo.sec + dc[dir]) < 0 || (lo.fir + dr[dir]) >= n || (lo.sec + dc[dir]) >= n || grid[lo.fir+dr[dir]][lo.sec+dc[dir]] == 'H')  return false;
    return true;
}

void dist_set(vector<pi>& cur, int val){
    dist[cur[0].fir][cur[0].sec][cur[1].fir][cur[1].sec][cur[2].fir][cur[2].sec] = val;
}

int dist_get(vector<pi>& cur){
    return dist[cur[0].fir][cur[0].sec][cur[1].fir][cur[1].sec][cur[2].fir][cur[2].sec];
}

void solve(){
    int n;
    cin >> n;

    vector<string> grid(n);
    for(auto& i : grid) cin >> i;

    //{location of bessie 1, location of bessie 2, directions of bessie, direction of bessie 2}

    //map<vector<pi>, vector<pi>> ancestor;
    vector<pi> initial = {{n-1,0}, {n-1,0}, {0, 1}};
    memset(dist, -1, sizeof(dist));

    dist_set(initial, 0);
     
    int ans = -1;
    queue <vector<pi>> q;
    q.push(initial);
    while (!q.empty()){
        vector<pi> cur = q.front(); q.pop();
        if (cur[0].fir == 0 && cur[0].sec ==n-1 && cur[1].fir == 0 && cur[1].sec ==n-1) {
            ans = dist_get(cur);
            break;
        }

        //Foward
        vector<pi> forward = cur;
        if (valid(forward[0], n, forward[2].fir, grid)){
            forward[0] = {forward[0].fir+dr[forward[2].fir], forward[0].sec+dc[forward[2].fir]};
        }

        if (valid(forward[1], n, forward[2].sec, grid)){
            forward[1] = {forward[1].fir+dr[forward[2].sec], forward[1].sec+dc[forward[2].sec]};
        }

        if (dist_get(forward) == -1){
            dist_set(forward,dist_get(cur)+1);
            q.push(forward);
        }


        //Left
        vector<pi> left = cur;
        //assigning new direction
        left[2].fir = ((left[2].fir - 1) + 4) % 4;
        left[2].sec = ((left[2].sec - 1) + 4) % 4;

        if (dist_get(left) == -1){
            dist_set(left,dist_get(cur)+1);
            q.push(left);
        }

        //Right
        vector<pi> right = cur;
        //assigning new direction
        right[2].fir = (right[2].fir + 1) % 4;
        right[2].sec = (right[2].sec + 1) % 4;

        if (dist_get(right) == -1){
            dist_set(right,dist_get(cur)+1);
            q.push(right);
        }
    }

    cout << ans;
}

int main(){
    setio("cownav");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```