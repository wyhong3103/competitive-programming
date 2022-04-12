```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){ 
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
    
    ll mn = 0;

    ll pref = 0;
    ll ans = -numeric_limits<ll>::max();

    for(int i{}; i < n; i++){
        pref += a[i];
        if (pref < mn){
            mn = pref; 
        }else{
            ans = max({ans, pref - mn, (ll)a[i]});
        }
        ans = max({ans, (ll)a[i]});
    }

    cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```