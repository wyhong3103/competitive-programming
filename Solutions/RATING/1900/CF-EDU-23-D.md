```

notice answer is

sum(max[i:j] - min[i:j])

= max[0:0] - min[0:0] + .... + max[n:n] - min[n:n]

Basically,
subtract every min
add every max

for every element

find the total time it's going to be a max/min on a subarray.

then add/subtract

for max:
	for left, find the closest elemen that is >= max, (to avoid overcounting)
	for right, find the closest elemne that is > max 

We can use sparse table to do this in O(1) and O(N log N) preprocessing


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


int n;

void processSparseMin(vi& a, vector<vi>& sparse){
    for(int i{}; i <= __lg(n); i++){
        for(int j{}; j <= n-(1 << i); j++){
            if (!i){
                sparse[i].pb(a[j]);
            }else{
                int w = i-1;
                sparse[i].pb(min(sparse[w][j], sparse[w][j+(1 << w)]));
            }
        } 
    }
}

void processSparseMax(vi& a, vector<vi>& sparse){
    for(int i{}; i <= __lg(n); i++){
        for(int j{}; j <= n-(1 << i); j++){
            if (!i){
                sparse[i].pb(a[j]);
            }else{
                int w = i-1;
                sparse[i].pb(max(sparse[w][j], sparse[w][j+(1 << w)]));
            }
        } 
    }
}

void solve(){
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    vector<vi> sparseMin(__lg(n)+1);
    vector<vi> sparseMax(__lg(n)+1);

    processSparseMin(a, sparseMin);
    processSparseMax(a, sparseMax);

    ll res = 0;

    for(int i{}; i < n; i++){
        ll l = 0, r = 0;

        //right
        int lo = i, hi = n-1;
        while (hi > lo){
            int mid = lo + (hi-lo+1)/2;

            int w = __lg(mid-i+1);
            int mx = max(sparseMax[w][i], sparseMax[w][mid-(1 << w)+1]);
            if (mx > a[i]){
                hi = mid-1;
            }else lo = mid;
        }

        r = lo-i+1;

        //left
        lo = 0, hi = i-1;
        while (hi > lo){
            int mid = lo + (hi-lo)/2;

            int w = __lg((i-1)-mid+1);
            int mx = max(sparseMax[w][mid], sparseMax[w][(i-1)-(1 << w)+1]);
            if (mx >= a[i]){
                lo = mid+1;
            }else hi = mid;
        }

        l = i-(a[lo] >= a[i] ? i : lo)+1;

        res += (l*r) * a[i];
    }

    for(int i{}; i < n; i++){
        ll l = 0, r = 0;

        //right
        int lo = i, hi = n-1;
        while (hi > lo){
            int mid = lo + (hi-lo+1)/2;

            int w = __lg(mid-i+1);
            int mn = min(sparseMin[w][i], sparseMin[w][mid-(1 << w)+1]);
            if (mn < a[i]){
                hi = mid-1;
            }else lo = mid;
        }

        r = lo-i+1;

        //left
        lo = 0, hi = i-1;
        while (hi > lo){
            int mid = lo + (hi-lo)/2;

            int w = __lg((i-1)-mid+1);
            int mn = min(sparseMin[w][mid], sparseMin[w][(i-1)-(1 << w)+1]);
            if (mn <= a[i]){
                lo = mid+1;
            }else hi = mid;
        }

        l = i-(a[lo] <= a[i] ? i : lo)+1;

        res -= (l*r) * a[i];
    }
    cout << res;
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