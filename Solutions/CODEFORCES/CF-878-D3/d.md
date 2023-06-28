```

One person can handle a range of value, and each can work on multiple of them simultaneously.

Answer is basically the max range a person handled.

We can do binary search the answer x, let everyone handle range of x, in a sorted array of a, total segment that has length at most x*2+1 can be at most 3.

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
 
    sort(all(a));
    
    int lo = 0, hi = a.back();
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
 
        bool ok = 1;
        int cnt = 0;
        int prev = 0;
        for(int i{}; i < n; i++){
            if ((a[i]-a[prev]+1) / 2 > mid){
                prev = i; 
                cnt++;
            }
            if (cnt == 3) ok = 0;
        }
        
        if (ok) hi = mid;
        else lo = mid+1;
    }
    cout << lo << '\n';
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