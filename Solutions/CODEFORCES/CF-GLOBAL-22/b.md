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
    int n, k;
    cin >> n >> k;
 
    vll s(k);
    for(auto& i : s) cin >> i;
    
    if (n == 1){
        cout << "YES" << '\n';
        return;
    }
 
 
    bool ok = 1;
    ll cur = INT_MAX;
    for(int i{k-1}; i >= 1; i--){
        if (s[i]-s[i-1] <= cur){
            cur = s[i]-s[i-1];
        }else ok = 0;
    }
 
    
    if (cur > 0){
        if (!(s[0] <= 0 || ceil(s[0]/(double)cur) <= n-(k-1))){
            ok = 0;
        }
    }
    else{
        if (!(s[0] <= cur * (n-(k-1)))) ok = 0;
    }
 
    
    if (ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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