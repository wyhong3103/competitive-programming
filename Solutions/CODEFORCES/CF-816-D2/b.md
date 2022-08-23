```
because you simply can't truncate the value, the best you could truncate down the value is k-1 , (because %k)

each value can takes up to k-1 value to truncate it down

b*k = floored sum

s-floored sum <= n*(k-1)
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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
 
    ll floored_sum = b*k;
 
    if (s-floored_sum > n*(k-1) || floored_sum > s){
        cout << -1 << '\n';
        return;
    }else{
        ll remain = s-floored_sum;
 
        vll a(n);
        a[0] = floored_sum;
        int at = 0;
        while (remain){
            a[at] += min(remain, k-1);
            at++;
            remain -= min(k-1, remain);
        }
        for(auto& i : a) cout << i << ' ';
        cout << '\n';
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