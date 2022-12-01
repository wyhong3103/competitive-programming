```

We can imagine letting a[x] = i, 1 < i < n, first, except at a[x]

now we would have a number n, and an empty space at a[x]

Observation

We need to squeeze out one index for n, such that the index is a divisor of n! 

If x is not a divisor of n, then it's impossible! 

Proof : At x, we can replace any element that is x*i, i > 1. Everytime we do this, we got a new index such that the index is still divisible by x! Eventually we will be left with 1 index that is also divisible by x. Think of it like this:

we use x*2 to replace x, so right now x*2 is empty, then we need x*4 at the very least to replace it. Eventually, x*2*i will not be available in the array! That's why x must always be a divisor of n, without it, it's impossible, there will always be 1 extra space.

Right now, we need to figure out on how to get the lexicographically minimal permutaton while fulfilling the above.

The idea is we can greedy on it, starting at x, we can place n there, and then iterate from x to x*i (1 <= i < inf && x*i < n). We need to prioritize letting the early elements to be as small as possible! So everytime we see an element x*i, such that n % x*i == 0, we swap it! Because that would guarantee the minimal array! One thing we need to be careful is, we're only allowed to swap iff x * i is also divisible by the previous index of n.

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
    
    if (n % x != 0) cout << -1 << '\n';
    else if (n == x){
        cout << x << ' ';
        for(int i{2}; i < n; i++) cout << i << ' ';
        cout << 1 << ' ';
        cout << '\n';   
    }
    else{
        vi ans(n);
        ans[0] = x;
        ans[n-1] = 1;
        for(int i{2}; i < n; i++){
            ans[i-1] = i;
        }
 
        //n % (x*i) == 0, greatest i
        ans[x-1] = n;
        int at = 1;
        for(int i{2}; i*x < n; i++){
            if ((n/x) % i == 0 && i % at == 0){
                ans[(at*x)-1] = i*x;
                ans[(i*x)-1] = n;
                at = i;
            }
        }
        
 
        for(auto& i : ans) cout << i << ' ';
        cout << '\n';
    }
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