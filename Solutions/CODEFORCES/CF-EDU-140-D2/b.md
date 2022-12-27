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
    ll res;
    cin >> res;
    vll a(n-1);
    for(auto& i : a) cin >> i;
    sort(all(a));
 
    for(int i{}; i < n-1; i++){
        if (a[i] > res){
            ll lo = 0, hi = a[i];
            while (hi > lo){
                ll mid = lo + (hi-lo+1)/2;
                if (a[i]-mid >= res+mid){
                    lo = mid;
                }else hi = mid-1;
            }
            res += (a[i]-lo > res+lo ? lo+1 : lo);
        }
    }
 
    cout << res << '\n';
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