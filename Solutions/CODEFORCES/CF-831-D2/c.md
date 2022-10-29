```

Sort the array first

Optimal strategy 1

Let min be at bag 1 (alone)

for bag 2 and 3, we can imagine it as 2 stacks. At first, 2nd stack was empty, 3rd stack has the biggest on top and then smallest (except min) in bottom.

We can start by popping biggest and push it to stack 2, and then try to do the difference.

The difference is always (stack 2's top - min) + (stack 2's top - stack 3's top).

The idea is, it is almost always guaranteed that the other guy would choose 2 adjacent elemnt (in the sorted array) that is in different bags, because that guaranteed the smallest diff. But sometime, 2 adjacent element can still have a big diff, and with that big diff, we pair the bigger one (stack 2's top) with the minimal element, we can guaranteed the best sum.

Optimal strategy 2

Basically the same as strat 1, just instead of letting min at bag 1, we let max at bag 1, and then do the same thing but reversed (smallest to biggest on stack 3)!

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
 
    sort(all(a));
 
    ll mx = 0;
    for(int i{n-2}; i >= 1; i--){
        mx = max((max(a[i], a[i+1])-a[0]) + (a[i+1]-a[i]), mx);
    }
    for(int i{1}; i < n-1; i++){
        mx = max((a[n-1] - min(a[i], a[i-1])) + (a[i]-a[i-1]), mx);
    }
 
    cout << mx << '\n';
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