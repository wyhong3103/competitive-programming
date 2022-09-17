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
    vector<string> r(10);
    for(auto& i : r) cin >> i;
 
 
    pi f {INT_MAX, 0};
    pi s {INT_MAX, 0};
    for(int i{}; i < 10; i++){
        for(int j{}; j < 10; j++){
            if (r[i][j] == '#'){
                f.fir = min(i, f.fir);
                f.sec = max(i, f.sec);
                s.fir = min(j, s.fir);
                s.sec = max(j, s.sec);
            }
        }
    }
    cout << f.fir+1 << ' ' << f.sec+1 << '\n';
    cout << s.fir+1 << ' ' << s.sec+1 << '\n';
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