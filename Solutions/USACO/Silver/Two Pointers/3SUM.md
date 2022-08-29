First way to do it - binary search.
```
Simply iterate through every subarrays, and binary search the interval for target element.

We must the sort the array before it.

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
    int n, x;
    cin >> n >> x;

    vll a(n);
    for(auto& i : a) cin >> i;
    
    vector<pi> pointers;
    for(int i{}; i < n; i++){
        pointers.pb({a[i], i});
    }
    sort(all(pointers));


    for(int i{}; i < n; i++){
        for(int j{i+2}; j < n; j++){
            int lo = i+1, hi = j-1;
            ll target = x - (pointers[i].fir + pointers[j].fir);
            while (hi >= lo){
                int mid = lo+(hi-lo)/2;
                if (pointers[mid].fir == target){
                    vi res = {pointers[i].sec, pointers[j].sec, pointers[mid].sec};
                    sort(all(res));
                    cout << res[0]+1 << ' ' << res[1]+1 << ' ' << res[2]+1;
                    return;
                }else if (pointers[mid].fir > target){
                    hi = mid-1;
                }else {
                    lo = mid+1;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
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

We can also do it with 2 pointers, in a similar manner, we can iterate through every element, fix it as the third pointer, and then use two pointer to find the target element.