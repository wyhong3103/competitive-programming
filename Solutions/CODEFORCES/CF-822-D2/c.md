```

Turned out doing a sieve-like algorithm wouldn't cost too much time. When we got to 1000, it only takes 1000 to reach 1e6. I am not sure about the time complexity yet, will update here.

```
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
    int n;
    cin >> n;
 
    vector<bool> checked(n);
 
    string s;
    cin >> s;
    
    ll cnt = 0;
    
    for(int i{1}; i <= n; i++){
        for(int j{i-1}; j < n; j+=i){
            if (checked[j]) continue;
            if (s[j] == '1'){
                break;
            }else{
                checked[j] = 1;
                cnt += i;
            }
        }
    }
 
    cout << cnt << '\n';
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