```

Terminology

Connected component - a CC in this problem is a component that is connected by edges (position of i in B, position of i in A)

Claim : The minimum number of swaps needed to make B -> A is M - number of cc

Proof :

It's not hard to see that for a single component, in order to arrange it back we only need to do (size of component - 1) swaps, because if we have arranged (size of component - 2)	elements, the remaining elements will be symmetrical, we could just swap them to the correct position in a swap.

Claim : Minimum number of swaps needed < Number of occurences of the number with maximal frequency

WLOG, let's assume there is an element that occurred twice. By right this element should have 2 outdegree. And the both of this element would be in the same component. Note that when this is the case, we can actually split this component into 2. You can kind of visualize to really understand what it really means to split the component. An optimal approach is basically not letting the same number in the same component, because it can be broken down into 2 or more components, which is more optimal as the total number of swaps needed is N - number of cc.

So how do we construct an array B with maximal swaps needed?

let's sort the number by its frequency first, from largest to smallest

How to have the total components = number of maximal component, we make sure every component has element that is unique.

To do this, we can have connect from the largest to the smallest, and then subtract their frequency by 1 (if it's nonzero), until we reach the end. And with this, we have sucessfully group the elements into a single component. Next thing we need to do is to do a cyclic rotation (shift to the left/right by 1). Repeat this process until the frequency of the largest element is 0.


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

    vi a(n);
    for(auto& i : a) cin >> i;

    map<int, vi> mp;
    for(int i{}; i < n; i++){
        mp[a[i]].pb(i);
    }

    vector<pi> cycle;
    for(auto& i : mp) cycle.pb({sz(i.sec), i.fir});

    sort(all(cycle), greater<pi>());

    vi res(n);

    while (cycle[0].fir){
        vi comp;
        for(auto& i : cycle){
            if (!i.fir) break;
            i.fir--;
            comp.pb(mp[i.sec].back());
            mp[i.sec].pop_back();
        }   
        
        for(int i{1}; i < sz(comp); i++){
            res[comp[i]] = a[comp[i-1]];
        }

        res[comp[0]] = a[comp.back()];
    }

    for(auto& i : res) cout << i << ' ';
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