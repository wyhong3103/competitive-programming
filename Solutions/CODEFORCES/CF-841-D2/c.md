```

Time limit is pretty strict!

The idea is very simple

A number has an odd number of divisor, iff its a perfect square.

Proof:


Let p0^a0*....*pn^an, be prime factorization of number i

number of divisor of a number = product(ai+1)

Notice that if one of the ai is odd, then we would have number of divisor = (odd+1 == even) * ai * aj

So it would definitely have an even number of divisor.

This might not be so useful.

So we know the condition for it to be odd divisor is simply having at least one prime factorization power that is even!

So in order for a number to have an even number of divisor, every power of it has got to be an even number!

And, that implied a perfect square, because if every prime number is an even number, we can split all of them into two group, and finally have x * x.

Great, now we know that there is less than sqrt(2*n) (2*n because XOR might make the value a little bigger, but never bigger than 2*n, pretty obvious).

Now the XOR subarray trick.

We need to store prefix XOR, and with that we could do a O(1) XOR subarray finding.

If we're currently at i, and XOR[0:i] = x, if we want x to be y, we simply need to find x XOR y in the prefix XOR.

[      x     ]
[x xor y][ y ]

That's the basic idea.


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
    ll n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    vll freq(8*n);
 
    vi perfect;
 
    for(int i{}; i <= sqrt(2*n)+1; i++){
        perfect.pb(i*i);
    }
 
    vll prefix(8*n);
    prefix[0]++;
 
    ll cur = 0;
    for(int i{}; i < n; i++){
        cur ^= a[i];
        for(auto& j : perfect){
            freq[j] += prefix[j^cur];
        }
        prefix[cur]++;
    }
 
    ll cnt = 0;
    for(auto& i : freq){
        cnt += i;
    }
 
    cout << n*(n+1)/2 - cnt << '\n';
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