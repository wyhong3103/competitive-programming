```

Let's model this problem differently first,

We want

sum(ai / bi) = n-1 / n, s.t bi | n, 1 < bi < n, and 1 < ai < bi


It's equivalent to 

sum(ai * ci) = n-1, s.t ci | n, 1 < ci < n,1 < ai < n/ci

How do we model the above into fractions?

notice that when we have

ai/bi, we would eventually turn the denominator to n, when we want to combine the sum.

The way we would combine them is

(ai * (n/bi)) / (bi * (n/bi)), this would turn the denominator into n

however, we're only interested in the numerator, ai * n/bi

sum(ai * n/bi) basically need to be n-1

So this allows us to model it into our desired equation

Let's first prove that if n = p^i, s.t p is a prime number, it is unsolvable

n mod p = 0 mod p obviously,

and

n-1 mod p = p-1 mod p

Since we're only allowed to use p, it is not possiblto have p*x = p-1 mod p, because p*x mod p is always 0 mod p

Now we prove that we only need k=2 to solve this problem when n= pi^ai * ... * pj^aj, s.t j >= 2

n mod p0 = 0 mod p0

and

n-1 mod p0 = p0-1 mod p0

In number theorey, we learned that when 2 number 'a' and 'm' is coprime, and is in the form of ax mod m, s.t x is an integer [1, m], each ax mod m will have different value.

So it is guaranteed that we could get a sum ax, s.t ax mod m = m-1 mod m

How does that help us?

Well, 
n-1 mod m = m-1 mod m
ax mod m = m-1 mod m

m-1 mod m - m-1 mod m = 0 mod m

So right now, we just need to find an integer y s.t m*y = n-1-a*x, it is always possible because n-1-a*x mod m = 0 mod m

How to fit this in just 2 fractions?

ax mod m has x < m-1, so we could easily fit this in

x / (n/a)

(because of our model, we can turn a*x to x / (n/a), and when they are combined, it will be converted to a*x)

And then

m*y mod m, y is guaranteed to be smaller than n/m, because if it was be >= n/m, we would have (n/m) * m = n

So

y / (n/m)


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
    ll n;
    cin >> n;
    
    map<int,int> pf;

    ll temp = n;
    for(int i{2}; i * i < temp; i++){
        while (temp % i == 0){
            pf[i]++;
            temp /= i;
        }
    }
    if (temp > 1) pf[temp]++;

    if (sz(pf) == 1){
        cout << "NO";
        return;
    }
    
    cout << "YES" << '\n';
    ll mn = pf.begin()->fir;
    ll mn1 = (++pf.begin())->fir;
    ll cur = 0;
    while ((cur * mn1) % mn != mn-1){
        cur++; 
    }

    cout << 2 << '\n';
    cout << cur << ' ' << n/mn1 << '\n';
    cout << (n-1-(cur * mn1))/mn << ' ' << n/mn << '\n';
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