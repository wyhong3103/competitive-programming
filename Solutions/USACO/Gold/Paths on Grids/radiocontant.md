```
DP state = [i-th location for farmer john, j-th location for bessie]

3 types of DP transition :

Farmer John moved , but Bessie didn't
dp[i][j] = min(dp[i][j], dp[i-1][j])

Bessie moved , but Farmer John didn't
dp[i][j] = min(dp[i][j], dp[i][j-1])

They both moved
dp[i][j] = min(dp[i][j], dp[i-1][j-1])

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


const int MX = 1005;
int dp[MX][MX];

int dist(pi p1, pi p2){
    int x = p1.fir-p2.fir;
    int y = p1.sec-p2.sec;
    return (x*x) + (y*y);
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pi> floc(n+1);
    vector<pi> bloc(m+1);
    cin >> floc[0].fir >> floc[0].sec >> bloc[0].fir >> bloc[0].sec;

    string fs, bs;
    cin >> fs >> bs;
    

    for(int i{1}; i <= n; i++){
        floc[i].fir = floc[i-1].fir + (fs[i-1] == 'E' ? 1 : (fs[i-1] == 'W' ? -1 : 0));
        floc[i].sec = floc[i-1].sec + (fs[i-1] == 'N' ? 1 : (fs[i-1] == 'S' ? -1 : 0));
    }

    for(int i{1}; i <= m; i++){
        bloc[i].fir = bloc[i-1].fir + (bs[i-1] == 'E' ? 1 : (bs[i-1] == 'W' ? -1 : 0));
        bloc[i].sec = bloc[i-1].sec + (bs[i-1] == 'N' ? 1 : (bs[i-1] == 'S' ? -1 : 0));
    }

    dp[0][0] = 0;

    for(int i{}; i <= n; i++){
        for(int j{}; j <= m; j++){
            if (i >= 1 || j >= 1){
                dp[i][j] = INT_MAX;
                if (i >= 1){
                    dp[i][j] = min(dp[i][j], dp[i-1][j]);
                }
                if (j >= 1){
                    dp[i][j] = min(dp[i][j], dp[i][j-1]);
                }
                if (i >= 1 && j >= 1){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
                dp[i][j] += dist(floc[i],bloc[j]);
            }
        }
    }

    cout << dp[n][m];
}
 
int main(){
    setio("radio");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}

```