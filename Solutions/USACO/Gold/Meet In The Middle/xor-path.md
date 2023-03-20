```

Initial Approach (WRONG)

Divide The Grid into Two Half

The reason this is wrong is that, we're not actually dividing the search space into two. The correct thing to divide into two is the number of moves!!

Also, we could iterate through the subset of (n+m-2)/2 (half of the number of moves), if its 1 we move down, 0 right.

For one half we start from (1,1), and go in the down right fashion, the other half we start from (n,m) and go in up left fashion.

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
    ll n, m, k;
    cin >> n >> m >> k;


    vector<vll> a(n, vll(m));

    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            cin >> a[i][j];
        }
    }

    if (m == 1){
        ll cur = 0;
        for(int i{}; i < n; i++) cur ^= a[i][0];

        cout << (cur == k);
        return;
    }

    vector<vector<map<ll,ll>>> moves(n, vector<map<ll,ll>> (m));

    int l = (n+m-2)/2;
    for(int i{}; i < (1 << l); i++){
        pi at{0, 0};
        ll sm = a[0][0];
        for(int j{}; j < l; j++){
            if (i & (1 << j)){
                at.fir++;     
            }else{
                at.sec++;     
            }
            if (at.fir >= n || at.sec >= m) break;
            sm ^= a[at.fir][at.sec];
        }
        if (at.fir < n && at.sec < m){
            moves[at.fir][at.sec][sm]++;
        }
    }

    ll res = 0;
    int r = (n+m-2) - l;
    for(int i{}; i < (1 << r); i++){
        pi at{n-1, m-1};
        ll sm = a[n-1][m-1];
        for(int j{}; j < r; j++){
            if (i & (1 << j)){
                at.fir--;     
            }else{
                at.sec--;
            }
            if (at.fir < 0 || at.sec < 0) break;
            sm ^= a[at.fir][at.sec];
        }
        if (at.fir >= 0 && at.sec >= 0){
            res += moves[at.fir][at.sec][k ^ (sm ^ a[at.fir][at.sec])];
        }
    }
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