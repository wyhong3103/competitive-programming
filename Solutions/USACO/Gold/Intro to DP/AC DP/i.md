```

dp[i][j] = probability of coin i being the j-th heads

base case,

dp[0][0] = 1 (No coin, no haed = 100%)

dp transition,


dp[i][j] = (dp[i-1][j-1] * a[i]) + (dp[i-1][j] * (1-a[i]))

We sum it up when it's an independent event.

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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    int n;
    cin >> n;

    vector<double> a(n);
    for(auto& i : a) cin >> i;


    vector<vector<double>> dp(n+1, vector<double> (n+1));
    dp[0][0] = 1;

    for(int i{1}; i <= n; i++){
        for(int j{}; j <= n; j++){
            if (j-1 >= 0) dp[i][j] = dp[i-1][j-1] * a[i-1];
            dp[i][j] += dp[i-1][j] * (1-a[i-1]);

        }
    }

    double res = 0;
    for(int i{(n/2)+1}; i <= n; i++){
        res += dp[n][i];
    }

    cout << setprecision(10) << fixed;
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