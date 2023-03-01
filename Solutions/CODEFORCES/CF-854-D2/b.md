```

We just need a single 2, and we can make every number 2!

Impossible case = when we have more than a 1 or a 1 and a non 1

How to get 2, if we dont have one??

find a big and small number, keep dividing big by small number, eventually we will get 2, except when big == small.

The idea is, if we have get to a point where ceil(x/y) = 1, which mean y > x, if we flip them, ceil(y/x) will equal to 2, this is because y = x + z, z < x, (x + z) / x = x/x + z/x = 1 + ceil(z/x) = 2

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    pi mn = {INT_MAX, -1}, mx ={0, -1};
    for(int i{}; i < n; i++){
        mn = min(mn, {a[i],i});
        mx = max(mx, {a[i], i});
    }
 
    if (mn.fir == 1 && mx.fir > 1){
        cout << -1 << '\n';
        return;
    }
    
    if (n == 1 || mn.fir == mx.fir){
        cout << 0 << '\n';
        return;
    }
 
    vector<pi> total;
 
    int found = -1;
    for(int i{}; i < n; i++){
        for(int j{}; j < i; j++){
            int nu = i, de = j;
            if (a[nu] < a[de]) swap(nu, de);
            while (a[de] != 2){
                if (a[nu] == a[de]) break;
                
                a[nu] = a[nu] / a[de] + (a[nu] % a[de] > 0);
                total.pb({nu, de});
                if (a[nu] < a[de]) swap(nu, de);
            }
            if (a[de] == 2) found = de;
            if (found != -1) break;
        }
    }
 
    if (found != -1){
        for(int i{}; i < n; i++){
            while (a[i] != 2){
                a[i] = a[i] / 2 + a[i] % 2;
                total.pb({i, found});
            }
        }
 
        cout << sz(total) << '\n';
        for(auto& i :total) cout << i.fir+1 << ' ' << i.sec+1 << '\n';
 
    }else{
        bool ok = 1;
        for(int i{}; i < n; i++){
            ok &= a[i] == a[0];
        }
 
        if (!ok){
            cout << -1 << '\n';
            return;
        }
        cout << sz(total) << '\n';
        for(auto& i :total) cout << i.fir+1 << ' ' << i.sec+1 << '\n';
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