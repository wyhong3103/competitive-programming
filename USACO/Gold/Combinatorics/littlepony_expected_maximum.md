```

EV = sum ((probability of getting max i with n throws)* i), 1 <= i <= m

We can find the probability of getting max i with n throws with simple combinatorics

For example, the probability of getting at most 2 with 2 throws ,in a 6 sided dice is (2^2)/(6^2), and the probability of getting max as 3 is simply (3^2)/(6^2) - (2^2)/(6^2), 

at most 3 - at most 2 = at max 3

To avoid integer overflow with i^n, for each probability we can do

(i/m)^n
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


double binpow(double n, int p){
    if (!p) return 1.0;

    double sq = binpow(n, p/2);
    sq = sq * sq;

    if (p%2) return sq * n;
    return sq;
}

void solve(){
    int m, n;
    cin >> m >> n;

    double res = 0;
    for(int i{1}; i <= m; i++){
        res += (binpow(((double)i)/m, n) - binpow(((double)(i-1))/m,n)) * i;
    } 

    cout << setprecision(6) << fixed;
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