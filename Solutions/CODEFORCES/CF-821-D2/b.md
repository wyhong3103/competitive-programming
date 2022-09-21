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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int n, x, y;
    cin >> n >> x >> y;
 
 
    bool ok = 1;
    
    if (y > x) swap(x, y);
 
    if ((x && y)|| (!x && !y)) ok = 0;
    else if (!(!y && (n-1) % x == 0)) ok = 0;
 
    if (!ok) cout << -1 << '\n';
    else{
        int cur = 1;
        int cnt = 0;
        int temp = 2;
        for(int i{}; i < n-1; i++){
            cout << cur << ' ';
            cnt++;
            temp++;
            if (cnt % x == 0) cur = temp;
        }
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