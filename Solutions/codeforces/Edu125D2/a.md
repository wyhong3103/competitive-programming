BFS

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

bool isInt(int x1, int y1, int x2, int y2){
    return sqrt((double)((x1-x2) * (x1-x2))+((y1-y2) * (y1-y2))) - floor(sqrt(((x1-x2) * (x1-x2)) + ((y1-y2) * (y1-y2)))) < 0.000001;
}


void solve(){
    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;

        queue<pair<int,int>> q;
        q.push({0,0});
        int distance[51][51];
        bool vis[51][51];
        memset(distance, 0, sizeof(distance));
        memset(vis, 0, sizeof(vis));
        vis[0][0] = true;
        while (!q.empty()){
            pair<int,int> s = q.front(); q.pop();
            
            for(int i{}; i <= x; i++){
                for(int j{}; j <= y; j++){
                    if (!vis[i][j] && isInt(s.fir,s.sec,i,j)){
                        q.push({i,j});
                        vis[i][j] = true;
                        distance[i][j] = distance[s.fir][s.sec] + 1;
                    }
                }
            }
        }
        cout << distance[x][y] << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```