```
Notice that the only thing that mattered in this problem is the frequency of each dishes with 1-3 sushi,
and we can use dp to make our way up to the answer from the base case.

Let us look at the most basic idea first (w/o optimization)

At each state, there will be 4 values that are important

c0 = number of dishes with 0 sushi
c1 = number of dishes with 1 sushi
c2 = number of dishes with 2 sushi
c3 = number of dishes with 3 sushi

Let us define a recursive formula.

E(x) = P(x) * R(x) , Expected value of an event = p-bility of that event * result of that event

Let n = total number of plates

E(c0, c1, c2, c3) =
	c1/n * (1 + E(c0+1, c1-1, c2, c3)) +
	c2/n * (1 + E(c0, c1+1, c2-1, c3)) +
	c3/n * (1 + E(c0, c1, c2+1, c3-1)) +
	c0/n * (1 + E(c0, c1, c2, c3))

If we chose a plate with 1 dishes, clearly, the p-bility is c1/n, and then c0 will add one, 
c1 will subtract one, same goes to the rest.

The special case here is with c0, because we're essentially making no changes.

And after choosing a plate with cx dishes, we're essentially taking the expected number of 
move with the new state + 1, + 1 because of the current new operation.

Now here comes the problem.

When we choose plates with c0, we're going into an infinite loop. What can we do?

Well first, notice that n = c0+c1+c2+c3, and by doing ci/n * 1 , 0 <= i <= 3, we're essentially 
doing n/n which will gives us 1.

So let us redefine our recursive formula.

E(N, 0, 0, 0) = 0

0 moves needed to clean N dishes with 0 sushis. 

E(c0, c1, c2, c3) =
	1 +
	c1/n * (E(c0+1, c1-1, c2, c3)) +
	c2/n * (E(c0, c1+1, c2-1, c3)) +
	c3/n * (E(c0, c1, c2+1, c3-1)) +
	c0/n * (E(c0, c1, c2, c3))


Still we haven't get rid of the infinite state.

Now, by doing a little algebera.

E(c0, c1, c2, c3) - (c0/n * E(c0, c1, c2, c3)) =
	1 +
	c1/n * (E(c0+1, c1-1, c2, c3)) +
	c2/n * (E(c0, c1+1, c2-1, c3)) +
	c3/n * (E(c0, c1, c2+1, c3-1))

E(c0, c1, c2, c3) * (1 - c0/n) =
	1 +
	c1/n * (E(c0+1, c1-1, c2, c3)) +
	c2/n * (E(c0, c1+1, c2-1, c3)) +
	c3/n * (E(c0, c1, c2+1, c3-1))

E(c0, c1, c2, c3) =
	(
	1 +
	c1/n * (E(c0+1, c1-1, c2, c3)) +
	c2/n * (E(c0, c1+1, c2-1, c3)) +
	c3/n * (E(c0, c1, c2+1, c3-1))
	) /
	(1 - c0/n)

There we go, we've gotten rid of the infinite state.


Next up, let's do DP for real.

dp[i][j][k][l] = expected number of times we need to take i number of dishes with 0 sushi, 
j number of dishes with 1 sushi, k number of dishes with 2 sushi, l number of dishes with 3 sushi

dp transition,

dp[i][j][k][l] =
	(
	1 +
	j/n * dp[i+1][j-1][k][l] +
	k/n * dp[i][j+1][k-1][l] +
	l/n * dp[i][j][k+1][l-1]
	) /
	(1 - i/n)

Contraint is N <= 300, sushis on each plate <= 3


300 ^ 4 ~ 8 billion, obviously TLE.

Notice that we don't really need one of the dimension, as n = i+j+k+l, 
we have n, we could get rid of any one of them, let's get rid of 0


dp[i][j][k][l] = expected number of times we need to take i number of dishes with 1 sushi, 
j number of dishes with 2 sushi, k number of dishes with 3 sushi


dp[i][j][k] =
	(
	1 +
	i/n * dp[i-1][j][k] +
	j/n * dp[i+1][j-1][k] +
	k/n * dp[i][j+1][k-1] +
	) /
	(1 - (n-i+j+k)/n)

Dp order

KJI, 

By nesting KIJ for the nesting loop, we can avoid accessing uncomputed state. 
If we are to do i first, dp[i+1] will not be computer, same goes to j and all. 
Only by doing KJI we compute every state correctly.
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

const int MX = 305;
long double dp[MX][MX][MX];

void solve(){
    int n;
    cin >> n;
    
    vi freq(4);
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    for(int k{}; k <= n; k++){
        for(int j{}; j <= n; j++){
            for(int i{}; i <= n; i++){
                if (!k && !j && !i) continue;
                
                dp[i][j][k] = 1;
                if (k){
                    dp[i][j][k] += dp[i][j+1][k-1] * ((double)k/n);
                }

                if (j){
                    dp[i][j][k] += dp[i+1][j-1][k] * ((double)j/n);
                }

                if (i){
                    dp[i][j][k] += dp[i-1][j][k] * ((double)i/n);
                }

                dp[i][j][k] /= (double)(1 - ((double)(n-(i+j+k))/n));
            }
        }
    }

    cout << setprecision(10) << fixed;
    cout << dp[freq[1]][freq[2]][freq[3]];
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