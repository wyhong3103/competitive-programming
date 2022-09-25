```

Nothing much, it was just about observing the pattern.

A cell in a rectangle could only reach by

between cells that are above, and all cell that are upper left

an inverted triangle basically.
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
    
    for(int i{}; i < n; i++){
        cout << 1 << ' ';
        for(int j{1}; j < i; j++){
            cout << 0 << ' ';
        }
        if (i) cout << 1;
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