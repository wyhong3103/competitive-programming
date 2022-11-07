```

If sum of [l:r] === 0, ans = 0

if xor of [l:r] != 0, ans = -1

Proof

Consider [l:r] below


1 0 0 1 1 0

Notice that the selected range [L:R] can only be odd, and if we are to include an odd number of 1s, we're not reducing anything, XOR odd number of 1s = 1. This tells us that we can only reduce even number of element every single time. Now this is obvious, odd cannot be fully reduced. If XOR of [l:r] gives non zero value that means one of the bit has odd number of 1s.

If xor of [l:r] is 0 and r-l+1 is odd lengthed, ans = 1 

it comes from the fact that we can just do the operation on entire subarray


if xor of [l:r] is 0, but r-l+1 is even length,

If a[l] or a[r] === 0, answer is automatically 1, because we can just treat it as if it's an odd array
else

we need to make a[l] or a[r] === 0, 

if we could do that, we simply just need to do one more operation

it turned out that we can just deal with a[l],

so the idea is to find a[l:x] such that xor[l:x] will give 0, and x-l+1 is an odd number

We can do this using prefix XOR, in order for XOR[l:x] == 0, prefix xor [x] need to equal to prefix xor [l-1]. (to understand how prefix XOR works checkout USACO Guide's Proof on that)

So the idea is simply

check whether there exist a prefix xor that has the value prefix[l-1] and index is within l, r (we can split index into odd and even, for dealing with the parity of index needed)

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
    int n, q;
    cin >> n >> q;

    vll a(n);
    for(auto& i : a) cin >> i;
    
    map<ll,vi> odd;
    map<ll,vi> even;

    vll prefix(n);
    vll prefix_sum(n);
    for(int i{}; i < n; i++){
        prefix[i] = a[i];
        prefix_sum[i] = a[i];
        if (i) prefix[i] ^= prefix[i-1];
        if (i) prefix_sum[i] += prefix_sum[i-1];
        if (i % 2){
            odd[prefix[i]].pb(i);
        }else even[prefix[i]].pb(i);
    }
    

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        if (prefix_sum[r] - (!l ? 0 : prefix_sum[l-1]) == 0) cout << 0;
        else if ((prefix[r]^(!l ? 0 : prefix[l-1])) != 0) cout << -1;
        else if ((r-l+1) % 2) cout << 1;
        else if ((r-l+1) % 2 == 0){
            if (a[l] == 0 || a[r] == 0) cout << 1 << '\n';
            else if (l % 2){
                if (odd.count((!l ? 0 : prefix[l-1])) && odd[(!l ? 0 : prefix[l-1])].back() >= l && *upper_bound(all(odd[(!l ? 0 : prefix[l-1])]), l) <= r) cout << 2;
                else cout << -1;
            }else{
                if (even.count(!l ? 0 : prefix[l-1]) && even[(!l ? 0 : prefix[l-1])].back() >= l && *upper_bound(all(even[(!l ? 0 : prefix[l-1])]), l) <= r) cout << 2;
                else cout << -1;
            }
        }
        cout << '\n';
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