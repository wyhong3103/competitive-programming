```

dp[i][j][l] = {maximal collected with l remainder when mod k, direction}

A pretty standard question, just the implementaiton. 

It's better if we flip the board. Instead from bottom to top, we go from top to bottom

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

//{maximal, -1 = dead end, 1 = L , 2 = R}
pi dp[105][105][15];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    k++;

    vector<string> a(n);
    for(auto& i : a) cin >> i;

    reverse(all(a));
    
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            for (int l{}; l < k; l++){
                dp[i][j][l] = {-1,-1};
            }
        }
    }

    for(int i{}; i < m; i++){
        dp[0][i][(a[0][i]-'0') % k] = {a[0][i]-'0', -1};
    }


    for(int i{1}; i < n; i++){
        for(int j{}; j < m; j++){
            int h = a[i][j]-'0';
            for(int l{}; l < k; l++){
                if (j && dp[i-1][j-1][l].fir != -1){
                    dp[i][j][(l + h) % k] = max(dp[i][j][(l+h) % k], {dp[i-1][j-1][l].fir+h, 2});
                }
                if (j < m-1 && dp[i-1][j+1][l].fir != -1){
                    dp[i][j][(l + h) % k] = max(dp[i][j][(l+h) % k], {dp[i-1][j+1][l].fir+h, 1});
                }
            }
        }
    }

    pi bst{-1, -1};
    for(int i{}; i < m; i++){
        bst = max(bst, {dp[n-1][i][0].fir, i});
    }

    if (bst.fir == -1){
        cout << -1 ;
        return;
    }

    cout << bst.fir << '\n';

    string res;
    pair<int,pi> cur = {0, {n-1, bst.sec}};

    while (dp[cur.sec.fir][cur.sec.sec][cur.fir].sec != -1){
        res += (dp[cur.sec.fir][cur.sec.sec][cur.fir].sec == 1 ? 'L' : 'R') ;
    
        if (dp[cur.sec.fir][cur.sec.sec][cur.fir].sec == 1){
            cur = {(((cur.fir - (a[cur.sec.fir][cur.sec.sec]-'0') ) % k) + k) % k, {cur.sec.fir-1, cur.sec.sec+1}};
        }else{
            cur = {(((cur.fir - (a[cur.sec.fir][cur.sec.sec]-'0') ) % k) + k) % k, {cur.sec.fir-1, cur.sec.sec-1}};
        }
    }
    cout << cur.sec.sec+1 << '\n';
    reverse(all(res));
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
