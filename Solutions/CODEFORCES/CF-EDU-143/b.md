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
    int n, k;
    cin >> n >> k;
 
    vector<pi> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;
 
    vector<pi> included;
    for(auto& i : a){
        if (i.fir <= k && i.sec >= k){
            included.pb(i);
        }
    }
 
 
    vi cnt(55);
 
    for(auto& i : included){
        for(int j{i.fir}; j <= i.sec; j++) cnt[j]++;
    }
 
    bool ok = 1;
    for(int i{}; i < 55; i++){
        if (i != k && cnt[i] >= cnt[k]) ok = 0;
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