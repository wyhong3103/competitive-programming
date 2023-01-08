```

Abridged statement

We have n numbers, and given a number m,

we want prefix sum of m to be one of the smallest

each operation we can flip the sign of one of the a[i] 


Observations

1. We can minimize every prefix sum after m first, and it wont affect anything before m. The only operation we would do here is to negate a negative element, this way we make all of them bigger. It doesn't make sense to make them smaller at all.

How do we greedily make each of them bigger by using minimal operation?

Well, we can greedy it, iterate fromm m+1, add every a[i] < 0 value to a multiset until we hit one that is smaller than m, negate from the largest to smallest until prefix[i] > m. The reason we do this is because we need to make sure we grab the largest value that affect most value after m (as early as possible). This greedy works!

2. For prefix before m, it is the same. There is no point negating a negative element at all, since if we enlarge prefix[i] m is going to be enlarged as well. So we do the same greedy, but by negating a positive element! One thing to note is that if prefix[i] < prefix[m], we cannot negate the value on prefix[i], because that would make prefix[i] smaller as well! We need to use the value after that.

The reason why we can guarantee after doing certain operation prefix[i] can be bigger/smaller than target value is that, we start from prefix[i], we can go bigger than it or go smaller than it. (by negating the a[i])

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
    int n, m;
    cin >> n >> m;
 
    vll a(n);
    for(auto& i : a) cin >> i;
 
    vll prefix(n);
    for(int i{}; i < n; i++){
        prefix[i] += a[i];
        if (i) prefix[i] += prefix[i-1];
    }
 
    int ans = 0;
    //deal with back first
    ll cur = 0;
    multiset<ll, greater<ll>> temp;
    for(int i{m}; i < n; i++){
        if (a[i] < 0){
            temp.insert(abs(a[i]));
        }
        if (prefix[i] + cur < prefix[m-1]){
            while (!temp.empty() && prefix[i]+cur < prefix[m-1]){
                cur += 2*(*temp.begin());
                temp.erase(temp.find(*temp.begin()));
                ans++;
            }
        }
    }
 
    temp.clear();
 
    cur = 0;
    //deal front
    for(int i{m-1}; i >= 0; i--){
        if (prefix[i] < prefix[m-1] + cur){
            while (!temp.empty() && prefix[i]<prefix[m-1]+cur){
                cur -= 2 * (*temp.begin());
                temp.erase(temp.find(*temp.begin()));
                ans++;
            }
        }
        if (a[i] > 0){
            temp.insert(a[i]);
        }
    }
 
    cout << ans << '\n';
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