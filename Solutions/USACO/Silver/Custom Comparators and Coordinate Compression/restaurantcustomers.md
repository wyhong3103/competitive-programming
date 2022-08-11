The idea of this problem is pretty straightfoward, we simply need to compress the coordinate , and make a difference array, and get the largest number we could.
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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 

void solve(){
    int n;
    cin >> n;
    
    vector<pi> updates(n);

    map<int, int> mp;
    vi a;
    for(int i{}; i < n; i++){
        int f, t;
        cin >> f >> t;
        a.pb(t);
        a.pb(f);
        updates[i] = {f, t};
    }

    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    
    for(int i{}; i < sz(a); i++){
    	//storing the compressed coordinate
        mp[a[i]] = i;
    }

    vi diff(sz(a));
    for(auto& i : updates){
        diff[mp[i.fir]]++;
        diff[mp[i.sec]]--;
    }

    int mx = diff[0];
    for(int i{1}; i < sz(a); i++){
        diff[i] = diff[i] + diff[i-1];
        mx = max(mx, diff[i]);
    } 
    cout << mx;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```