```

Basically just OR every number, then find one number that is overlapping on every bit.

If it doesn't exist, that just mean every number has a unique bit, hence impossible.


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
 
const int MX = 2e5 + 5;
int cnt[MX];
 
void solve(){
    int n;
    cin >> n;
 
    vector<vi> c;
 
    for(int i{}; i < n; i++){
        int k;
        cin >> k;
        vi temp(k);
        for(auto& i : temp) cin >> i;
        c.pb(temp);
        for(auto& i : temp) cnt[i]++;
    }
 
    bool ok = 0;
    for(auto& i : c){
        bool extra = 1;
        for(auto& j : i){
            extra &= cnt[j] > 1;
        } 
        ok |= extra;
    }
 
    for(auto& i : c){
        for(auto& j : i){
            cnt[j]--;
        } 
    }
 
    cout << (ok ? "YES" : "NO") << '\n';
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