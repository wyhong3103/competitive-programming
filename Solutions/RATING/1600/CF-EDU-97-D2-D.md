```

If the order goes in increasing order, then we could keep adding it as a child of the same previous node. Else, we add it to the next parent node of the previous level, if it has been used up, we simply create a new level.


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
    for(auto& i : a) cin >> i;

    int res = 1;
    int prev = 1;
    int cur = 0;
    for(int i{1}; i < n; i++){
        if (a[i] < a[i-1]){
            prev--; 
            if (!prev){
                prev = cur;
                cur = 0;
                res++;
            }
        }
        cur++;
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