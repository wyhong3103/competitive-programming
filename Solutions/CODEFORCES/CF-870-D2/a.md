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
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i :a) cin >> i;
 
    map<int,int> mp;
 
    for(int i{}; i < n; i++){
        mp[a[i]]++;
    }
 
    bool ok = 0;
    int sm = 0;
    for(auto& i : mp){
        sm += i.sec;
        if (n-sm >= i.fir && (mp.rbegin()->fir == i.fir || (mp.upper_bound(i.fir)->fir > n-sm))) ok = 1;
        if (ok) break;
    }
 
    cout << (!ok ? -1 : n-sm) << '\n';
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