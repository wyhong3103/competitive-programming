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
    ll a, b;
    cin >> a >> b;
 
    ll steps = a/b;
 
    int cur = b % 10;
    vi cycle;
    cycle.pb(cur);
    while (true){
        cur += b % 10; 
        cur %= 10;
        if (cur == cycle[0]) break;
        else cycle.pb(cur);
    }
 
    ll total_cycles = steps/sz(cycle);
    ll remain = steps % ((int)sz(cycle));
    ll total = 0;
    ll total1 = 0;
    for(int i{}; i < sz(cycle); i++){
        if (i < remain) total += cycle[i];
        total1 += cycle[i];
    }
 
    cout << total + (total_cycles*total1) << '\n';
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