Got AC with lucks, it wasn't supposed to work lol, I literally brute forced it, trying every combinations to see if we can reach from one cow to other cow without a road. This problem is similar to the one we did previously, where we have to assign the fences, that is tougher in my opinion, for this problem, it's okay to assign the road from both ways, because if we detect a road from either side, we're just going to skip it. But the last problem is different. This problem is fairly easy I would say.
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

const int MAX = 105;
int farm[MAX][MAX][4];
bool vis[MAX][MAX];
int n, k, r;

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,-1,1};

void dfs(pi at, pi dest, bool& found){
    if (at.fir == dest.fir && at.sec == dest.sec){
        found = true;
        return;
    }

    vis[at.fir][at.sec] = true;

    for(int i{}; i < 4; i++){
        if (!(at.fir+dr[i] < 0 || at.sec+dc[i] < 0 || at.fir+dr[i] >= n || at.sec+dc[i] >= n || vis[at.fir+dr[i]][at.sec+dc[i]])){
            if (i < 2){
                if (!farm[at.fir][at.sec][dr[i] == 1 ? 0 : 2]){
                    dfs({at.fir+dr[i], at.sec+dc[i]}, dest, found);
                }
            }else{
                if (!farm[at.fir][at.sec][dc[i] == 1 ? 1 : 3]){
                    dfs({at.fir+dr[i], at.sec+dc[i]}, dest, found);
                }
            }
        }
        if (found) return;
    }
}

void solve(){
    cin >> n >> k >> r;
    for(int i{}; i < r; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--;y--;a--;b--;
        if (x == a){
            farm[x][y][(y-b == 1 ? 3 : 1)] = 1;
            farm[a][b][(y-b == 1 ? 1 : 3)] = 1;
        }else{
            farm[x][y][(x-a == 1 ? 2 : 0)] = 1;
            farm[a][b][(x-a == 1 ? 0 : 2)] = 1;
        }
    }

    vector<pi> cows;
    for(int i{}; i < k; i++){
        int r, c;
        cin >> r >> c;
        r--;c--;
        cows.pb({r,c});
    }

    int count = 0;
    for(int i{}; i < k; i++){
        for(int j{i+1}; j < k; j++){
            bool found = false;
            memset(vis,0,sizeof(vis));
            dfs(cows[i], cows[j], found);     
            if (!found) count++;
        }
    }
    cout << count;
}

int main(){
    setio("countcross");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```
A better way of solving it,	we can basically see it as a few connected components, and the answer is literally the combinations cows in a connected components 

```cpp
#include <bits/stdc++.h>

using namespace std;

const int MX = 1e2;

bool vis[MX][MX];
int cows[MX][MX], di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1}, nCows, n, k, r;
set<tuple<int, int, int, int>> roads;

void ff (int i, int j, int i1, int j1) {
	if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || roads.count(tie(i, j, i1, j1))) return;

	vis[i][j] = true;
	//Plus cow at the same spot
	nCows += cows[i][j];

	for (int k = 0; k < 4; k++) {
		ff (i + di[k], j + dj[k], i, j);
	}
}

int main () {
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);

	cin >> n >> k >> r;

	for (int i = 0; i < r; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		tuple<int, int, int, int> cur = tie(y1, x1, y2, x2);
		tuple<int, int, int, int> cur1 = tie(y2, x2, y1, x1);
		roads.insert(cur);
		roads.insert(cur1);
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		cows[y][x]++;
	}

	vector<int> cowsComponent;
	int totalCows = 0;
	//Determining the number of connected components and the number of cows in it
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;
			nCows = 0;
			ff (i, j, -1, -1);
			totalCows += nCows;
			if (nCows) cowsComponent.push_back(nCows);
		}
	}

	int sol = 0;
	//Answer
	for (int i = 0; i < (int) cowsComponent.size(); i++) {
		for (int j = i + 1; j < (int) cowsComponent.size(); j++) {
			sol += cowsComponent[i] * cowsComponent[j];
		}
	}

	cout << sol << '\n';
}
```