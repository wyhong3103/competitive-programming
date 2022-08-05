There might be a better way to compute it, but here is my way of doing it.
```
Implementation is hell, bruh....

Anyways,

First observation,

Due to the fact that we could only visit each cell once, and we can only visit it if the current time > the value on the cell.

So the only possible moves are moves like wiggling, snake-like movmeent, zig-zag

DRDR
RURU.....

And at each "wiggle"/"snake-like movement"/"zig-zag", we could do a turning-back.

DLLLLLLLL
RRRRRRRRU

DRDRRRRRD
RURULLLLL

It's better to visualize it.


####################################################################################################

Now it's the implementation.

How do we compute the turning back?

Note that at each turning-back, we first move to the end , and then up/down move to the column we at

i.e, say we at [i][j], we first move to [i][n-1] then [!i][n-1] , finally [!i][j]

Now we could break this down into two parts, which is prefix and suffix

Suffix works the same as the prefix, so we will only demonstrate prefix here.

Say this is the row

0 10 10 10

We could store the minimal time we need to reach the i-th cell on this row from left to right (prefix), so it would be

0 11 12 13

Another example,

0 17 17 18

to

0 18 19 20

If we're at the 2nd column, and out current time is 18, the best possible time we could reach the end, is 20, as the 20 is based on the 18 as well.

If our current time is 17, the best time we could reach the end is also 20, 

If there isn's a single prefix that is > than our current time, then the time we need to reach the final cell is simply, current time + cell remaining to visit. This is because if none of the (minimal) time is bigger than us, we could simply visit them without waiting.

####################################################################################################

To generalize it, 

If there is one cell that would block us along the way to the end, then the answer is simply prefix[n-1], else current time + cell remaining

Now we could compute this using binary search, and that's all!
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

    vector<vll> a(2);
    for(auto& i : a) i.resize(n);

    for(int i{}; i < 2; i++){
        for(int j{}; j < n; j++) cin >> a[i][j];
    }

    vector<vll> prefix(2);
    vector<vll> suffix(2);

    for(int i{}; i < 2; i++){
        prefix[i].resize(n);
        suffix[i].resize(n);
    }

    prefix[0][0] = 0;
    prefix[1][0] = max(a[1][0]+1,1LL);
    for(int i{}; i < 2 ; i++){
        ll cur = prefix[i][0];
        for(int j{1}; j < n; j++){
            cur = max(a[i][j]+1, cur+1);
            prefix[i][j] = cur;
        }
    }

    suffix[0][n-1] = max(a[0][n-1]+1,prefix[1][n-1]+1);
    suffix[1][n-1] = max(a[1][n-1]+1,prefix[0][n-1]+1);
    for(int i{}; i < 2 ; i++){
        ll cur = suffix[i][n-1];
        for(int j{n-2}; j >= 0; j--){
            cur = max(a[i][j]+1, cur+1);
            suffix[i][j] = cur;
        }
    }

    ll ans = LONG_LONG_MAX;
    ll cur = 0;
    for(int i{}; i < n-1; i++){
        ll total = cur;
        //prefix
        int lo = i+1, hi = n-1;
        while (hi > lo){
            int mid = lo + (hi-lo+1)/2;
            if (total+(mid-i) >= prefix[(i%2)][mid]){
                lo = mid;
            }else hi = mid-1;
        }
        if (lo == n-1 && (total+(lo-i)) >= prefix[i%2][lo]){
            total += (n-1)-i;
        }else total = prefix[i%2][n-1];

        total = max(total+1, suffix[!(i%2)][n-1]);
        //suffix
        lo = i, hi = n-2;
        while (hi > lo){
            int mid = lo + (hi-lo)/2;
            if (total+(n-1-mid) >= suffix[!(i%2)][mid]){
                hi = mid;
            }else lo = mid+1;
        }
        if (lo == i && (total+(n-1-lo)) >= suffix[!(i%2)][lo]){
            total += (n-1)-i;
        }else total = suffix[!(i%2)][i];

        ans = min(ans, total);
        //transition
        cur = max(cur+1, a[!(i%2)][i]+1);
        cur = max(cur+1, a[!(i%2)][i+1]+1);
    }

    //there's no need for binary search at n-1, so we can just compute it manually
    cout << min(ans, max(cur+1, a[!((n-1)%2)][n-1]+1)) << '\n';
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