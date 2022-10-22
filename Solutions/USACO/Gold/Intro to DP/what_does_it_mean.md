```

dp[i][j] = number of different combinatiosn using j-th word that ends at i

transition

if s[i-a[j] : i] is one of the dictionary word

dp[i][j] *= dp[i-a[j]][k] for every 1 <= k <= n

base case

dp[0][0] = 1 

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

const int MOD = 1e9 + 7;
 
void solve(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    map<string, pi> dict;

    for(int i{}; i < n; i++){
        string x;
        int m;
        cin >> x >> m;
        dict[x] = {i+1, m};
    }

    vector<vll>  dp(sz(s)+1, vll(n+1));
    dp[0][0] = 1;

    for(int i{1}; i <= sz(s); i++){
        for(int j{1}; j <= min(i, 32); j++){
            if (dict.count(s.substr(i-j, j))){
                for(int k{}; k <= n; k++){
                    dp[i][dict[s.substr(i-j, j)].fir] = (dp[i][dict[s.substr(i-j, j)].fir] + (dp[i-j][k] * dict[s.substr(i-j,j)].sec) % MOD) % MOD;
                }
            }
        }
    }

    ll total = 0;
    for(int i{}; i <= n; i++){
        total += dp[sz(s)][i];
        total %= MOD;
    }
    cout << total;

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