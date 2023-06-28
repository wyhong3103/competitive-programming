
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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int n;
    cin >> n;
 
    vi a;
    bool found = 0;
    while(n--){
        int x;
        cin >> x;
        if (!sz(a)){
            a.pb(x);
            cout<<1;
        }else if (sz(a) == 1){
            found = x < a[0];
            a.pb(x);
            cout<<1;
        }
        else if (!found){
            if (x >= a.back()){
                a.pb(x);
                cout<<1;
            }else if (x < a.back() && a[0] >= x){
                a.pb(x);
                cout<<1;
                found = 1;
            }else{
                cout<<0;
            }
        }else if (found && x >= a.back() && x <= a[0]){
            a.pb(x);
            cout<<1;
        }else cout << 0;
    }
    cout<<'\n';
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