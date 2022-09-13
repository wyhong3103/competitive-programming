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
    string s, p;
    cin >> s >> p;

    vi a(sz(s));
    for(auto& i : a) cin >> i;

    auto good = [&](int mid){
        vector<bool> removed(sz(s));
        for(int i{}; i <= mid; i++){
            removed[a[i]-1] = 1;
        }

        int at = 0;
        for(int i{}; i < sz(s); i++){
            if (removed[i]) continue;
            if (at < sz(p) && s[i] ==  p[at]) at++;
        }
        return at == sz(p);
    };

    int lo = 0, hi = sz(s)-1;
    while (hi > lo){
        int mid = lo+(hi-lo+1)/2;
        if (good(mid)){
            lo = mid;
        }else hi = mid-1;
    }

    cout << (good(lo) ? lo+1 : 0);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
 

```