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
    int n, q;
    cin >> n >> q;
 
    vll a(n);
    for(auto& i : a) cin >> i;
 
    pll odd{};
    pll even{};
    for(int i{}; i < n; i++){
        if (a[i] % 2){
            odd.fir += a[i];
            odd.sec++;
        }
        else{
            even.fir += a[i];
            even.sec++;
        }
    }
 
    while (q--){
        ll t, x;
        cin >> t >> x;
        if (x % 2 == 0){
            if (t) {
                odd.fir += (odd.sec * x);
            }
            else even.fir += (even.sec * x);
            cout << odd.fir+even.fir;
        }else{
            if (t){
                //odd to even
                odd.fir += odd.sec * x;
                even.fir += odd.fir;
                even.sec += odd.sec;
                odd.fir = 0;
                odd.sec = 0;
            }else{
                even.fir += even.sec * x;
                odd.fir += even.fir;
                odd.sec += even.sec;
                even.fir = 0;
                even.sec = 0;
            }
            cout << odd.fir+even.fir;
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