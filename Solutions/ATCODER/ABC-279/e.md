```

Notice that we only care about where 1 is at.

If the skipped operation does not change where 1 is at, then it just doesn't matter at all.

If the skipped operation did involve changing location of 1, it's simple as well. Instead of looking for 1, we need to look for the other one that 1 swapped with.

For each i-th operation (not the k operations), it points to one target element, if 1 isn't affected we still point to 1, if it is, we point to the other one! Then we can easily find the index of 1 at the final array. (Where we swap everything without skipping an operation)

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
    int n, m;
    cin >> n >> m;
 
    vi a(m);
    for(auto& i : a) cin >> i;
    
    vi b(n);
    for(int i{1}; i <= n; i++) b[i-1] = i;
 
    vi point(m, 1);
    for(int i{}; i < m; i++){
        if (b[a[i]-1] == 1){
            point[i] = b[a[i]];
        }else if (b[a[i]] == 1){
            point[i] = b[a[i]-1];
        }
 
        swap(b[a[i]-1], b[a[i]]);
    }
 
    map<int,int> at;
    for(int i{}; i < n; i++) at[b[i]] = i+1;
 
    for(int i{}; i < m; i++){
        cout << at[point[i]] << '\n';
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```