A greedy problem, the perfect rest stops we're going to stop at is the global maximum after i-th, bessie location. And the time we're going to be at the rest stop is the difference between the time needed for bessie to reach the rest stop and the time needed for farmer jorn to reach the rest stop.
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
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int l, n, rf, rb;
    cin >> l >> n >> rf >> rb;

    vector<pi> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;

    sort(all(a), [](pi a,pi b){
        if (a.sec == b.sec){
            return a.fir > b.fir;
        }
        return a.sec > b.sec;
    });

    
    vector<pi> dest;
    pi cur = a[0];
    dest.pb(cur);
    for(auto& i : a){
        if (i.fir > dest[sz(dest)-1].fir){
            dest.pb(i);
        }
    }

    ll res = 0;
    //keep tracks of their location
    int bs{};
    int fj{};
    for(auto& i : dest){
        ll timebs = (ll)(i.fir-bs) * rb;  
        ll timefj = (ll)(i.fir-fj) * rf;
        bs = i.fir;
        fj = i.fir;
        res += (ll)(timefj-timebs) * i.sec;
    }
    cout << res;
}
 
int main(){
    setio("reststops");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```