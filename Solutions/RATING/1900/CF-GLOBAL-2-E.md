```

First case, triangle with 3 same side, is always possible with any length of stick


Second case, 2 side same and 1 different

1 different length must be <= length of 2 same

we can basically use 2 stick of the same length and bridge it to any stick smaller than it


Third case, triangle with 3 different sides

Triangle with 3 different length cannot exist

Proof

let 2^b be the longest side, and 2^a be the shortest side of the triangle, the angle between longest side and shortest side x, < 90, that being said the minmal lenght of the third side is > 2^b-2^a, bc when we align the two side, this is the shortest length that we could connect both ends. Maximal distance is 2^b, because when we have 2 2^b we could always connect to any smaller, and we assumed 2^b to be the longest side.

There does not exist such a side because

let's say 2^a is 2^(b-1) which is the biggest stick length that is smaller than 2^b, 2^b - 2^(b-1) will produce 2^(b-1), which is a number that can be expressed in binary form s.t there is only one bit on.

But we know we need a number bigger than that so its impossible.

If we have any number below 2^(b-1), MSB of 2^b-2^a would be as big as 2^(b-1) (the b-1 th bit will always be on), so the next number that is bigger than this number and would fulfill the condition is 2^b it self.

Optimal Placement

It's always better to pick 2 stick of the same length pair up with the one that is smaller first.

Its better to waste the length that is smaller first because it's wont be any worse than using the same length of stick as the third stick. Because either way, we're using stick of length <= 2^x. We will left with the same number of sticks that are left unused. 

A case where this is proven to be optimal


1 1 4

when we're using stick with 2^3, we can do 2 1, 2 1 with the previous sticks, however if we are to prioritize making sticks of length 3 first, we wouldn't be able to do anything.

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
    int n;
    cin >> n;

    vll a(n);
    for(auto& i : a) cin >> i;

    ll cnt = 0;
    ll small = 0;
    for(auto& i : a){
        ll paired = min(small, i/2);
        i -= paired * 2;
        small -= paired;
        cnt += paired;
        cnt += i/3; 
        i -= (i/3) * 3;
        small += i;
    }
    cout << cnt << '\n';
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