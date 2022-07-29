```
We are to maximize the number of cool buildings. 

Building is cool if it's taller than building i-1 and building i+1

Notice that if we have n = 7, excluding first and last building, we will have 5 buildings

_ _ _ _ _ 

The maximum cool buildings we can get is ceil(n-2/2)
In this case it's ceil(5/2) = 3

x _ x _ x

Notice that there isn't any other way to have 3 cool buildings only the above.


But if n = 8, excluding first and last, we will have 6 buildings, maximum = ceil(n-2/2) = 3

_ _ _ _ _ _ 

Ways to form 3 cool buildings when we have 6 buildings

x _ _ x _ x

x _ x _ _ x

x _ x _ x _

_ x _ x _ x

Notice that 

If we had the first building as cool building, there can be at most 1 gap of 2 buildings, the rest is 1. Whenever you decided to have 2 buildings between 2 cool buildings, you will basically start to build all the even-buildings as the cool buildings.

In other words, let's identify the below pattern

This is an odd pattern, all cool buildings are at odd

x _ x _ x _

This is an even pattern,

_ x _ x _ x

The moment where you decided to have a gap of 2, you will go from odd to even


x _ | _ | x _ x
odd       even

If we are to start at even building, there is no way we could have a 2 space building gap.

And we can basically try every 2-gap, and find the minimum amongst all, we could do that fairly easy with prefix sum array (cost to make i to j buildings as cool buildings)

One caveat is, take care of the border, make sure there is always o | e. 

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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
 
    vll a(n);
    for(auto& i : a) cin >> i;
    
    //mx cool building = ceil(n-2/2)
    //if n-2 == odd, only one way to maximum cool building
    ll res = 0;
    if ((n-2) % 2){
        for(int i{1}; i < n-1; i+=2){
            if (!(a[i] > a[i-1] && a[i] > a[i+1])){
                res += max(a[i-1],a[i+1])-a[i]+1;
            }
        }
    }else{
        vll prefix_o(n);
        vll prefix_e(n);
        for(int i{1}; i < n; i++){
            if (i % 2 && i < n-1){
                if (!(a[i] > a[i-1] && a[i] > a[i+1])) {
                    prefix_o[i] += max(a[i-1],a[i+1])-a[i]+1;
                }
            }
            prefix_o[i] += prefix_o[i-1];
        }
        for(int i{1}; i < n; i++){
            if (i % 2 == 0 && i < n-1){
                if (!(a[i] > a[i-1] && a[i] > a[i+1])) {
                    prefix_e[i] += max(a[i-1],a[i+1])-a[i]+1;
                }
            }
            prefix_e[i] += prefix_e[i-1];
        }
        
        res = min(prefix_e[n-1], prefix_o[n-1]);
 
        for(int i{1}; i < n-1; i+=2){
            res = min(res, prefix_o[i] + (i == n-3 ? INT_MAX : prefix_e[n-1]-prefix_e[i+1]));
        }
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