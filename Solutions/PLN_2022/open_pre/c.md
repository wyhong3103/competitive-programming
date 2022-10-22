```

Every item will eventually get picked, it's either picked by a or b. We want to greedy at the right property.

Wrong greedy : greedy on value

Imagine if we have

5 2
5 x 1

and x = 1, y = 1

if we took the a's 5

we will get 5 + 1

if we took b's 5

we will get 5 + 2

which is ambiguous, we cannot determine the optimal answer using this property!

Correct greedy : pick the elemen that has the biggest difference!

let d_a[i] = a[i]-b[i], d_b[i] = b[i]-a[i]

sort d_a[i] and d_b[i] in an array.

greedily take the element that has the largest difference! because we want to avoid getting an element that is not worthy!

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
 
    int n, x, y;
    cin >> n >> x >> y;
 
    vi a(n);
    vi b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
 
    vector<bool> vis(n);
 
    // {amount, index, a or b}
    set< pair<ll,pi>, greater<pair<ll,pi>> > available;
    for(int i{}; i < n; i++){
        available.insert({a[i]-b[i], {i, 0}}) ;
        available.insert({b[i]-a[i], {i, 1}}) ;
    }
 
    ll total = 0;
    for(auto& i : available){
        if (vis[i.sec.fir]) continue;
        if (i.sec.sec && y){
            //b
            total += b[i.sec.fir];
            vis[i.sec.fir] = 1;
            y--;
        }else if (!i.sec.sec && x){
            //a
            total += a[i.sec.fir];
            vis[i.sec.fir] = 1;
            x--;
        }
    }
    cout << total << '\n';
 
 
    
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