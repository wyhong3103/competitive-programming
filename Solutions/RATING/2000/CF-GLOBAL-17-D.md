```

My attempt:

It's obvious that as long as we have at least an odd number in the subsequence. Our array will always be good.

An odd length segment can be place in the middle (0) on the number line with both side with the same length, subtracting each other. With more than one odd, we can simply overlap them at the middle.

I managed to come up with the linear diophantine equation for 2 even element. 

ax + a*(a+1)/2 = by + b*(b+1)/2

ax and by because the this is how the sum changes as we move a segment of size a / b to the left and right on a number line.

ax - by  = b*(b+1)/2 - a*(a+1)/2

If the difference is divisible by gcd(a,b) then it is good.

But this is apparently not enough, so let's look at the solution. (Yes i gave up.)

Solution:

First we must know the generalized linear diophantine equation.

a1x1 + a2x2 + ... + anxn = c

Solution x1,x2,x2...,xn only exist iff c = k * gcd(a1, a2, ..., an), k is any integer

For a particular sequence, b of size m, s.t there is an odd number

b1*(b1 + 1)/2 + b1*x1 + ... + bm*(bm + 1)/2 + bm*xm = 0

b1*x1 + ... + bm*xm = -(b1*(b1+1)/2 + ... + bm*(bm+1)/2)

Let g be the gcd(b1,b2,...,bm), g is not an even number, because there exist an odd number in sequence b.

Let's look any of the natural sum term,

bi * (bi + 1) / 2

This term will be divisible by 2 regardless, since it's a product of an odd number and even number.

Let's prove that g will divide this term,

after dividing 2 with that term, g would still remain in the product, the reason is 2 is not part of g, dividing it would not affect anything.

Okay, g % 2 is proven.

Now, let's prove g % 2 == 0.

Okay when g is an even number, we need to find a property in the sum, s is always divisible by g.

Claim : s is divisible by g when s is divisible by 2^l, s.t l is the maximal integer in the power of 2 that can divide g.

Proof :

1. Not hard to see that when we have g / 2^l, g will become an odd number. And an odd number of g can always divide the sum, proven by our previous proof.

2. So basically, if s is divisible by 2^l, (then we can factor 2^l from g and cancel it out), and then have g as an odd number and divide every number.

Counting for case when >= an odd number is involved is pretty easy,

it's simply (2^(number of odd) - 1) * (2 ^ number of non odd)

We do -1 on the 2^(odd) because we dont want to include empty set.

Counting for even cases,

We can fix every l. 

Also, notice that, it would be very perculiar if 2^l is the greatest power of 2 that divide gcd and at the same time we having 2^l as a factor of the sum. 

Because if we have a = 2^l * x, sum of this would be 2^l*x * (2^l*x + 1) / 2 = (2^(l-1) * x)*(2^l*x + 1) = ... + 2^l-1

So we would get 2^l-1, this is obviously not enough for us to factor it out.

So the idea is, for every number that is involved and their maximal divisible power of 2 is l, we need to have an even number of them, because that way, we would have 2^l-1 + 2^l-1 = 2^l.

Let mn = number that has maximal divisible power of 2 that is l, greater = number that has maximal divisible power of 2 greater than l

Total subset is, (2^(mn-1)-1) * (2^greater)

2^n-1 gives us NC0 + NC2 + NC4 + NC6 + ... + NCN

It's basically just 2^n / 2, cus in the total subset, subset with an odd number and even number of element would balance out.

And there we have the answer.

Proof for:

For a sequence that has an even gcd and 2^l as the maximal divisible power of 2 wouldn't be a good array if s is not divisble by 2^l.

Obviously, if s is not divisible by 2^l, we cannot divide our gcd.

Steps im missing:

Forming the generalize LDE, and after that, we want to find a property of s, so that it allows us to divide g, which is by removing the even parity of it.

```
```

Intuitive way of coming up with this idea

lets suppose we had chosen the starting position to be all 0s (its stupid ik, but just write the sum you get)
lets call this S

then by altering the starting position for the i'th subsequence, we reduce/increase S by b[i] multiples right?

so the set of reachable numbers from a subsequence can be written as 
S + b[1] * x1 + b[2] * x2 + .... 
for some arbitary variables x[i] 

by bezouts lemma, the set of reachable numbers becomes S + gcd(b[i]) * X for some X

to make 0, hence the condition is gcd() | S

we are done with the most part, now lets try to see what S looks like
S = sum(b[i] * (b[i] - 1)/2) 

so we got gcd (b1, b2, ...., bn) | sum of (b[i] * (b[i] - 1))/2 
now, you note that it is "nearly always" good 
specifically suppose that denominator 2 wasnt there, then it wud always be good right?

the issue happens because of the denominator 2 being there, and if b[i] is even, then b[i] gets divided by 2

some careful analysis and you can figure out how to reach the condition through induction

like what if all b[i] odd, all divisible by 2, all divisible by 2 or 4 etc


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

const int MOD = 1e9 + 7;

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    ll res = 0;

	// Even case
    for(int i{1}; i < 32; i++){
        ll cnt = 0;
        ll cntg = 0;
        for(auto& j : a){
            if (j % (1LL << i) == 0){
                if ((j / (1LL << i)) % 2 == 0) cntg++;
                else cnt++;
            }
        }

        if (!cnt) continue;
        res += (modpow(2, cnt-1) - 1) * (modpow(2, cntg));
        res %= MOD;
    }

    // Odd case
    ll cnt = 0;
    ll cntg = 0;
    for(auto& j : a){
        if (j % 2 == 0) cntg++;
        else cnt++;
    }

    res += (modpow(2, cnt) - 1) * (modpow(2, cntg));
    res %= MOD;

    cout << res;
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