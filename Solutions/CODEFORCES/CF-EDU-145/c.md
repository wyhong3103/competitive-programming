```

Find the first k+1 subarray, where the order of subarray is the order of every subarray from [i,n] for every i from 1 to n.


Once we found the subarray.

f, f, f, [h, x, x, x, t], x, x, x, ..., x

We set t as -100, and h as 50, because this guarantee h that before we iterates through t when h is the first elment of the subarray we are guarnateed to get negative sum.

For every f, we let it be 1000, so that it guarantees that every head with f has positve sum.

Every x, we let it be -1, as they need to be negative sum, when they're alone.

We would have k positive sum subarray and (n*(n+1))/2 - k negative sum subarray at the end.

case where k == (n*(n+1)/2), just let everything be 1

case where k == n == 1, just print 1

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
    int n, k;
    cin >> n >> k;
 
    if (n == 1 && k == 1){
        cout << 1 << '\n';
        return;
    }else if (k >= (n*(n+1))/2){
        for(int  i{}; i < n; i++) cout << 1 <<' ';
        cout<<'\n';
        return;
    }
 
    vi a(n);
 
    int cnt = 0;
    bool found = 0;
    int ed = 0;
    for(int i{}; i < n; i++){
        for(int j{i}; j < n; j++){
            cnt++; 
            if (cnt == k+1){
                ed = j;
                found = 1;        
                break;
            }
        }
        if (found){
            for(int j{}; j < i; j++) a[j] = 1000;
            for(int j{i}; j < n; j++) a[j] = -1;
            a[ed] = -100;
            if (i != ed) a[i] = 50;
            break;
        }
    }
    for(auto& i : a) cout << i << ' ';
    cout << '\n';
    
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