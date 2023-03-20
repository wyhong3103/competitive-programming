I bruteforced for small cases during contest, but doesn't matter, I proved it after the contest.
```
Let's list out the obvious case first,

{0, 0, 0, 0, 0, ..., 0} will always work for any n

{x, x} will always work for n = 1

{2, 2, 2, 2} will always work for n = 2

Let's find another construction

a * b * c * d = e + f + g + h

a * b * c * e = d + f + g + h

Assume no element is equal to 0

WLOG, let a * b * c be A, f + g + h be B

A * e = d + B

A * d = e + B

This is not possible if A == B except when n == 2, because when A == B, we're essentially letting A * d = e * B = A + d = B + e, which would make d = e. Which is only possible when n == 2.

So let's assume A != B

A * d = e + B
A * e = d + B

A * d - (e + B) = A * e - (d + B)
A * d - A * e = e + B - (d + B)
A (d - e) = e - d

A (-1) (e - d) = (e - d)
-A = 1
A = -1

So right now we have,

-1 * d = e + B

This is essentially saying, for any group of n elements in the total of 2*n elements, we can essentially get -1 with the product of n-1 element of the group. 

Obviously, there cannot be n element that is non -1.

Let the 1 element that is excluded from the n-1 element be an unnkown x.

So basically excluding the number x from 2*n elements, any n-1 group should have a product of -1.

When n is even,

Turned out this is only possible when all of them is -1. When we have at least a non -1 that is not x, we can just take that non -1 and group up with the rest n-2 -1, which would make it non -1.

When n is odd,

we need product of any n-1 (even number) element to be -1. We couldn't have >= n-1 of them to be -1, because that would simply make the group of an even number of -1, which would give 1 as the prodcut at the end. But if we have < n-1 of -1, we can just take any n-1 element that is non -1 to make it not have -1. So this is impossible.

So we learned that it is only possible to have such construction when n is even, and we have every 2*n element to be -1.

It is obviously impossible to have x = -1, because no way we can have -1^n = n*-1

So

-1 * x = n * (-1)

-x = -n

x = n

We have got our construction for when n is even number, we can have q as -1 , -1, ... , n

We can just try all the construction above to find the min.
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
 
/*

// BRUTEFORCING FOR SMALL CASES
void recur(int at, vi& a, int n, int mn, int mx){
    if (at == n){
            
        bool ok = 1;
        for(int i{}; i < (1 << n); i++){
            if (__builtin_popcount(i) == n/2){
                ll prod = 1;
                ll sum = 0;
                for(int j{}; j < n; j++){
                    if (i & (1 << j)){
                        prod *= a[j];
                    }else sum += a[j];
                }
                ok &= prod == sum;
            }
        }
        if (ok){
            for(auto& i : a) cout << i << ' ';
            cout << '\n';
        }
 
        return;
    }
 
    for(int i{mn}; i <= mx; i++){
        a.pb(i);
        recur(at+1, a, n, mn, mx);
        a.pop_back();
    }
}
 
void solve(){
    int n, mn, mx;
    cin >> n >> mn >> mx;
    vi a;
    recur(0, a, n, mn, mx);
}
*/
 
void solve(){
    int n;
    cin >> n;
    vi a(2*n);
    for(auto& i : a) cin >> i;
 
    if (n == 1){
        cout << abs(a[0]-a[1]) << '\n';
        return;
    }
 
 
    ll mn = LONG_LONG_MAX;
 
    if (n == 2){
        ll total = 0;
        for(int i{}; i < 2*n; i++){
            total += abs(2-a[i]);
        }
        mn = min(mn, total);
    }
 
    //0 0 case
    ll total = 0;
    for(int i{}; i < 2*n; i++){
        total += abs(a[i]);
    }
    mn = min(mn, total);
    
    if (n % 2 == 0){
        // -1 n case
        total = 0;
        for(int i{}; i < 2*n; i++){
            total += abs(-1-a[i]);
        }
        
        for(int i{}; i < 2*n; i++){
            mn = min(mn, total - abs(-1-a[i]) + abs(n-a[i]));
        }
    }
    cout << mn << '\n';
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