```

We can have 3 array a1,a2,a3 which stores the element of a1, a2 and a3, if element i exist in aj, then aj[i] = 1, then make them a prefix sum.

Let's find the amount needed to fill in prefix i and remove the extra elements while not touching array 3 at all 

With the equation, prefix[i] = a2[i] + a1[n-1]-a[i];

a1[n-1]-a[i] gives how many element do we need to remove, a2[i] is the amount of swapping we need for a2[i]. Notice that this will not fill prefix of a1 in some situations, because there could be elements <= i that is in array 3.

And then fix every suffix i in array 3, notice that if we are to fix at suffix i, every element < i in array 3 will be removed anyway!!! so we just have to choose the prefix minimum of the prefix array, and when we take the elements we have to remove into account, the elements are either going to array 2, or array 1. No matter which prefix array i we choose, we have to remove them regardless, so we can just choose the one that needs the minimal move.

Edge cases

Middle array and suffix array only
Middle array only
suffix array only
prefix array only

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
    vi k(3);
    for(auto& i : k) cin >> i;

    int n = k[0] + k[1] + k[2];
    vector<vi> a(3, vi(n));

    for(int i{}; i < 3; i++){
        for(int j{}; j < k[i]; j++){
            int x;
            cin >> x;
            x--;
            a[i][x] = 1;
        }
    }

    for(int i{}; i < 3; i++){
        for(int j{1}; j < n; j++){
            a[i][j] += a[i][j-1];
        }
    }
    
    vi mn(n);
    for(int i{}; i < n; i++){
        mn[i] = a[1][i] + (a[0][n-1]-a[0][i]);
        if (i) mn[i] = min(mn[i], mn[i-1]);
    }

    int res = n - max({a[0][n-1], a[1][n-1], a[2][n-1]});

    for(int i{n-1}; i >= 1; i--){
        res = min(res, mn[i-1] + a[1][n-1] - a[1][i-1] + a[2][i-1]);
        res = min(res, ((n-1-(i-1)) - (a[2][n-1]-a[2][i-1])) + (i - a[1][i-1]));
    }

    cout << res << '\n';
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