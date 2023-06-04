```
 
given n lamps, each has bi and ai
 
initially all off
 
we can turn on one lamp 
 
we receive bi
 
total number of lamps turned on, x
 
ai <= x breaks
 
find max points
 
For every lamps that has ai, take the largest min(ai, total lamps that have ai) lamps that have ai 

Here are the observations:


It makes sense to start from the smallest ai, and when total taken == ai, the lamps that has ai is going to break.

Let's look at two situation,

let freq[a[i]] be total element that has a[i]

When freq[ai] >= ai

When this is the case, we can just take every element that has ai, and then move on to a[i+1], ignoring what we did here, and do the same thing, reason is if freq[a[i]] + freq[a[i+1]] >= a[i], we're going to throw freq[a[i+1]] elements away, and we're basically left with freq[a[i+1]] elements, so we can proceed to do the same thing

Else

Take the maximal a[i] elements that has a[i]

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
    
    vector<pll> a(n);
 
    for(auto& i : a) cin >> i.fir >> i.sec;
 
    map<int, multiset<ll, greater<ll>>> mp;
 
    for(auto& i : a){
        mp[i.fir].insert(i.sec);
    }
 
    ll sm = 0;
 
    for(auto& i : mp){
        int cnt = 0;
        for(auto& j : i.sec){
            if (cnt == i.fir) break;
            sm += j;
            cnt++;
        }
    }
    cout << sm << '\n';
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