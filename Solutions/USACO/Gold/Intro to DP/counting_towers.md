```

Notice that at each row,

the cell is either a double cell or a single cell!

oo / o|o

Notice that from 

oo

We can build these these pattern on top of it

---------------------------

oo
oo

o|o
___
o o

oo
__
oo

3 patterns in total

---------------------------

From 

o|o

We can build these these pattern on top of it

---------------------------

o|o
___
o|o


o|o
  _
o|o


o|o
_
o|o


o|o
o|o

o o
___
o|o

5 patterns in total

---------------------------

Note that there is one pattern in oo and o|o each that turns the top cell to the opposite.


o o
___
o|o


o|o
___
o o


So that means for every transition

dp[i][0] = dp[i-1][0] * 4 + dp[i-1][1]
dp[i][1] = dp[i-1][1] * 2 + dp[i-1][0]

first type of cell : 4 transition fromm the same type, 1 from different
second type of cell : 2 transition from the same type, 1 from different
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

const int MOD = 1e9 + 7;
const int MXN = 1e6 + 5;

int mx = 1;
pll dp[MXN];

void solve(){
    int n;
    cin >> n;
    if (n <= mx){
        cout << (dp[n].fir + dp[n].sec) % MOD << '\n';
        return ;
    }

    for(int i{mx+1}; i <= n; i++){
        dp[i].fir = (((dp[i-1].fir * 4) % MOD) + (dp[i-1].sec)) % MOD;
        dp[i].sec = (((dp[i-1].sec * 2) % MOD) + (dp[i-1].fir)) % MOD;
        mx++;
    }

    cout << (dp[n].fir + dp[n].sec) % MOD << '\n';
} 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1].fir = 1;
    dp[1].sec = 1;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```