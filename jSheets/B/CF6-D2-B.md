```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
 
using namespace std;
using vi = vector<int>;
using ll = long long;
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 

set<char> deputy;
bool vis[101][101];
int n, m;
char c;
vector<string> room(101);

void dfs(int i, int j){
    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || room[i][j] == '.'){
        return;
    }

    if(room[i][j] != c){
        deputy.insert(room[i][j]);
        return;
    }

    vis[i][j] = true;

    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i, j-1);
}

 
void solve(){
    cin >> n >> m;
    cin >> c;
    
    for(int i{}; i < n; i++){
        cin >> room[i];
    }
    
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (room[i][j] == c){ 
                dfs(i, j);
                break;
            }
        }
    }

    cout << sz(deputy);
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```