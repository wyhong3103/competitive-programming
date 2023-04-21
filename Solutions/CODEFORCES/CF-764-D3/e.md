```

Every segment has to be of at least length 2.

Notice that, only segment with lenght of 2 and 3 matters. Since we can use them to cover all even and odd segments.

We can find every substring of length 2 and 3 from the n strings.

And then do something like interval DP on the string n.

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<string> a(n);
    for(auto& i : a) cin >> i;
 
    string s;
    cin >> s;
 
    map<string, pair<pi,int>> mp;
 
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (j+1 < m) mp[a[i].substr(j, 2)] = {{j, j+1},i};
            if (j+2 < m) mp[a[i].substr(j, 3)] = {{j, j+2},i};
        } 
    }
 
    vector<pair<pi,int>> dp(m,{{-1,-1},-1});
 
    for(int i{}; i < m; i++){
        if (i && dp[i-1].sec == -1) continue;
        if (i+1 < m && mp.count(s.substr(i, 2))){
            dp[i+1] = mp[s.substr(i, 2)];
        }
        if (i+2 < m && mp.count(s.substr(i, 3))){
            dp[i+2] = mp[s.substr(i, 3)];
        }
    }
 
    if (dp.back().sec == -1){
        cout << -1 << '\n';
    }else{
        vector<pair<pi,int>> res;
        int at = m-1;
        while (at >= 0){
            res.pb(dp[at]);
            at -= dp[at].fir.sec-dp[at].fir.fir+1;
        }
        reverse(all(res));
        cout << sz(res) << '\n';
        for(auto& i :res){
            cout << i.fir.fir+1 << ' ' << i.fir.sec+1 << ' ' << i.sec+1 << '\n';
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```