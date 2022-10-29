```

Observations

1. It is always optimal to open first i pipes!

2. Time needed to fill up all the locks decreases and number of pipes increases.

3. Water leaked from lock i can only contribute to lock i+1...n

Can we precompute the time needed to fill up all the locks if we are to open first i pipes, for all i? And then simply binary search at each query? 

Well, that is the way to solve this problem!

The tricky part is to figure out the precomputation part. We need to be able to do it in O(n log n) time.

You might be tempted to think that we can simply precompute first i pipes by simply binary searching the time needed, but this isn't the case, because pipe i only contribute to locks i to n. It's hard to figure a way to do it in log n.

So, the alternative is, 

For first i pipes, we can first figure out how many seconds do we need to fill up the first i pipes exactly. Let's call it min[i].

To compute min[i], any water that comes out from i-1 pipes will contribute to the current lock. So the formula is

time + ((time * i-1) - sum(0, i-1)) total volume contribute to the current pipe

(There's some flaw here, but it somehow got AC, I am assuming it's always possible to fill them exactly, but is it always the case?)

Notice that any water that comes out from first i pipes after min[i] all contributes to locks i+1 to n. So we can simply binary search the lowest time needed to contribute to locks after i.

Formula is

(time * i) - sum(0,i) total volume contributes to locks i+1 to n.

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

    vll a(n);
    for(auto& i : a) cin >> i;

    vll mn(n);
    mn[0] = a[0];
    vll needed(n);
    vll suffix(n);
    for(int i{n-1}; i >= 0; i--){
        suffix[i] += a[i];
        if (i+1 < n) suffix[i] += suffix[i+1];
    }
    vll prefix(n);
    for(int i{}; i < n; i++){
        prefix[i] += a[i];
        if (i) prefix[i] += prefix[i-1];
    }


    for(ll i{}; i < n; i++){
        if (i){
            ll lo = mn[i-1], hi = needed[i-1];
            while (hi > lo){
                ll mid = lo + (hi-lo)/2;
                if (mid + ((i * mid) - prefix[i-1]) >= a[i]) hi = mid;
                else lo = mid + 1;
            }
            mn[i] = lo;
        }
        ll lo = mn[i], hi = (!i ? (ll)n * (ll)1e9 : needed[i-1]);
        while (hi > lo){
            ll mid = lo + (hi-lo)/2;
            if (((i+1) * mid) - prefix[i] >= (i == n-1 ? 0 : suffix[i+1])) hi = mid;
            else lo = mid + 1;
        }
        needed[i] = lo;
    }

    int q;
    cin >> q;

    while(q--){
        ll t;
        cin >> t;
        int lo = 0, hi = n-1;
        while (hi > lo){
            int mid = lo + (hi-lo)/2;
            if (needed[mid] <= t) hi = mid;
            else lo = mid + 1;
        }
        cout << (needed[lo] <= t ? lo+1 : -1) << '\n';
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