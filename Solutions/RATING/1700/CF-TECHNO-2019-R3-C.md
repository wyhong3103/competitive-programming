```
So there is only 5 option for each key, obviously, we could do DP on it.

DP state = [i-th key, j-th finger]
DP value = the last finger we transitioned from
DP transtion =

If a[i] > a[i-1], then we transition from dp[i-1][k] such that 0 <= k < j, j is current finger
If a[i] < a[i-1], then we transition from dp[i-1][k] such that j < k <= n-1, j is current finger
If a[i] == a[i-1], then we could transition from dp[i-1][k] such that 0 <= k <= n-1, and k != j

Finally, we simply restore the trasition from the value.
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

const int MXN = 1e5;
int dp[MXN][5];

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;
    
    memset(dp, -1, sizeof(dp));
    for(int i{}; i < 5; i++) dp[0][i] = 5;

    for(int i{1}; i < n; i++){
        for(int j{}; j < 5; j++){
            if (a[i] > a[i-1]){
                for(int k{j-1}; k >= 0; k--){
                    if (dp[i-1][k] != -1) dp[i][j] = k;
                }
            }else if (a[i] < a[i-1]){
                for(int k{j+1}; k < 5; k++){
                    if (dp[i-1][k] != -1) dp[i][j] = k;
                }
            }else{
                for(int k{}; k < 5; k++){
                    if (k == j) continue;
                    if (dp[i-1][k] != -1) dp[i][j] = k;
                }
            }
        } 
    }


    int ok = -1;
    for(int i{}; i < 5; i++){
        if (dp[n-1][i] != -1) ok = i;
    }
    
    if (ok == -1) cout << -1;
    else{
        int cur = ok;
        vi res(n);
        for(int i{n-1}; i > 0; i--){
            res[i] = cur;
            cur = dp[i][cur];
        }
        res[0] = cur;

        for(auto& i : res) cout << i+1 << ' ';
    }
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