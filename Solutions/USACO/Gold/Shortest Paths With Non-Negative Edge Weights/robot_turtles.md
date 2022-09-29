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


ll dist[8][8][4];
bool vis[8][8][4];
string p[8][8][4];

vi dr = {1, 0, -1, 0};
vi dc = {0, 1, 0, -1};

struct State{
    int r, c, f;
    bool operator<(const State& y) const {
        return r < y.r;
    }
};

void solve(){
    int n = 8;

    vector<string> board(n);
    for(auto& i : board) cin >> i;

    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            for(int k{}; k < 4; k++){
                dist[i][j][k] = LONG_LONG_MAX;
            }
        }
    }

    dist[n-1][0][1] = 0;
    p[n-1][0][1] = "N";
    priority_queue<pair<ll, State>> q;
    q.push({0, {n-1, 0, 1}});

    while (!q.empty()){
        State cur = q.top().sec; q.pop();
        pi at = {cur.r, cur.c};
        int f = cur.f;
        if (vis[at.fir][at.sec][f]) continue;
        vis[at.fir][at.sec][f] = 1;
        for(int i{}; i < 4; i++){
            if (!(at.fir + dr[i] >= 0 && at.fir + dr[i] < n && at.sec + dc[i] >= 0 && at.sec + dc[i] < n)) continue;
            if (f == i && dist[at.fir+dr[i]][at.sec+dc[i]][f] > dist[at.fir][at.sec][f] + 1 + (board[at.fir+dr[i]][at.sec+dc[i]] == 'I') && board[at.fir+dr[i]][at.sec+dc[i]] != 'C'){
                dist[at.fir+dr[i]][at.sec+dc[i]][f] = dist[at.fir][at.sec][f] + 1 + (board[at.fir+dr[i]][at.sec+dc[i]] == 'I');
                p[at.fir+dr[i]][at.sec+dc[i]][f] = "";
                if (board[at.fir+dr[i]][at.sec+dc[i]] == 'I') p[at.fir+dr[i]][at.sec+dc[i]][f] += "X";
                p[at.fir+dr[i]][at.sec+dc[i]][f] += "F";
                q.push({-dist[at.fir+dr[i]][at.sec+dc[i]][f], {at.fir+dr[i], at.sec+dc[i], f}});
            }
        }
        
        if (dist[at.fir][at.sec][(f+1)%4] > dist[at.fir][at.sec][f] + 1){
            dist[at.fir][at.sec][(f+1)%4] = dist[at.fir][at.sec][f] + 1;
            p[at.fir][at.sec][(f+1)%4] = "L";
            q.push({-dist[at.fir][at.sec][(f+1)%4], {at.fir, at.sec, (f+1)%4}});
        }

        if (dist[at.fir][at.sec][(f+3)%4] > dist[at.fir][at.sec][f] + 1){
            dist[at.fir][at.sec][(f+3)%4] = dist[at.fir][at.sec][f] + 1;
            p[at.fir][at.sec][(f+3)%4] = "R";
            q.push({-dist[at.fir][at.sec][(f+3)%4], {at.fir, at.sec, (f+3)%4}});
        }
    }

    pair<State, ll> bst = {{0,0,0}, LONG_LONG_MAX};
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            if (board[i][j] != 'D') continue;
            for(int k{}; k < 4; k++){
                if (dist[i][j][k] < bst.sec){
                    bst = {{i,j,k}, dist[i][j][k]};
                }
            }
        }
    }

    if (bst.sec == LONG_LONG_MAX){
        cout << "no solution";
        return;
    }

    State cur = bst.fir;
    string sol{};
    while (p[cur.r][cur.c][cur.f] != "N"){
        for(int i{sz(p[cur.r][cur.c][cur.f])-1}; i >= 0; i--){
            sol += p[cur.r][cur.c][cur.f][i];
        }
        if (sol.back() == 'X' || sol.back() == 'F'){
            cur = {cur.r + dr[(cur.f + 2)% 4], cur.c + dc[(cur.f + 2) % 4], cur.f};
        }else if (sol.back() == 'L'){
            cur = {cur.r, cur.c, (cur.f+3) % 4};
        }else{
            cur = {cur.r, cur.c, (cur.f+1) % 4};
        }
    }

    for(int i{sz(sol)-1}; i >= 0; i--) cout << sol[i];
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