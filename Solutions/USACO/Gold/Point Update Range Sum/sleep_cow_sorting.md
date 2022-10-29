```

we want to push its order in the longest sorted suffix.

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


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update
>;

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    Tree<int> intree;

    while (!a.empty() && (intree.empty() || a.back() < *intree.begin())){
        intree.insert(a.back());
        a.pop_back();
    }

    vi res;
    for(int i{}; i < sz(a); i++){
        int unsorted = sz(a)-(i+1);
        int index = intree.order_of_key(a[i]);
        res.pb(unsorted+index);
        intree.insert(a[i]);
    }

    cout << sz(res) << '\n';
    for(int i{}; i < sz(res)-1; i++) cout << res[i] << ' ';
    cout << res.back();
}
 
int main(){
    setio("sleepy");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
 

```