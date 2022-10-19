```

My in-contest sol is to greedily fill those on the right, which is apprently not the best strategy....


7 6 5 4 3 2 8 1

Failed on the above!


Well, the fact that that array is a permutation gives away something.


The max difference between two adjacent element is <= n.

So instead of greedily increase an element until it became equal with its adjacent greater element.

We can put our focus on those we can fill up first.

The idea is

Get a difference array, sort it according to the difference , we start with the greatest negative first (-1 ... -n), that way we can reduce the inversion evenly, isntead of putting all our operation on the largest difference which is stupid, because the largest difference could've easily been dealt with the last operation where we have n.

I guess we can always clear out the inversion pairs.

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
    vi a(n);
    for(auto& i : a) cin >> i;

    vector<pll> diff;
    
    for(int i{1}; i < n; i++){
        diff.pb({a[i]-a[i-1], i});
    }        

    sort(all(diff), greater<pll>());

    int cur = 1;
    int cnt = n;
    for(auto& i : diff){
        while (a[i.sec] < a[i.sec-1] && cnt > 0){
            a[i.sec] += cur++; 
            cout << i.sec+1 << ' ';
            cnt--;
        }
    }
    while (cnt--) cout << 1 << ' ';
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