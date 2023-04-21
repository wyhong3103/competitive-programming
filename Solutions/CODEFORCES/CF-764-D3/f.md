```

Important condition, 1 <= x < n

We can do this with binary search

Notice that at the beginning, floor(x/n) = 0

x mod n is from [0, n-1]

We could get the mid point of this interval, let it be m, and then add n-m+1, if x mod n <= m, then x/n would stay the same, else we would get (x/n)+1

If it stays the same, it is safe to say that the interval is now on [l+n-m+1, n-1]

else

interval is on [0, r-m+1]

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
    ll n;
    cin >> n;
 
    ll x = 0;
    ll l = 0, r = n-1;
    while(l != r){
        ll mid = l + (r-l)/2;
        cout << "+ " << n-mid-1 << '\n';
        cout.flush();
        ll temp;
        cin >> temp;
        if (temp == x){
            r = mid;
            l += n-mid-1;
            r += n-mid-1;
        }else{
            r = r-mid-1;
            l = 0;
        }
        x = temp;
    }
 
    cout << "! " << (x * n) + l;
    cout.flush();
 
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