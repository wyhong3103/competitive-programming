```

Got a somewhat similar approach during contest, instead of considering an individual element(which I did not think of during the contest), I've came up with an approach that consider the block(identical and consecutive elements). Which theoretically works the same, but is somewhat complicated to implement, a lot of boundary checking etc is required.

After taking a small glance on editorial, I realized that we could in fact only consider a single element.

And here's how it works.

We could use a technique (not exactly the same) called contribution to the sum.

If a[i] == a[i-1]

Then we should only consider how many subarray will a[i] be included, such that a[i] is the starting point of the subarray, the answer is n-i , with self, +1,

Else

Then we should consider three cases, a[i] being the ending point, starting point, and in the middle. And this is really simple as well, ending point = i-1, starting point = n-i, both side = (i-1) * (n-i), and self +1.

Imagine if we have an array below

2 2 2 2

first element = 3 + 1
second element = 2 + 1
third element = 1 + 1
forth element = 1

There is no overcounting, if one element is the same as its previous one, then it shouldn't be considered as an ending point/middle as such subarrays have already been counted by the previous one. We only need to consider the subarrays that starts with that element.

With the query, we can also apply the similar concept.

If we are to change one of the element, we simply need to subtract it's initial value, and also a[i+1], because they're codependent. And then we do the same thing, on these two elements (a[i] , a[i+1]) again.
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
    ll n,m;
    cin >> n >> m;
    
    vll a(n+2);
    for(int i{1}; i<=n;i++){
        cin >> a[i];
    }

    //2 extra points for the ease of boundary checking
    a[0] = -1;
    a[n+1] = -1;

    //initialize with self + first element
    ll res = n;
    for(int i{1}; i <= n; i++){
        if (a[i] == a[i-1]){
            //consider only the right part
            res += n-(i);
        }else{
            res += n-(i) + (i-1) + ((n-(i)) * (i-1));
        }
    }

    while(m--){
        ll i, x;
        cin >> i >> x;
        if (a[i] == a[i-1]){
            res -= n-(i);
        }else{
            res -= n-(i) + (i-1) + ((n-(i)) * (i-1));
        }
        if (a[i+1] == a[i]){
            res -= n-(i+1);
        }else{
            res -= n-(i+1) + (i) + ((n-(i+1)) * (i));
        }

        a[i] = x;
        if (a[i] == a[i-1]){
            res += n-(i);
        }else{
            res += n-(i) + (i-1) + ((n-(i)) * (i-1));
        }
        if (a[i+1] == a[i]){
            res += n-(i+1);
        }else{
            res += n-(i+1) + (i) + ((n-(i+1)) * (i));
        }

        cout << res << '\n';
    }
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

INITIAL APPROACH, while this will work, but it has really complicated implementation.
``` 
everytime we change an element, we only need to recompute the adjacent part

cases : same , same,
diff diff
same diff
dif same

Awesomeness for each subsegment = for each block

+begining + end = beginning  + end

+begining = begining * length of consecutive block

+end = end * length of consecutive block

+self = length of consecutive block*(length of consecutive block+1)/2

####################

we could use map, to deal with the query, range
```
