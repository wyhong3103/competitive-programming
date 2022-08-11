```
The idea of solving this problem is actually pretty simple.


First thing first, 

if we have two connections

a <-> b

a1 <-> b1

One fact is that, in order for them to not intersect, or have the same endpoints, a1 > a && b1 > b

So this is just like the transition on dp[i-1][j-1]

Okay, now let's get into DP

dp state = [i-th field, j-th field] = maximum crosswalk we could get so far at [i-th field,j-th field]

dp transition = max(dp[i-1][j], dp[i][j-1])

if abs(a-b) <= 4, then dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j])
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

const int MX = 1001;
int dp[MX][MX];

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;
    vi b(n);
    for(auto& i : b) cin >> i;


    for(int i{1}; i <= n; i++){
        for(int j{1}; j <= n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (abs(a[i-1] - b[j-1]) <= 4){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            }
        }
    }

    cout << dp[n][n];
}
 
int main(){
    setio("nocross");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}

```