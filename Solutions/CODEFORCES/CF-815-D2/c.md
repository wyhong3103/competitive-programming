You only need 2 zeros to remove each 1 with one operation.
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
    int n,m;
    cin >> n >> m;
 
 
    vector<string> a(n);
    for(auto& i: a)cin>> i;
 
    int cnt = 0;
    int mn = INT_MAX;
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            cnt += a[i][j] == '1';
            if (i > 0){
                if (j > 0){
                    mn = min(mn, a[i-1][j]+a[i][j]+a[i][j-1]-(3*('0')));
                }
                if (j < m-1){
                    mn = min(mn, a[i-1][j]+a[i][j]+a[i][j+1]-(3*('0')));
                }
            }
            if (i < n-1){
                if (j > 0){
                    mn = min(mn, a[i+1][j]+a[i][j]+a[i][j-1]-(3*('0')));
                }
                if (j < m-1){
                    mn = min(mn, a[i+1][j]+a[i][j]+a[i][j+1]-(3*('0')));
                }
            }
        }
    }
 
    cout << cnt-(mn ? mn : 0)+(mn >= 1) << '\n';
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