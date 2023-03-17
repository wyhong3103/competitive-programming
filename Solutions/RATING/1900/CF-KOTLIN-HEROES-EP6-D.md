```

For a value x, if we want to achieve it, there is always a constructive way that guarantees if a_n is possible to be >= x, then we can always construct such sequence.

We can basically place a_n = x first. For every previous a_i, we do ceil(ai+1/2), because this is the lowest we can go, and this ensure us the more remaining we can use. By repeatedly doing this, until we get ceil(ai+1/2) == 1, we can basically start placing 1 from 0 to i. What about the remainng ones? You might be wondering. We know for a fact, the smallest difference between ai and ai+1, not including all the 1s, is 1 and 2 (if we have remaining at the end). Notice that, if we are to add the 1 on each element from left to right (repeatedly) until we have no more remaining, we wouldnt' change the order and magnitude of anything actually, but we can possibly fill 1 and 2, to 2 and 2, or more, the differnece between the new seq and the old seq wont be more than 1, so it would actually still work. Also, notice that by /2 each time, we essentially have a O(log n) time complexity, which is very doable.

At last, we can just binary search it, since the above is literally monotinic.


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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}


void solve(){
    ll n, s;
    cin >> n >> s;

    auto good = [&](ll mid){
        ll total = n-1;
        ll remain = s-mid;
        
        ll cur = mid / 2 + (mid % 2);
        while (cur != 1 && total){
            total--;
            remain -= cur;
            cur = (cur / 2) + (cur % 2);
        }

        return remain >= total;
    };

    ll lo = 1, hi = s;
    while (hi > lo){
        ll mid = lo + (hi-lo+1)/2;
        if (good(mid)) lo = mid;
        else hi = mid-1;
    }

    cout << lo << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}

```