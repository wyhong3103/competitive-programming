```

dp[i] = maximum stones the first player (not necessary takashi) can take until the end of the game


dp transition

dp[i] = max(dp[i], a[j] + (i-a[j]) - dp[i-a[j]]) , 1 <= i <= N, 0 < j < k

The idea is

If we're at i, we can take a[j] + (i-a[j] - dp[i-a[j]]) stones, this is because if we took a[i] stones, and the second player will be able to take dp[i-a[j]] at max, so what's left is simply i-a[j] - dp[i-a[j]]
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

const int MX = 1e4 + 1;
int dp[MX];

void solve(){
    int n, k;
    cin >> n >> k;


    vi a(k);
    for(auto& i : a) cin >> i;

    
    for(int i{1}; i <= n; i++){
        for(int j{}; j < k; j++){
            if (i-a[j] >= 0){
                dp[i] = max(dp[i], a[j] + ((i-a[j])-dp[i-a[j]]));
            }
        }
    }
    cout << dp[n];
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