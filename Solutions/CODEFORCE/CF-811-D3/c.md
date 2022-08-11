We can bruteforce it, since 2^9 = 512 only.
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
    
 
    string res = "";
    for(int i{}; i < (1 << 9); i++){
        string temp;
        int cnt = 0;
        for(int j{}; j < 9; j++){
            if ((i >> j) & 1){
               temp.pb((j+1) + '0');
               cnt += j+1;
            }
        }
        if (cnt == n){
            sort(all(temp));
            if (res == "") res = temp;
            else if (sz(temp) < sz(res)) res = temp;
            else if (sz(temp) == sz(res) && temp < res) res = temp;
        }
    }
 
    cout << res << '\n';
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