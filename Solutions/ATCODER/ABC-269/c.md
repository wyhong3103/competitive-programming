```
Recursive subset

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
 
ll n;
 
void recur(ll at, ll total, set<ll>& res){
    if ((1LL << at) > n) return;
    res.insert(total);
    recur(at+1, total, res);
    if ((n >> at) & 1LL){
        total += 1LL << at;
        res.insert(total);
        recur(at+1, total, res);
        total -= 1 << at;
    }
}
 
 
void solve(){
    cin >> n;
 
    set<ll> res;
    res.insert(0);
    recur(0, 0, res);
    for(auto& i : res) cout << i << '\n';
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