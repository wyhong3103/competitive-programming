```

Got lucky

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
    
    vi a(n);
 
    vi p(n);
 
    for(auto& i : a){
        cin >> i;
        p[i-1]++;
    }
 
    bool ok=  1;
    int prefix_u{};
    int prefix_n{};
    for(int i{}; i < n; i++){
        if (!p[i]) prefix_u++;
        if (p[i] == 2) prefix_n++;
        ok &= prefix_u >= prefix_n;
        ok &= p[i] <= 2;
    }
 
    map<int,int> mp;
    set<int> unused;
    for(int i{}; i < n; i++){
        if (!p[i]) unused.insert(i+1);
        else if (p[i] == 2){
            mp[i+1] = *unused.begin();
            unused.erase(*unused.begin());
        }
    }
 
    if (!ok){
        cout << "NO" << '\n';
    }else{
        cout << "YES" << '\n';
        vi res_a(n);
        vi res_b(n);
 
 
        for(int i{}; i < n; i++){
            if (p[a[i]-1] == 1){
                res_a[i] = a[i];
                res_b[i] = a[i];
            }else if (p[a[i]-1] == 2){
                res_a[i] = a[i];
                res_b[i] = mp[a[i]];
                p[a[i]-1]++;
            }else if (p[a[i]-1] == 3){
                res_b[i] = a[i];
                res_a[i] = mp[a[i]];
            }
        }
        for(auto& i : res_a) cout << i << ' ';
        cout << '\n';
        for(auto& i : res_b) cout << i << ' ';
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