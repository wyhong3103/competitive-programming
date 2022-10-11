```

The idea is to maintain 2 multiset!

Let the first multiset stores the first half (in sorted order), second multiset store the second half!

The tricky part is about maintaining the array!

If we are to remove one previous element, if it's in multiset 1 we need to shift the first element in multiset 2 back to multiset 1. Else, just remove it

If we are to insert an element into multiset 1, while multiset 1 is full, we need to remove the last element in multiset 1 and insert it to multiset 2, and then insert our element!

The median is simply the last element in multiset 1!

CAVEAT : DO NOT USE .count() to check for existence!

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
    int n, k;
    cin >> n >> k;

    multiset<int> ms1;
    multiset<int> ms2;

    vi a(n);
    for(auto& i : a) cin >> i;

    vi res;
    for(int i{}; i < n; i++){
        if (i >= k){
            if (ms1.find(a[i-k]) != ms1.end()){
                ms1.erase(ms1.find(a[i-k]));
                if (!ms2.empty()){
                    ms1.insert(*(ms2.begin()));
                    ms2.erase(ms2.find(*(ms2.begin())));
                }
            }else{
                ms2.erase(ms2.find(a[i-k]));
            }
        }

        if (sz(ms1) < (k+1)/2 || a[i] < *(--ms1.end())){
            if (sz(ms1) >= (k+1)/2){
                ms2.insert(*(--ms1.end()));
                ms1.erase(ms1.find(*(--ms1.end())));
            }
            ms1.insert(a[i]);
        }else{
            ms2.insert(a[i]);
        }
        if (i >= k-1) res.pb(*(--ms1.end()));
    }
    for(auto& i : res) cout << i << ' ';
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