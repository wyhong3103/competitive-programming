```
it's like sliding window, and there are n-m+1 windows, we are to find the min (mex of the windows)

first window might need linear time to compute to find all the missing value

second window , it's either the same mex or something missing earlier

store all the mex <= M in the first window

pop it off

add it to the mex set

maintain the mex set

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
    vi a(n);
    for(auto& i : a) cin >> i;
 
    multiset<int> ms;
    set<int> mexs;
    for(int i{}; i < m; i++){
        ms.insert(a[i]);
    }
    for(int i{}; i <= m; i++){
        if (ms.find(i) == ms.end()) mexs.insert(i);
    }
 
    int mn = *mexs.begin();
    for(int i{m}; i < n; i++){
        ms.erase(ms.find(a[i-m]));
        if (ms.find(a[i-m]) == ms.end()){
            mexs.insert(a[i-m]);
        }
        ms.insert(a[i]);
        if (mexs.count(a[i])) mexs.erase(a[i]);
 
        mn = min(*mexs.begin(), mn) ;
    }
    cout << mn;
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