```

We can solve this problem by solving both axis independently!

Here are a few fact

- We should always start with going x axis at the positive direction
- We should go in alternate direction (x, y, x, y)

Every even indices are for sure going in y axis, odd are x axis

The idea is

we could dp it, since A is very small, we can cover it all!

dp_x[i][j] = whether we can reach j on x axis at i-th move
dp_y[i][j] = whether we can reach j on y axis at i-th move

transition is simple,

if i is even,

dp_x[i+1][j] = for every j in x axis (we do not move in even move for x axis)
dp_y[i+1][j+a[i] / j-a[i]] = for every j in y axis

if i is odd,

dp_y[i+1][j] = for every j in y axis (we do not move in even move for y axis)
dp_x[i+1][j+a[i] / j-a[i]] = for every j in x axis

if dp_x[n][x] && dp_y[n][y] is true,then yes.

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


void solve(){
    int n, x, y;
    cin >> n >> x >> y;

    set<pll> o;
    set<pll> e;

    vi a(n);
    for(auto& i :a) cin >> i;

    vector<set<int>> dp_x(n+5);
    vector<set<int>> dp_y(n+5);
    dp_x[1].insert(a[0]);
    dp_y[1].insert(0);

    for(int i{1}; i < n; i++){
        if (i % 2){
            for(auto& j : dp_y[i]){
                dp_y[i+1].insert(j-a[i]);
                dp_y[i+1].insert(j+a[i]);
            }     
            for(auto& j : dp_x[i]){
                dp_x[i+1].insert(j);
            }     
        }else{
            for(auto& j : dp_x[i]){
                dp_x[i+1].insert(j-a[i]);
                dp_x[i+1].insert(j+a[i]);
            }     
            for(auto& j : dp_y[i]){
                dp_y[i+1].insert(j);
            }     
        }
    }

    cout << (dp_x[n].count(x) && dp_y[n].count(y) ? "Yes" : "No");
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