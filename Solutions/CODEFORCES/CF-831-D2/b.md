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
 
    vector<pll> a(n);
    for(auto& i : a){
        cin >> i.fir >> i.sec;
        if (i.sec > i.fir) swap(i.fir, i.sec);
    }
 
    sort(all(a));
        
    ll prev = a[0].fir;
    ll total = a[0].fir + (2 * a[0].sec);
    for(int i{1}; i < n; i++){
        total += a[i].fir - prev;
        prev = a[i].fir;
        total += 2* a[i].sec;
    }
    total += prev;
    cout << total << '\n';
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