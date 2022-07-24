```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void open(int i, vector<bool>& b, vi& a){
    if (i <= 0) return;
    b[i-1] = 1;
    open(a[i-1],b,a);
}
 
void solve(){
    int n;
    cin >> n;
 
    vi a(3);
    for(auto& i : a) cin >> i;
    vector<bool> b(3);
    
    open(n, b, a);
    if (b[0] && b[1] && b[2]) cout << "YES";
    else cout << "NO";
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