```

I HAVE FINALLY CONQUERED IT!!


The most important observation : if there are >= floor(n/2) consecutive pegs that are removed, blue peg will be touched

Solution

The general idea is to count the total number of ending state (Remove 1 peg to have blue peg touched) ! And then for the pegs that are removed, do permutation.


when n is odd

We can fix a peg x,

 o o
o . o
  x

For the next floor(n/2) pegs to x (clockwise), we can select one of them. And let it be y

 y o
o . o
  x


Only one pegs from these floor(n/2) pegs can be selected, the reason is we want the blue peg to be touched whenever we remove peg y.

Now we can still select some pegs next to y, as long as it doesn't create a gap of floor(n/2)

How do we do that?

Let the first peg to be selected be z, distance between z and y must < floor(n/2)


 y z
o . o
  x

Generally, for when n is odd number, you kind of visualize it as having 3 groups, x as a group of itself, the left of x with floor(n/2) pegs, and the right of x with another floor(n/2) pegs

The group on the left of x is the one where we remove a peg and then have blue peg touched, group with z is just used to make sure there isn't any other floor(n/2) consecutive pegs from y.

Now we have x,y,z we can basically start counting the total number of ways to end this game with the current x,y,z.

Notice that we can also have pegs from z+1 to x-1 to be selected or no, it's totally optional. As long as z is there, it doesn't matter what peg do we select there.

If we are to select j pegs from z+1 peg to x-1 peg, then the total way to end the game with such state, is just (n-3-j)!, 3 comes from peg x,y,z, j comes from the peg we selected from z+1 peg to x-1 peg.

So how to count this in O(N^2)?

Notice that we can shrink the size of the group with z, from floor(n/2) to 1. (1 because we need to keep z)

And then for each group size, we always place z at the first one, so that we dont overcount. If size is i, peg z would basically be at (x-i) % n peg.

For each z, there can only be some peg y, because we cant have such a peg y that has >= floor(n/2) distance between z.

So the formula is

total = 0

for i in range(floor(n/2), 1):
	// to select the optional pegs from z+1 to x-1
	temp = 0
	for j in range(0, i-1):
		temp += (ncr[i-1][j] * fact[n-3-j])

	// you can do some math to see that there is exactly i pegs that can be peg y
	temp *= i

	total += temp

// because this can be apply to every peg x we fixed, since it is symmetric
total *= n


For even case, there is something we need to take care of


Group size of z doesn't start from floor(n/2), but floor(n/2)-1.

Also, even case can have a case where we only need peg x and y, and no need z. Which is when
  y
o   o
  x

We can remove y in this scenario to have the blue peg touched.

```

<img src="./equation.svg" alt="equation">

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

ll ncr[2505][5100];
ll fact[5100];

void gen_ncr(ll mod){
    ncr[0][0] = 1;

    for(int i{1}; i <= 2500; i++){
        for(int j{}; j < 5100; j++){
            if (!j) ncr[i][j] = 1;
            else if (j == i){
                ncr[i][j] = 1;
            }else{
                ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % mod;
            }
        }
    }
}

void gen_fact(ll mod){
    fact[0] = 1;
    fact[1] = 1;
    for(int i{2}; i < 5100; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
}

void solve(){
    ll n, mod;
    cin >> n >> mod;

    gen_ncr(mod);
    gen_fact(mod);

    ll total = 0;
    for(int i{n/2 - (n%2 == 0)}; i >= 1; i--){
        ll temp = 0;
        for(int j{}; j < i; j++){
            temp +=  ((ncr[i-1][j] * fact[n-3-j]) % mod);
            temp %= mod;
        }
        temp *= i + (n%2==0);
        temp %= mod;
        total = (total + temp) % mod;
    }

    if (n % 2 == 0){
        total = (total + fact[n-2]) % mod;
    }

    cout << (total * n) % mod;
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