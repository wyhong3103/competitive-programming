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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(auto& i : a) cin >> i;
    int mx = 0;
    for(int i{}; i < n; i++){
        mx = max(a[i], mx);
    }
 
    bool ok = 0;
    for(int i{}; i < k; i++){
        int x;
        cin >> x;
        x--;
        if (a[x] == mx) ok = 1;
    }
 
    cout << (ok ? "Yes" : "No");
 
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```