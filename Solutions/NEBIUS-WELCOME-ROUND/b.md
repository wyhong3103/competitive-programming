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
    ll n, k, d, w;
    cin >> n >> k >> d >> w;
 
    vll t(n);
    for(auto& i : t) cin >> i;
 
    ll open = -1;
    ll remain = 0;
    ll used = 0;
    for(int i{}; i < n; i++){
        if (open != -1 && t[i] - open > d){
            remain = 0;
            open = -1;
        }
 
        if (open == -1){
            open = t[i] + w;
            remain += k;
            used++;
        }
 
 
        if (remain){
            remain--;
        }
        if (!remain) open = -1;
    }
 
    cout << used << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}
```