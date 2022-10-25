```

Board placement as a dp state.

Transitions of a state is every possible move, and we want the one that return the minimal!

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

pi recur(vector<string>& board, map<vector<string>, pi>& dp){
    if (dp.count(board)) return dp[board];
    pi& memo = dp[board];
    memo = {INT_MAX, INT_MAX};

    int cnt = 0;
    int n = sz(board);
    int m = sz(board[0]);
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (board[i][j] != 'o') continue;
            cnt++;
            for(int k{}; k < 4; k++){
                if (i+dr[k] < 0 || i+dr[k] >= n || j+dc[k] < 0 || j+dc[k] >= m || board[i+dr[k]][j+dc[k]] != 'o') continue;
                if (i+dr[k]+dr[k] < 0 || i+dr[k]+dr[k] >= n || j+dc[k]+dc[k] < 0 || j+dc[k]+dc[k] >= m || board[i+dr[k]+dr[k]][j+dc[k]+dc[k]] != '.') continue;
                board[i][j] = '.';
                board[i+dr[k]][j+dc[k]] = '.';
                board[i+dr[k]+dr[k]][j+dc[k]+dc[k]] = 'o';
                pi res = recur(board, dp);
                memo = min(memo, {res.fir, res.sec+1});
                board[i][j] = 'o';
                board[i+dr[k]][j+dc[k]] = 'o';
                board[i+dr[k]+dr[k]][j+dc[k]+dc[k]] = '.';
            }
        }
    }

    memo = min(memo, {cnt, 0});
    return memo;
}

void solve(){
    vector<string> grid(5);
    for(auto& i : grid) cin >> i;

    map<vector<string>, pi> dp;

    recur(grid, dp);
    cout << dp[grid].fir << ' ' << dp[grid].sec << '\n';
} 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

```