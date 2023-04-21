```

Only consecutive number of ones mattered.

Check the maximal consecutive number of ones.

The maximal area for a consecutive of ones, is simply, max((sz-i) * (i+1)), i from 0 to sz-1

Special case is the case for the ones that is connected from both ends.

we cannot get maximal rotation for these ones. The maximal rotation is max(length of 1s from the end, min(length of start + end, n-length of end -1))


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
    string s;
    cin >> s;
 
    int n = sz(s);
 
    int p = -1;
    for(int i{}; i < n; i++){
        if (s[i] == '0'){
            p = i;
            break;
        }
    }
 
    if (p == -1){
        cout << (ll)sz(s) * (ll)sz(s) << '\n';
    }else{
        ll mx = 0;
        ll cnt = 0;
        for(int i{}; i < n; i++){
            if (s[i] == '1'){
                cnt++;
            }else{
                mx = max(mx, cnt);
                cnt = 0;
            }
        }
 
        mx = max(mx, cnt);
 
        ll res = 0;
        for(ll i{}; i < mx; i++){
            res = max(res, (mx-i) * (i+1));
        }
 
        if (sz(s) >= 2 && s[0] == '1' && s.back() == '1'){
            ll b = 0;
            for(int i{}; i < n; i++){
                b += s[i] == '1';
                if (s[i] == '0') break;
            }
            ll e = 0;
            for(int i{n-1}; i >= 0; i--){
                e += s[i] == '1';
                if (s[i] == '0') break;
            }
 
            for(ll i{}; i <= max(e, min(b+e, n-e-1)); i++){
                res = max(res, ((b+e)-i) * (i+1));
            }
        }
        cout << res << '\n';
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