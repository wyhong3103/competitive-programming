```

Let's see what can we do just by using a single 1, and 7


1..33...7

Turned out, by just doing this, we can easily achieve 1e9, by just having ~50000 3 in between!

And basically, if we add 1 in between of the 3s, we can also get ncr(number of 3 between the 1 we just added between and the last 7, 2) without overcounting any!

So the idea is, we can binary search for every NCR(N, 2) until we get exactly N 1337s.

This is possible, because if we're lacking of little of N, we can always use 1s.

1...333...111337.

The last 111 gives exactly 3 more subsequence of 1337!

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


long long ncr(ll n, ll r){
    ll nom = 1;
    for(ll i{n-r+1}; i <= n; i++) nom *= i;

    ll denom = 1;
    for(ll i{1}; i <= r; i++){
        if (nom % i == 0) nom /= i;
        else denom *= i;
    }
    return nom / denom;
}


void solve(){
    ll n;
    cin >> n;

    ll lo = 2, hi = 1e5;
    while (hi > lo){
        ll mid = lo + (hi-lo+1)/2;
        if (ncr(mid, 2) <= n) lo = mid;
        else hi = mid-1;
    }

    ll biggest = lo;
    ll remain = n-(ncr(biggest, 2));
    vi pos;
    pos.pb(0);
    while (remain){
        lo = 2, hi = 1e5;
        while (hi > lo){
            ll mid = lo + (hi-lo+1)/2;
            if (ncr(mid, 2) <= remain) lo = mid;
            else hi = mid-1;
        }
        remain -= ncr(lo, 2);
        pos.pb(biggest-lo);
    }

    vi res;
    int at = 0;
    for(int i{}; i < biggest; i++){
        while (at < sz(pos) && pos[at] == i){
            res.pb(1);
            at++;
        }
        res.pb(3);
    }
    res.pb(7);
    for(auto& i : res) cout << i;
    cout << '\n';
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