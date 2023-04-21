```

Find MEX m, first

if the length of the array is exactly MEX length, then it is impossible to make m+1 the MEX, since replacing one will make the MEX smaller


if m+1 exist in the array, find the first and last occurence of it, make sure everything in between is redundant (bigger than MEX OR duplicated), replace it with m

else we can just replace any element bigger than m with m


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
 
    map<int,int> freq;
 
    for(auto& i : a){
        freq[i]++;
    }
 
    //find MEX
    int cur = 0;
    for(auto& i : freq){
        if (i.fir != cur) break;
        else cur++;
    }
 
    if (n == cur){
        cout << "NO" << '\n';
        return;
    }
    
    pi ft{-1,-1};
    for(int i{}; i < n; i++){
        if (a[i] == cur+1) {
            if (ft.fir == -1) ft.fir = i;
            ft.sec = i;
        }
    }
 
    if (ft.fir == -1){
        cout << "YES" << '\n';
    }else{
        for(int i{ft.fir}; i <= ft.sec; i++){
            freq[a[i]]--;
        }
        bool ok = 1;
        for(auto& i : freq){
            if (i.fir < cur){
                ok &= i.sec >= 1;
            }
        }
 
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
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