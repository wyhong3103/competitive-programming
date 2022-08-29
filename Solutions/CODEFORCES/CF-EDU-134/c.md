```

every d[i] is independent of each other. One thing you need to make sure of, is that if a[i] is assigned to be b[j], the array b can still be produced ,i.e there won't exist a situation where an element is used by others and leading to a[k] didn't have no element to be

1 2 3 4
1 2 3 4

0 0 0 0
0 0 0 0

Notice that we cannot make 1 equal to 2/3/4 as they are exclusive, if we taken one of them, array b won't be formed.

Another example

2 10 10 12 12
8 11 11 13 14

6 1 1 1 1 
6 1 1 2 2

a[0] can only be b[0]
a[1] can be b[1] or b[2] 
a[2] can be b[1] or b[2]
a[3] can be b[3] or b[4] 
a[4] can be b[3] or b[4]

Notice that some of the elements are kind of fixed to be used by a certain element.

Let's create an array as, the total number of b[j] can be used by a[i]


The intial value of all a[i] is 5 4 4 2 2, for the case above.

Where a[i] can be b[j], i <= j < i+5

Let's make this problem a little bit easier.


2 10 10
8 11 11


so it would be

3 2 2

Notice that if we are to consider the last element first (we always should, since the elemnts are sorted, so if a[i] can use b[j], a[k] can use b[j] as well, such that i > k)

So we should prioritize the latest element

If we used a number for that a[2] now that array would become

2 1 1
(a number is used, we're only left with these number of choices)

If we used a number for that a[1] now that array would become

1 0 1

We got a 0! (ignore the element after it (that has already been processed))

And finally, this array would be 

0 0 1


From this , we can sort of tell that, when we received a 0, we can never use elements after the 0. As all the elments have been used up.

And that's the idea of solving this problem. Get the max and min before 0 for each number.

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
    vll b(n);
    for(auto& i : b) cin >> i;
 
    vll d_mn(n);
    vll d_mx(n);
 
    vll total(n);
    for(int i{}; i < n; i++){
        total[i] = b.end() - lower_bound(all(b), a[i]);
    }
 
    int zero = n;
    int sub = 0;
    for(int i{n-1}; i >= 0; i--){
        sub++;
        total[i] -= sub;
        int index = lower_bound(all(b), a[i])  - b.begin();
        d_mn[i] = b[index] - a[i];
        d_mx[i] = b[zero-1] - a[i];
        if (!total[i]) zero = i;
    }
 
    for(auto& i : d_mn) cout << i << ' ';
    cout << '\n';
    for(auto& i : d_mx) cout << i << ' ';
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