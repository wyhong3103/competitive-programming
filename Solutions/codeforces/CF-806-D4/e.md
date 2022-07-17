In order for a grid to be the same even after rotated 90 deg, 180 deg, 270 deg, every cell at those rotated position must be the same. The only reason I got it wrong the first time is I misinterpreted the rotated position.
```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int n;
    cin >> n;
 
    vector<string> grid(n);
    for(auto& i: grid) cin >> i;
 
    //only look for quater
 
    int res = 0;
    
    if (n%2){
        for(int i{}; i < n/2; i++){
            pi cnt{};
            if (grid[i][n/2] == '0')  cnt.fir++;
            else cnt.sec++;
            if (grid[n/2][i] == '0')  cnt.fir++;
            else cnt.sec++;
            if (grid[n-(i+1)][n/2] == '0')  cnt.fir++;
            else cnt.sec++;
            if (grid[n/2][n-(i+1)] == '0')  cnt.fir++;
            else cnt.sec++;
            res += min(cnt.fir, cnt.sec);
        }
    }
 
    for(int i{}; i < (n)/2; i++){
        for(int j{}; j < (n)/2; j++){
            pi cnt{};
            if (grid[i][j] == '0'){
                cnt.fir++;
            }else cnt.sec++;
 
            if (grid[j][n-(i+1)] == '0'){
                cnt.fir++;
            }else cnt.sec++;
 
            if (grid[n-(i+1)][n-(j+1)] == '0'){
                cnt.fir++;
            }else cnt.sec++;
 
            if (grid[n-(j+1)][i] == '0'){
                cnt.fir++;
            }else cnt.sec++;
            
            res += min(cnt.fir, cnt.sec);
        }
    }
    cout << res << '\n';
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