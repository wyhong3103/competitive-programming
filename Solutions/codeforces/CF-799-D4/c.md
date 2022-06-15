```cpp
#include <bits/stdc++.h>
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
        vector<string> grid(8);
        for(auto& i : grid) cin >> i;
 
        for(int i{1}; i < 7; i++){
            for(int j{1}; j < 7; j++){
                if (grid[i][j] == '#' && grid[i-1][j-1] == '#' && grid[i+1][j-1] == '#' && grid[i+1][j+1] == '#' && grid[i-1][j+1] == '#'){
                    cout << i+1 << ' ' << j+1 << '\n';
                }
            }
        }
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```