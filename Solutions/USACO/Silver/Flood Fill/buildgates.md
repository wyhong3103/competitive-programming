Okay so the idea of this problem is really simple, you first start off at a place every place you been through will leave a fence. The tricky part is that, you have to find a way to store the fence, 	that means we cannot use an ordinary grid to store the information, you might be tempted to use a boolean 2D array, but sadly it doesn't work.
```
1 1
1 1

This is why, you don't know which fence connect to each other
```
So we will have to use a 3D array, first 2 dimension is used to find the location, the 3rd dimension, only has 4 element, if it's 1 , it indicates that it has fence at a specific direction. And this is what are we going to use flood fill on. Another tricky part is the case where
```
NNNNSSSS

This is equivalent to NNNN

But if you are not careful while you're assigning the fences it might ends up travelling back and forth, which will leads to WA, so when there's already at the place, we don't need at it

For example

[0][1] - 1

[1][0] doesn't have to be 1
```
And to solve it, it's literally about finding the number of cycles in the grid. Which is the number of times where we visit a visited node.

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

const int MAX = 2005;
bool grid[MAX][MAX][4];
bool vis[MAX][MAX];

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c, int& count){
    if (r < 0 || c < 0 || r > MAX || c > MAX || vis[r][c]) return;
    
    vis[r][c] = 1;
    for(int i{}; i < 4; i++){
        if (grid[r][c][i]){
            if (vis[r+dr[i]][c+dc[i]]){
                count++;
            }
            else dfs(r+dr[i], c+dc[i], count);
        }
    }    
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    pi cur{1000, 1000};
    for(auto& i : s){
        switch (i){
            case 'N':
                if (!grid[cur.fir+1][cur.sec][2])
                    grid[cur.fir][cur.sec][0] = 1;
                cur.fir++;
                break;
            case 'E':
                if (!grid[cur.fir][cur.sec+1][3])
                    grid[cur.fir][cur.sec][1] = 1;
                cur.sec++;
                break;
            case 'S':
                if (!grid[cur.fir-1][cur.sec][0])
                    grid[cur.fir][cur.sec][2] = 1;
                cur.fir--;
                break;
            case 'W':
                if (!grid[cur.fir][cur.sec-1][1])
                    grid[cur.fir][cur.sec][3] = 1;
                cur.sec--;
                break;
        }
    }
    int res = 0;
    dfs(1000,1000, res);
    cout << res;
}

int main(){
    setio("gates");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```