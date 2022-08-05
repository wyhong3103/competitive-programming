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
    int n;
    cin >> n;
 
    vi a;
    cout << (n-2)+2 << '\n';
    for(int i{}; i < n;i++){
       a.pb(i+1);
    }
 
    for(auto& i : a) cout << i << ' ';
    cout << '\n';
    swap(a[0], a[1]);
    for(int i{2}; i < n; i++){
        for(auto& i : a) cout << i << ' ';
        cout << '\n';
        swap(a[0], a[i]);
    }
    for(auto& i : a) cout << i << ' ';
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