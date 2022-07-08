Simple Greedy LOL.
```cpp
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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    ll n, x;
    cin >> n >> x;
 
    vector<ll> stages(n);
    vector<ll> res(n);
 
    for(int i{}; i < n; i++){
        ll a, b;
        cin >> a >> b;
        stages[i] = b;
        res[i] = a+b;
        if (i > 0) res[i] += res[i-1];
    }
 
    ll mn = LONG_LONG_MAX;
    for(int i{}; i < n; i++){
        if (x - i <= 0) break;
        ll total = (x-(i+1)) * (stages[i]);
        total += res[i];
        mn = min(mn, total);
    }
 
    cout << mn;
 
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