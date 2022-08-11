```

DP state = [Subset S, i number of men]

DP Value = Number of ways to form pairs that are compatible with the women that are selected (bit is 1) with only using first i men

DP transition = dp[s][i] + dp[s^(1<<j)][i-1], such that the j-th bit (0 <= j < n) is 1, and j-th woman and i-th man is compatible.

Note that in transition for each subset, 

we will only be using the same i-th man, and i = number of bits that are on, this is because in order to find the number of ways we can form pairs with first i men and those particular women that are selected, we only need to find to which j-th woman is compatible with i-th man, if they are compatible, then we can transition from the same subset but without j-th woman, and i-th man, so naturally it's just dp[s^(1<<j)][i-1].


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
using vdb = vector<double>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

const int MX = 21;
const int MOD = 1e9 + 7;
ll dp[1<<MX][MX];
bool compatible[MX][MX];

void solve(){
    int n;
    cin >> n;

    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            cin >> compatible[i][j];
        }
    }

    for(int s{1}; s < (1 << n); s++){
        int cur = __builtin_popcount(s) - 1;
        for(int i{}; i < n; i++){
            if ((s & (1 << i)) && compatible[i][cur]){
                if (!cur) dp[s][cur] = (dp[s][cur] + 1) % MOD;
                else dp[s][cur] = (dp[s][cur] + dp[s^(1<<i)][cur-1]) % MOD;
            }
        }
    }

    cout << dp[(1<<n)-1][n-1];
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