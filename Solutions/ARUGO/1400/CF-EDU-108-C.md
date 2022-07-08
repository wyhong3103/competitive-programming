Greedy + Prefix Sum.
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
    int n;
    cin >> n;

    vector<ll> res(n);
    
    map<int,vector<ll>> mp;

    vi a(n);
    for(auto& i : a) cin >> i;

    vi b(n);
    for(auto& i : b) cin >> i;

    for(int i{}; i < n; i++){
        mp[a[i]].pb(b[i]);
    }

    for(auto& i : mp){
        sort(all(i.sec));
        for(int j{1}; j < sz(i.sec); j++){
            i.sec[j] += i.sec[j-1];
        }

        int total = sz(i.sec);
        int k = 1;
        while (total > 0){
            res[k-1] += i.sec[sz(i.sec)-1] - (sz(i.sec)-total ? i.sec[(sz(i.sec)-total)-1] : 0);
            k++;
            total = (sz(i.sec)/k) * k;
        }
    }

    for(int i{}; i < n; i++) cout << res[i] << ' ';
    cout << '\n';
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