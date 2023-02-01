```

Notice that in order for there to be t mountains and t-1 valley, we must first start with a mountain and then ends with a mountain as well. 

DP state

dp[i][j][k] = number of ways to form j mountains & valleys so far at i with the last height = k

there is going to be 2*t-1 mountain and valleys. 

If j is an odd number, that means the last we had is a mountain,

which implies the current gradient is going down (since we just had a mountain), so we got 2 type of choice to make

either keep going down

or go up (get one valley)

Same to an even number! But for gaining mountain or keep going up.

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


const int MXN = 30;
const int MXH = 30;
const int MXT = 4;

ll dp[MXN][MXH][MXT];

void solve(){
    int n, t;
    cin >> n >> t;

    for(int i{}; i < 4; i++) dp[0][0][i] = 1;

    for(int i{}; i < 4; i++){
        for(int j{i+1}; j < 4; j++){
            dp[1][0][j] += dp[0][0][i];
        }
    }
    
    for(int i{1}; i < n-1; i++){
        for(int j{}; j <= 2*t-1; j++){
            for(int k{}; k < 4; k++){
                if (j % 2){
                    for(int l{}; l < k; l++) dp[i+1][j][l] += dp[i][j][k];
                    for(int l{k+1}; l < 4; l++) dp[i+1][j+1][l] += dp[i][j][k];
                }else{
                    for(int l{k+1}; l < 4; l++) dp[i+1][j][l] += dp[i][j][k];
                    for(int l{}; l < k; l++) dp[i+1][j+1][l] += dp[i][j][k];
                }
            }
        }
    }

    int res = 0;
    for(int i{}; i < 4; i++){
        res += dp[n-1][2*t-1][i];
    }
    cout << res;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}


```