```

Might be tempted to use kadane or what not, but this is not the case!

Kadane works in O(N) (without the restriction of the window size), prefix sum + set works in O(n log n)!


The idea is

Iterate through the array, keep the borders (prefix sum of i-b to i-a) in a multiset, as we iterate through the array (sliding window) remove the one that is out of window size and then add the one that is new. Max is simply current prefix[i] - least element in the muliset.

Caveat : 

Set mx to -INF

If we are to find the prefix sum of i - prefix sum of i-a, the actual arithmetic would be p[i] - p[i-a-1] (the element before it)!
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
    int n, a, b;
    cin >> n >> a >> b;

    vll arr(n);
    for(auto& i : arr) cin >> i;

    vll prefix(n);
    for(int i{}; i < n; i++){
        prefix[i] = arr[i];
        if (i) prefix[i] += prefix[i-1];
    }

    multiset<ll> ms;
    
    ll mx = -LONG_LONG_MAX;
    for(int i{a-1}; i < n; i++){
        ms.insert((i-a < 0 ? 0 : prefix[i-a]));
        if (i >= b){
            ms.erase((i-b-1 < 0 ? ms.find(0) : ms.find(prefix[i-b-1])));
        }
        mx = max(mx, prefix[i] -  (*(ms.begin())) );
    }
    cout << mx;
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