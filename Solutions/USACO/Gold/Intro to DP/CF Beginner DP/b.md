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

    string s;
    cin >> s;

    vi dp(n, -1);
    vi moves = {1,3,5};

    dp[0] = 0;
    for(int i{}; i < n; i++){
        for(int j{}; j < 3; j++){
            if (dp[i] != -1 && i + moves[j] < n && s[i+moves[j]] != 'w'){
                dp[i+moves[j]] = max(dp[i+moves[j]], dp[i] + (s[i+moves[j]] == '"'));
            }
        }
    }

    cout << (dp[n-1] == -1 ? -1 : dp[n-1]);
}
 
int main(){
    setio("lepus");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```