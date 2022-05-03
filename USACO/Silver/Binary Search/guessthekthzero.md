So the idea is to make query as if we're doing binary search(we're literally doing binary search). I will demonstrate below
```

Say we got 

1 0 1 1 0 1

As our array, and we want to look for 2nd zero

So first we will query from low to mid, this is because the sum we're getting is from low to mid

? 1 3

We get 2

So apparently, there is one zero from 1 to 3, and our target is not in there, so we minus our target by 1, this is because we're going to shadow the region, we have to take the zero into account

So now k = 1

Then

? 4 5

We get 1, 2 - 1 = 1, there's obviously one zero in between the value, so our target must be somwhere in there

So now, we set our high to mid

The active region

1 0

? 4 4

We get 1, so our target is not in there

We're left with 

0 at the end

So the answer is 5
```
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, t;
    cin >> n >> t;

    int k;
    cin >> k;

    int lo = 1, hi = n;
    
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        cout << "? " << lo << ' ' << mid << '\n';
        int sm;
        cin >> sm;
        if (((mid-lo)+1) - sm >= k){
            hi = mid;
        }else{
            k -= ((mid-lo)+1)-sm;
            lo = mid+1;
        }
    }

    cout << "! " << lo;
}
 
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
    solve();
	return 0;
}

```