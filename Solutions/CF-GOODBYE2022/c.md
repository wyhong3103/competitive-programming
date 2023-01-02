```
https://codeforces.com/blog/entry/110754

Abridged Statements

Given n integers a_i, n <= 100, a_i <= 1e18. We're asked whether it's possible that there exist a x such that gcd(a_i+x, a_j+x) = 1, for every pair of i and j, i != j.

Observations

1. It is obvious that if there exist 2 same number, it is always a 'NO', gcd(x+a, x+a) = x+a

2. Let's consider another trivial case, that is pretty obvious. When we have 2 odd numbers and 2 even numbers, it is always impossible, because that 2 even numbers has gcd = 2k, which is at least 2, to destroy this even parity, we need to add an odd number, but if we're to add an odd number, the 2 odd number will become even!

Let's generalize this a little bit

Let cnt_p[i] be the number of a[j] that has residue i when mod p.

When we have 2 odd number and 2 even number.

cnt_p[0] = 2
cnt_p[1] = 2

What does that say? No matter what x we add, cnt_p[0] will always >= 2. Think of it as a cycle, if we are to add x, we're basically rotating the cycle, and cnt_p[0] will always remain >= 2. That basicall says no matter what x we add, there will always be >= 2 numbers divisible by p, which is 2 in this case.

To generalize this, for every prime number p, it is impossible to have every pair gcd(a_i + x, a_j + x) = 1, if min(cnt_p) >= 2.

But the problem is, 1e18 is a huge prime number, there is no way we're going to find every prime number up to that number.

Now, consider pigeonhole principle, in what case would we have min(cnt_p) >= 2? When 2*n >= p. And n is relatively small for this.

So we only have to check for prime numbers that is below <= n/2.

Now here comes another dilemma.

If min(cnt[i] for residue i mod p) < 2, that just mean there exist a number x such that, if you add it, all the number will not be divisible by p. 

Now this only applies to one prime number p.

How do we prove that there exists a x that apply to everyone of them?

Chinese Remainder Theorem comes into play.

Given pairwise coprime positive integers m1, m2, ..., mk and arbitary integers a1, a2, ..., ak, the system of simultaneous congrueneces

x = a1 mod m1
x = a2 mod m2
.
.
.
x = ak mod mk

is always solvable.

How do we apply into this question?

For every prime number p_i, we let a_i = any number such that after adding a_i to every number, cnt_p[0] is < 2.

And it is always solvable.

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
 
 
vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
 
void solve(){
    int n;
    cin >> n;
    
    set<ll> s;
 
    bool ok = 1;
    vll a(n);
    for(auto& i : a){
        cin >> i;
        ok &= !s.count(i);
        s.insert(i);
    }
 
    if (!ok){
        cout << "NO" << '\n';
        return;
    }
 
    for(auto& i : primes){
        vi cnt(i);
        for(auto& j : a) cnt[j % i]++;
        
        int mn = INT_MAX;
        for(auto& j : cnt){
            mn = min(j, mn);
        }
 
        if (mn >= 2){
            cout << "NO" << '\n'; 
            return;
        }
    }
 
    cout << "YES" << '\n';
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