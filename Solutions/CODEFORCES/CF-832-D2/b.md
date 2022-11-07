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
 
    int cur = n*3;
    int at = 2;
    vector<pi> res;
    for(int i{}; i < n/2; i++){
        res.pb({at, cur});
        at += 3;
        cur -= 3;
    }
    if (n % 2 != 0){
        res.pb({1, cur});
    }
    cout << sz(res) << '\n';
    for(auto& i : res) cout << i.fir << ' ' << i.sec << '\n';
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