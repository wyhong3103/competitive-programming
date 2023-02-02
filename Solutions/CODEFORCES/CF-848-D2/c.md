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
    ll n, k;
    cin >> n >> k;
 
    string a, b;
    cin >> a >> b;
 
    set<char> diff;
 
 
    for(auto& i : a){
        diff.insert(i);
    }
 
    if (k >= sz(diff)){
        cout << (n * (n+1))/2 << '\n';
        return;
    }
 
    vector<char> diffv;
 
    for(auto& i : diff) diffv.pb(i);
 
    ll mx = 0;
    for(int i{}; i < (1 << sz(diffv)); i++){
        if (__builtin_popcount(i) == k){
            set<char> selected;
            for(int j{}; j < sz(diffv); j++){
                if (i & (1 << j)){
                    selected.insert(diffv[j]);
                }
            }
 
            ll total = 0;
            ll cur = 0;
            for(int j{}; j < n; j++){
                if (selected.count(a[j]) || a[j] == b[j]) cur++;
                else{
                    total += (cur*(cur+1))/2;
                    cur = 0;
                }
            }
            total += (cur*(cur+1))/2;
            mx = max(mx, total);
        }
    }
 
    cout << mx << '\n';
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