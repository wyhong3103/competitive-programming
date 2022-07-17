```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, c, q;
    cin >> n >> c >> q;
 
    string s;
    cin >> s;
 
    map<ll, pll> mp;
    mp[n] = {1, n};
 
    for(int i{}; i < c; i++){
        ll f, t;
        cin >> f >> t;
        auto it = --mp.end();
        mp[it->fir + 1 + (t - f) ] = {f, t};
    }
 
 
    while (q--){
        ll k;
        cin >> k;
        auto it = mp.lower_bound(k); 
        ll x = (it == mp.begin() ? k : (k - (((--it)->fir)+1)) + ((++it)->sec.fir));
        while (x > n){
            auto it2 = mp.lower_bound(x); 
            x = (it2 == mp.begin() ? x : (x - (((--it2)->fir)+1)) + ((++it2)->sec.fir));
        }
        cout << s[x-1] << '\n';
    }
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