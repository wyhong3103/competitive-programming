```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
 
using namespace std;
using vi = vector<int>;
using ll = long long;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 
 
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(m);
    for(auto& i : a) cin >> i.fir >> i.sec;
 
    sort(all(a), [](pair<int,int> a, pair<int,int> b){
        return a.sec > b.sec;
    });
 
    ll ans = 0;
 
    for(auto& i : a){
        if (n){
            int nmber = min(i.fir,n);
            n -= nmber;
            ans += nmber * i.sec;
        }else{
            break;
        }
    }
    cout << ans;
}
 
int main(){
    //setIO("t");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```