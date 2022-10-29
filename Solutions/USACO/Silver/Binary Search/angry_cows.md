```

First of all, let's notice that from each cell there is a minimal radius needed for it to reach the left most/ right most, depend on whether it's on the right most or left most.

Let's look at one example

1 5 6 10

For each i as a left most we triggered, we have to find what is the minimal needed for it to reach the end of left

1 is obviously 0, if we hit 1, left most is cleared

5 is 5, because of the fact that when we hit 5 with radius = 5, it -1, so became 4, and it hits 1 clearing the prefix

6 is 6, because we need > the last value (imagine if we hit the last haybale with the same value, it's going to -1, so we need at least last value + 1)

10 is 6, with 6 we could hit 5 as well!

So we came up with a few observations

Value needed is monotonic!

And for the current value, it should be at least last value + 1.

Let's see how to find the value for each i for the prefix first

If a[i]-a[i-1] is > last value, the answer is simply a[i]-a[i-1]+1 (+1, because we need that much value in order to trigger a a[i]-a[i-1] radius to hit the target on the left)

else

we will use last value + 1 as a base distance, and see where is the further we can go to! We will do it using binary search.

After that,

we can binary search the radius

And for the checking function, we can use two pointer to find the maximal l and r that is within the 2*radius window, and check if radius >= prefix[l] && radius >= suffix[r]

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
 
    vll prefix(n);
    vll suffix(n);
 
    for(int i{1}; i < n; i++){
        if (a[i]-a[i-1] > prefix[i-1]) prefix[i] = a[i]-a[i-1]+1;
        else{
            int lo = 0, hi = i-1;
            while (hi > lo){
                int mid = lo + (hi-lo)/2;
                if (a[i]-a[mid] <= prefix[i-1]-1){
                    hi = mid;
                }else{
                    lo = mid + 1;
                }
            }
            prefix[i] = max(prefix[i-1], prefix[lo]+1);
        }
    }
    for(int i{n-2}; i >= 0; i--){
        if (a[i+1]-a[i] > suffix[i+1]) suffix[i] = a[i+1]-a[i]+1;
        else{
            int lo = i+1, hi = n-1;
            while (hi > lo){
                int mid = lo + (hi-lo+1)/2;
                if (a[mid]-a[i] <= suffix[i+1]-1){
                    lo = mid;
                }else{
                    hi = mid - 1;
                }
            }
            suffix[i] = max(suffix[i+1], suffix[lo]+1);
        }
    }
 
 
    auto good = [&](double mid){
        int l = 0, r = 0;
        bool ok = 0;
        while (r < n){
            if ((a[r] - a[l]) <= 2*mid || (fabs((a[r]-a[l])-(2*mid)) <= EPS)){
                ok |= ((mid >= prefix[l] || fabs(mid-prefix[l]) <= EPS) && (mid >= suffix[r] || fabs(mid-suffix[r]) <= EPS));
                r++;
            }else{
                l++;
            }
        }
        return ok;
    };
 
    double lo = 0, hi = 1e9;
    for(int i{}; i < 100; i++){
        double mid = lo + (hi-lo)/2;
        if (good(mid)) hi = mid;
        else lo = mid;
    }
 
    cout << setprecision(1) << fixed;
    cout << lo;
} 
 
int main(){
    setio("angry");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```