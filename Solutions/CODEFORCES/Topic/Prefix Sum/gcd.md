This problem is really interesting, sadly, I didn't solve it on my own. First, it's because I don't see how I could apply prefix technique here, at least in the very first sight, I didn't spend more than an hour to think, so I figured that I might just take a look at the solution, and understand the technique, and the technique is WOW!
<br>
Explanation :
```
Before we talk about anything, let's first understand how do we get gcd of N integers

12 15 18

gcd of this array is basically

gcd(gcd(12,15), 18)

Basically, chaining all the number pairs up, and gcd the number and the gcd of the last pair.

Notice that we can also work backward.

gcd(gcd(15,18), 12)
```

This problem is about omitting one element, and find the greatest gcd, math won't really helps in here. Brute forcing, recalculating the gcd of the array in N times(omitting one every time), will get TLE.
<br>
The more elegant way of doing this is, using the suffix and prefix GCD. Below show how it works:
```
So, as we already know that, we can work both backward, and foward, they're going to be the same.

X - Omit
O - Included

Let's say we got an array

O O O O O

And we want to omit an element

X O O O O

It could be anywhere, we have to look for the best place that it gets us the greatest gcd

O X O O O

O O X O O

O O O X O

O O O O X

Notice that there will always be first half and second half, or only one of them.

But how do we compute the second half, without the first half gcd??

The suffix and prefix gcd comes into play!

Basically create a suffix gcd array and a prefix gcd array

Calculating foward
prefix gcd array - gcd(i, i) (only the first element), gcd(i, gcd(i-1)) (first two), gcd(i, gcd(i-1)) (first three)....gcd(n-1, gcd(n-2))

Calculating backward
suffix gcd array - gcd(n,n)(only the last element), gcd(n-1, gcd(n)) (last two) ... gcd(i,i+1)

Now test every location

From 0 to N

Omitting the middle element

ans = max(gcd(prefix[i-1], suffix[i+1]), ans)

Note that it's i-1, and i+1, we have to check the case where it's only i-1, or i+1, which is here

O O O O X

X O O O O

```


```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

int gcd(int a, int b){
    if (b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}
 
 
void solve(){ 
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
    
    vi prfGcd(n);
    vi sufGcd(n);

    prfGcd[0] = a[0];

    for(int i{1}; i < n; i++){
        prfGcd[i] = gcd(a[i], prfGcd[i-1]);
    }
    
    sufGcd[n-1] = a[n-1];
    for(int i{n-2}; i >= 0; i--){
        sufGcd[i] = gcd(a[i], sufGcd[i+1]);
    } 

    int ans = max(prfGcd[n-2], sufGcd[1]);
    for(int i{1}; i < n-1; i++){
        ans = max(ans, gcd(sufGcd[i+1], prfGcd[i-1]));
    }
    cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```