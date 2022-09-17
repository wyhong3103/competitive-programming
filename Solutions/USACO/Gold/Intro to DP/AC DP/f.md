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
    string a, b;
    cin >> a >> b;

    int n = max(sz(a), sz(b)) + 1;

    vector<vector<pi>> dp(n, vector<pi> (n));

    for(int i{1}; i <= sz(a); i++){
        for(int j{1}; j <= sz(b); j++){
            dp[i][j] = dp[i-1][j];
            dp[i][j].sec = 0;
            if (dp[i][j-1].fir > dp[i][j].fir) dp[i][j] = {dp[i][j-1].fir, 1};
            if (a[i-1] == b[j-1] && dp[i-1][j-1].fir+1 > dp[i][j].fir) dp[i][j] = {dp[i-1][j-1].fir+1, 2};
        }
    }

    string res;
    int i = sz(a), j = sz(b);
    while (!(i == 0 || j == 0)){
        if (dp[i][j].sec == 1){
            j--;
        }
        else if (dp[i][j].sec == 2){
            res += a[i-1];
            i--;j--;
        }else i--;
    }

    for(int i{sz(res)-1}; i >= 0; i--){
        cout << res[i];
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