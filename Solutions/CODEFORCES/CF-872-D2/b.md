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
    int n, m;
    cin >> n >> m;
 
    vll a(n*m);
    for(auto& i : a) cin >> i;
 
    sort(all(a));
 
    ll total1 = 0;
    total1 += (a.back() - a[0]) * (n-1) * (m-1);
    total1 += max(n-1, m-1) * (a.back() - a[0]);
    total1 += min(n-1, m-1) * (a[n*m-2]-a[0]);
 
    ll total2 = 0;
    total2 += (a.back() - a[0]) * (n-1) * (m-1);
    total2 += max(n-1, m-1) * (a.back()-a[0]);
    total2 += min(n-1, m-1) * (a.back()-a[1]);
 
    cout << max(total1, total2) << '\n';
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