Stupid question lol.
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
    int n, h, m;
    cin >> n >> h >> m;
 
    vector<pi> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;
    a.pb({h, m});
 
    sort(all(a));
    int cnt = 0;
    int index = 0;
    for(int i{} ; i <= n; i++){
        if (a[i].fir == h && a[i].sec == m){
            cnt++;
            index = i;
        }
    }
 
    if (cnt >= 2){
        cout << 0 << ' ' << 0 <<'\n';
    }else{
        pi time;
        if (index == n){
            time = a[0];
        }
        else time = a[index+1];
        cout << ((((((time.fir-h) % 24) + 24) % 24) - (time.sec < m)) + 24) % 24 << ' ' << ((((time.sec-m) % 60) + 60) % 60) << '\n';
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