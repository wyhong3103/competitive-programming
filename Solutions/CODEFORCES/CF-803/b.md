The idea is if k >= 2, there will never be new pile of sands that are taller, this is because when k >= 2, no matter which sands you're trying to increase, it's neighbour will increase as well so they will never be taller. But if k == 1, maximum you can go is each intermediate sand.
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
    int n, k;
    cin >> n >> k;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    int res = 0;
    for(int i{1}; i < n-1; i++){
        if (a[i] > (a[i-1] + a[i+1])) res++;
    }
 
    if (k == 1){
        cout << (n-1)/2 << '\n';
    }else{
        cout << res << '\n';
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