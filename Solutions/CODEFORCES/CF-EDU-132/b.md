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
 
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    vll diffup(n);
    vll diffdown(n);
    for(int i{1}; i < n; i++){
        if (a[i] > a[i-1]) continue;
        diffup[i] = abs(a[i] - a[i-1]);
    }
 
    for(int i{1}; i < n; i++){
        if (a[i] < a[i-1]) continue;
        diffdown[i] = abs(a[i] - a[i-1]);
    }
 
    vll prefix(n);
    for(int i{1}; i < n; i++){
        prefix[i] += (diffup[i] + prefix[i-1]);
    }
 
    vll prefix1(n);
    for(int i{1}; i < n; i++){
        prefix1[i] += (diffdown[i] + prefix1[i-1]);
    }
    
    while (m--){
        int f,t;
        cin >> f >> t;
        f--;t--;
        if (f > t){
            cout << prefix1[f]- prefix1[t];
        }else{
            cout << prefix[t]- prefix[f];
        }
        cout << '\n';
    }
    
 
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```