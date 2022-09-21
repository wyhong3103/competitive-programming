It turned out negating the step is unnecessary.
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

const int MX = 1e2+5;
ll weight[MX][MX];
ll dist[MX][MX][4];
bool vis[MX][MX][4];

vi dr = {1, -1, 0, 0};
vi dc = {0, 0, 1, -1};

void solve(){
    ll n, t;
    cin >> n >> t;

    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            cin >> weight[i][j];
            for(int k{}; k < 4; k++) dist[i][j][k] = INT_MAX;
        }
    }
    dist[0][0][0] = 0;

    //{cost, step, at}
    priority_queue<vll> q;
    q.push({0,0,0,0});

    while (!q.empty()){
        vll cur = q.top(); q.pop();
        cur[1] = -cur[1];
        if (vis[cur[2]][cur[3]][cur[1]]) continue;
        vis[cur[2]][cur[3]][cur[1]] = 1;
        

        for(int i{}; i < 4; i++){
            if (cur[2]+dr[i] >= n || cur[2]+dr[i] < 0 || cur[3]+dc[i] >= n || cur[3]+dc[i] < 0) continue;

            if (cur[1] == 3){
                if (dist[cur[2]][cur[3]][cur[1]] + t < dist[cur[2]+dr[i]][cur[3]+dc[i]][1]){
                    dist[cur[2]+dr[i]][cur[3]+dc[i]][1] =  dist[cur[2]][cur[3]][cur[1]] + t;  
                    q.push({-dist[cur[2]+dr[i]][cur[3]+dc[i]][1], -1, cur[2]+dr[i], cur[3]+dc[i]});
                }
            }
            else if (cur[1] == 2){
                if (dist[cur[2]][cur[3]][cur[1]] + weight[cur[2]+dr[i]][cur[3]+dc[i]] + t < dist[cur[2]+dr[i]][cur[3]+dc[i]][cur[1]+1]){
                    dist[cur[2]+dr[i]][cur[3]+dc[i]][cur[1]+1] =  dist[cur[2]][cur[3]][cur[1]] + weight[cur[2]+dr[i]][cur[3]+dc[i]] + t;  
                    q.push({-dist[cur[2]+dr[i]][cur[3]+dc[i]][cur[1]+1], -3, cur[2]+dr[i], cur[3]+dc[i]});
                }
            }else{
                if (dist[cur[2]][cur[3]][cur[1]] + t < dist[cur[2]+dr[i]][cur[3]+dc[i]][cur[1]+1]){
                    dist[cur[2]+dr[i]][cur[3]+dc[i]][cur[1]+1] =  dist[cur[2]][cur[3]][cur[1]] + t;  
                    q.push({-dist[cur[2]+dr[i]][cur[3]+dc[i]][cur[1]+1], -(cur[1]+1), cur[2]+dr[i], cur[3]+dc[i]});
                }
            }
        } 
    }

    ll mn = LONG_LONG_MAX;
    for(int i{}; i < 4; i++){
        mn = min(dist[n-1][n-1][i], mn);
    }
    cout << mn;
}
 
int main(){
    setio("visitfj");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```
