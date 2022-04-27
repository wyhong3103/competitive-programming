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
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        vector<string> grid(n);
        for(auto& i : grid) cin >> i;
 
        for(int i{n-2}; i >= 0; i--){
            for(int j{}; j < m; j++){
                int row = i, col = j;
                if (grid[i][j] != '*') continue;
                while (row < n-1 && grid[row+1][col] == '.'){
                    grid[row][col] = '.';
                    grid[row+1][col] = '*';
                    row++;
                }
            }
        }
 
        for(auto& i : grid) cout << i << '\n';
        cout << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```