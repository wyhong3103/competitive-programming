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
 
bool recur(int at, ll sm, int longest, int& mn, vi& arr){
    int n = sz(arr);
    if (at == n){
        mn = min(longest, mn);
        return true;
    }
 
    int cur = 0;
    for(int i{at}; i < n; i++){
        if (cur < sm) cur += arr[i];
 
        if (cur == sm){
            longest = max(longest, i-at+1);
            return recur(i+1, sm, longest, mn, arr);
        }
        if (cur > sm){
            return false;
        }
    }
    return false;
}
 
void solve(){
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    ll sm = 0;
    int mn = INT_MAX;
    for(int i{}; i < n; i++){
        sm += a[i];
        recur(i+1, sm, i+1, mn, a);
    }
    cout << mn << '\n';
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