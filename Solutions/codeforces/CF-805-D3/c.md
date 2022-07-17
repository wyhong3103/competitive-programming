```cpp
#include <bits/stdc++.h>
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
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    vector<ll> a(n);
    for(auto& i : a){
        cin >> i;
    }
    
    //store furtherst index {to}
    //store closest index (from)
 
    map<ll,int> from;
    map<ll,int> to;
    for(int i{};i < n; i++){
        if (!from.count(a[i])){
            from[a[i]]  = i;
        }
        if (!to.count(a[i])){
            to[a[i]]  = i;
        }
 
        from[a[i]] = min(i, from[a[i]]);
        to[a[i]] = max(i, to[a[i]]);
    }
 
    while (k--){
        int a, b;
        cin >> a >> b;
        if (to.count(a) && to.count(b) && from[a] <= to[b]) cout << "YES" ;
        else cout << "NO";
        cout << '\n';
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