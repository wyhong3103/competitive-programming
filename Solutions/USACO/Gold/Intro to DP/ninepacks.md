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

const int MXN = 105;
const int MXW = 105 * 1005;
int dp_a[MXN][MXW];
int dp_b[MXN][MXW];

void solve(){
    int n, m;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
    cin >> m;
    vi b(m);
    for(auto& i : b) cin >> i;

    for(int i{}; i < MXW; i++){
        dp_a[0][i] = INT_MAX;
        dp_b[0][i] = INT_MAX;
    }
    dp_a[0][0] = dp_b[0][0] = 0;
    
    for(int i{1}; i <= n; i++){
        for(int j{1}; j <= n * 1000; j++){
            dp_a[i][j] = dp_a[i-1][j];
            if (j - a[i-1] >= 0 && dp_a[i-1][j-a[i-1]] != INT_MAX){
                dp_a[i][j] = min(dp_a[i][j], dp_a[i-1][j-a[i-1]]+1);
            }
        }
    }

    for(int i{1}; i <= m; i++){
        for(int j{1}; j <= m * 1000; j++){
            dp_b[i][j] = dp_b[i-1][j];
            if (j - b[i-1] >= 0 && dp_b[i-1][j-b[i-1]] != INT_MAX){
                dp_b[i][j] = min(dp_b[i][j], dp_b[i-1][j-b[i-1]]+1);
            }
        }
    }

    int mn = INT_MAX;
    for(int j{1}; j < MXW; j++){
        if (dp_a[n][j] != INT_MAX && dp_b[m][j] != INT_MAX && dp_a[n][j] && dp_b[m][j]) mn = min(mn, dp_a[n][j] + dp_b[m][j]);
    }

    if (mn == INT_MAX) cout << "impossible";
    else cout << mn;
    
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