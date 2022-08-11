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
    int n, q;
    cin >> n >> q;
 
    vector<ll> p(n);
    for(auto& i : p) cin >> i;
 
    sort(all(p));
 
    vector<ll> prefix(n);
    prefix[0] = p[0];
    for(int i{1}; i < n; i++){
        prefix[i] = prefix[i-1] + p[i];
    }
    
    for(int i{}; i < q; i++){
        int x, y;
        cin >> x >> y;
        if (x < n){
            cout << prefix[n-1-(x-y)] - prefix[n-1-(x)] << '\n';
        }else{
            cout << prefix[y-1] << '\n';
        }
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```