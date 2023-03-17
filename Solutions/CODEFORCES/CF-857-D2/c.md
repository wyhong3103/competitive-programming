```

Notice that we just need to make each 2x2 has the same XOR.

Each 2x2 has 2 same row, and 2 same col.

We could just assign any different number to every column, every 2x2 is going to XOR to 0, this is becuase, each column in the 2x2 is involed twice in the 2x2.

And then for each row we can assign a row ID to it, shifted by the the largest bit we have for each column.

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
    int n, m;
    cin >> n >> m;
 
    vector<vll> a(n, vll(m));
 
 
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            a[i][j] = j;
        }
    }
 
 
    for(int i{1}; i < n; i++){
        for(int j{}; j < m; j++) a[i][j] += (i << (__lg(m) + 1));
    }
 
    cout << n * m << '\n';
    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            cout << a[i][j] << ' ';
        } 
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