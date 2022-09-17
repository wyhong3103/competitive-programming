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


void solve(){

    vector<vi> board(8, vi(8));
    for(int i{}; i < 8; i++){
        for(int j{}; j < 8; j++) cin >> board[i][j];
    }

    vector<vll> dp(8, vll(8, INT_MAX));
    dp[7][0] = 0;

    for(int i{7}; i >= 0; i--){
        for(int j{}; j < 8; j++){
            if (i+1 < 8){
                dp[i][j] = min(dp[i][j], dp[i+1][j] + board[i][j]);
            }
            if (j-1 >= 0){
                dp[i][j] = min(dp[i][j], dp[i][j-1] + board[i][j]);
            }
            if (i+1 < 8 && j-1 >= 0){
                dp[i][j] = min(dp[i][j], dp[i+1][j-1] + board[i][j]);
            }
        }
    }
    cout << dp[0][7];
}
 
int main(){
    setio("king2");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```