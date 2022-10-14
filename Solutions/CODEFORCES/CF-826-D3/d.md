```

Something like merge sort, but modified!

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
 
vi recur(int l, int r , vi& a, bool& ok, int& total){
    if (l == r){
        return {a[l]};
    }
    
    int mid = (l+r)/2;
    vi left = recur(l, mid, a, ok, total);
    vi right = recur(mid+1, r, a, ok, total);
 
    if (abs(left[0]-right[0]) != (mid-l+1)){
        ok = 0;
    }
 
    vi sorted;
    if (left[0] > right[0]){
        total++;
        for(auto& i : right) sorted.pb(i);
        for(auto& i : left) sorted.pb(i);
    }else{
        for(auto& i : left) sorted.pb(i);
        for(auto& i : right) sorted.pb(i);
    }
    return sorted;
}
 
void solve(){
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
    bool ok = 1;
    int total = 0;
    recur(0, n-1, a, ok , total);
 
    if (ok){
        cout << total << '\n';
    }else cout << -1 << '\n';
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