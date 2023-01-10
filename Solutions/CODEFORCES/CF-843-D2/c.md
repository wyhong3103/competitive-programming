```
We just need to know min step needed to get rid of all the 1s that is in n but not in x, and the max step you can go before any of the 1 (common between n and x) turn 0.

And then if min steps >= mx steps, impossible otherwise just min+1

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
    ll n, x;
    cin >> n >> x;
 
    
    bool ok = 1;
 
    for(int i{}; i < 63; i++){
        if ((x & (1LL << i)) && !(n & (1LL << i))) ok = 0;
    }
 
 
    //number of turn we can go while making sure all the bit stays
    ll mn = LONG_LONG_MAX;
    for(int i{}; i < 63; i++){
        if (x & (1LL << i)){
            ll prev = 0;
            for(int j{}; j < i; j++){
                if (n & (1LL << j)) prev += (1LL << j);
            }
            mn = min((1LL << i)-prev, mn);
        }
    }
 
    //number of turn needed to get rid of all the unnecessary
    ll mx = 0;
    for(int i{}; i < 63; i++){
        if (!(x & (1LL << i)) && (n & (1LL << i))){
            ll prev = 0;
            for(int j{}; j < i; j++){
                if (n & (1LL << j)) prev += (1LL << j);
            }
            mx = max((1LL << i)-prev, mx);
        }
    }
 
    if (!ok || mx >= mn){
        cout << -1 << '\n'; 
    }else cout << n+mx << '\n';
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