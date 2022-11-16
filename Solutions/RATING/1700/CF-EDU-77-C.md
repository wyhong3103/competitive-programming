```

Basically

we're given a cycle of size max(r, b), and we want to find the closest starting point (first fence at this starting point, so it cannot be 0 in this cycle! Because if it's at 0, we could simply replace it with color of max(r,b)) we can be at! The reason for this is that, starting as early as possible guaranteed us the maximal fence to place in the interval.

Observation

Every indices in the cycle of max(r,b) that is divisible by gcd(a,b) is reachable by min(a,b)! So, gcd(a,b) is simply the first point we can be at!


From the first point to the end, the distance is (max(r,b) - gcd(a,b) - 1 (excluding first point)). If distance / min(r,b) >= k-1 (excluding first point!), then we must REBEL

else OBEY!


Now the problem comes, how do we know that we can be at every gcd(r,b)??

Let's talk about the situation where gcd(r,b) = 1

If we could prove that there exist an x and an y such that

min(r,b)*x - max(r,b)*y = 1

Then for gcd(r,b) > 1, it's almost the same, because it's just equivalent to

min(r,b)/gcd(r,b) *x - max(r,b)/gcd(r,b) *y = gcd(r,b)/gcd(r,b)

which will gives us 

i*x - j*y = 1

(i.e when gcd(a,b) > 1, we could just size it down to gcd(a,b) == 1, and then it's just equivalent to sizing it back up!)

example,

gcd(8,6) = 2

8/2 = 4, 6/2 = 3

gcd(4,3) = 1

Say we could reach every indices in the cycle of 4 (0 1 2 3), now we size it up again (0*2 1*2 2*2 3*2) = (0 2 4 6)

It is bezout's identity, but extended euclidean algorithm should be more relevant: https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm)

An easier proof

To see why the result is true, (consider the case where a < b, a and b are coprime)
consider the following sequence:
a (mod b), 2a (mod b), 3a (mod b), ..., (b - 1) * a (mod b), b * a (mod b)

if you can see that the above terms are all distinct, then since there are b terms, and all of them are between 0 and b - 1 (cuz you're taking mod b, those are the only possible values), therefore 1 must be among those values. then you can see you will be able to get to 1 by multiplying a by some constant, then taking mod b (i.e. 1 = k * a - m * b) 

(It makes sense that all of them are distinct! If one of them is not distinct, then we basically just created a new cycle before reaching each and every index in the cycle)

Here's why all the terms above are distinct:
suppose there exists some 1 <= k1, k2 <= b s.t. k1 * a = k2 * a (mod b)
then, since a, b are coprime, you could multiply both sides by a's inverse to get: (a,b are coprime, a inverse exists!)
k1 * a * a^(-1) = k2 * a * a^(-1) (mod b) 
k1 = k2 (mod b)

(1 <= k1, k2 <= b !)

so k1 * a = k2 * a (mod b) if and only if k1 = k2 (mod b)
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

ll gcd(ll a, ll b){
    return (!b ? a : gcd(b, a % b));
}

void solve(){
    ll r, b, k;
    cin >> r >> b >> k;


    ll mx = max(r, b);
    ll mn = min(r, b);

    ll start = gcd(mx, mn);

    if ((mx-start-1) / mn >= k-1) cout << "REBEL" << '\n';
    else cout << "OBEY" << '\n';
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