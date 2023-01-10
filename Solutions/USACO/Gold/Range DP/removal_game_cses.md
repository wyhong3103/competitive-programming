```

At each player's turn, they're going to try and maximize their score.

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

const int MX = 5000 +5;
pll dp[MX][MX];

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;

    for(int i{}; i < n; i++) dp[i][i] = {(n % 2 ? a[i] : 0), (n % 2 ? 0 : a[i])};
    
    for(int i{2}; i <= n; i++){
        for(int j{}; j <= n-i; j++){
            pll l = dp[j][j+i-2];
            pll r = dp[j+1][j+i-1];
            //first player will take it when i is odd
            if (n % 2){
                //first player's turn
                if (i % 2){
                    l.fir += a[j+i-1];
                    r.fir += a[j];

                    //if both subarray have the same value, we take the one that has minimal on the opponent score
                    if (l.fir == r.fir){
                        dp[j][j+i-1] = {l.fir, min(l.sec, r.sec)};
                    }
                    else dp[j][j+i-1] = max(l,r);
                }else{
                //sec player's turn
                    l.sec += a[j+i-1];
                    r.sec += a[j];
                    swap(l.fir, l.sec);
                    swap(r.fir, r.sec);

                    //if both subarray have the same value, we take the one that has minimal on the opponent score
                    if (l.fir == r.fir){
                        dp[j][j+i-1] = {l.fir, min(l.sec, r.sec)};
                    }
                    else dp[j][j+i-1] = max(l,r);
                    swap(dp[j][j+i-1].fir, dp[j][j+i-1].sec);
                }
            }
            //first player will take it when i is even
            else{
                //first player's turn
                if (i % 2 == 0){
                    l.fir += a[j+i-1];
                    r.fir += a[j];

                    //if both subarray have the same value, we take the one that has minimal on the opponent score
                    if (l.fir == r.fir){
                        dp[j][j+i-1] = {l.fir, min(l.sec, r.sec)};
                    }
                    else dp[j][j+i-1] = max(l,r);
                }else{
                //sec player's turn
                    l.sec += a[j+i-1];
                    r.sec += a[j];
                    swap(l.fir, l.sec);
                    swap(r.fir, r.sec);
                    
                    //if both subarray have the same value, we take the one that has minimal on the opponent score
                    if (l.fir == r.fir){
                        dp[j][j+i-1] = {l.fir, min(l.sec, r.sec)};
                    }
                    else dp[j][j+i-1] = max(l,r);
                    swap(dp[j][j+i-1].fir, dp[j][j+i-1].sec);
                }

            }
        }
    }

    cout << dp[0][n-1].fir;
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