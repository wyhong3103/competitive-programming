```

Greedily fill out zero on the right!

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
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
    
    set<int> s;
    for(int i{}; i < n; i++){
        if (a[i] == 1) s.insert(i);
    }
 
    int cnt = 0;
    for(int i{n-1}; i >= 0; i--){
        if (a[i] == 0 && sz(s) && i > *s.begin()){
            s.erase(*s.begin());
            cnt++;
        }
    }
 
    cout << cnt << '\n';
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