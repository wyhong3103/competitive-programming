```

Approach

We count the minimal answer for every x, s.t there will be x 1s at the end of the string.

Observation

1. If we ever have to swap a 0 throught more than 1s, it's better to just remove it!


Solution

We store all the number of 0s before the xth 1 from the end except for the 0 between xth 1 and x-1th 1.

we will swap the 0 betwee xth and xth 1, and remove all the 0s after that.

next thing we do is remove all the 1s.

All of these can be done in O(1).

we also have to try the case where only 1 / 0 is remaining.

O(N) solution cus we try all x.

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
 
    ll n = sz(s);
 
    ll op = 1e12;
    ll total = 0;
    for(auto& i : s){
        total += i == '1';
    }
 
    ll res = min(total * (op + 1), (n-total)*(op+1));
    
    ll cur = 1;
    ll prev = 0;
    ll cnt = 0;
    for(int i{n-1}; i >= 0; i--){
        if (s[i] == '0') {
            cnt++;
        }else{
            res = min(res, prev * (op+1) + cnt * op + ((total-cur) * (op+1)));
            prev += cnt;
            cnt = 0;
            cur++;
        }
    }
    cout << res << '\n';
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