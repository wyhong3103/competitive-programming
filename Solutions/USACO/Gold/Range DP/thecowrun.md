```

What a problem!

I hate the dp order of this problem, it's a little complicated than usual dp order.

Anyways,

dp[i,j] = minimum cost while fj is at cow i, in subarray[i,j]
dp[j,i] = minimum cost while fj is at cow j, in subarray[i,j]

Although [i,j] and [j,i] is referring to the same subarray, but they're different, one ends at i, and another one ends at j

DP transition,

Notice that, at each instant,

If we want to reach cow i, it's either we come from cow i+1, or cow j

Say that the index is positioned like below

i x x x 0 x x x x j

never > i+1 or < j

This is because, if we're able to reach x, that literally mean we've already reached x+1, (if x is in the left), same goes to x in the right

We will have to keep track of where it ends, because the current minimum of subarray [i,j] doesn't necessary mean it will produce the minimum for the next subarray, so we will have to save both possible state which either ends at i or j

dp[i,j] = min(dp[i][j], dp[i+1][j] + halted * dist[i+1,i], dp[j][i+1] + halted * dist[j][i])
dp[j,i] = min(dp[i][j], dp[j-1][i] + halted * dist[j-1,i], dp[i][j-1] + halted * dist[j][i])

Now the order, which is a little complicated


x x x x 0 y y y y y

note that, there is no need for transition [x,x] or [y,y] (because it doesn't make sense at all, as we would never start from y to y, or x to x)

at each instant, we should only transition between [x,y]

To accomplish this task, we can precompute, [x,0] and [y,0] first, because we would never start from x or y, so [x,0] = [0,x], same goes for y

Now after computing the above, we can start computing the state for [x,y], such that x < 0, y > 0, 0 as in coordinate 0

Now basically try every combination of i and j, (smaller size to bigger size).

And then do the transition.


final answer is simply min(dp[0][n], dp[n][0])

There is an extra element in the array, this is because we've added coordinate 0 into it.
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

//{at, subarray from i to j}
ll dp[1005][1005];

void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;
    a.pb(0);
    sort(all(a));

    int center = lower_bound(all(a), 0) - a.begin();
    
    //left
    for(int i{center-1}; i >= 0 ; i--){
        int halted = center-i-1;
        dp[i][center] = dp[i+1][center];
        dp[i][center] += (n-(halted))*abs(a[i]-a[i+1]);
        dp[center][i] = dp[i][center];
    }

    //right
    for(int i{center+1}; i < n+1; i++){
        int halted = i-center-1;
        dp[i][center] = dp[i-1][center];
        dp[i][center] += (n-halted)*abs(a[i]-a[i-1]);
        dp[center][i] = dp[i][center];
    }

    //left & right

    for(int i{center-1}; i >= 0; i--){
        for(int j{center+1}; j < n+1; j++){
            int halted = j-i-1;
            dp[i][j] = INT_MAX;
            dp[j][i] = INT_MAX;
            dp[i][j] = min({dp[i][j], dp[i+1][j] + ((n-halted) * abs((i+1 == center ? a[j] : a[i+1])-a[i])), dp[j][i+1] + ((n-halted) * abs(a[j]-a[i]))});
            dp[j][i] = min({dp[j][i], dp[j-1][i] + ((n-halted) * abs((j-1 == center ? a[i] : a[j-1])-a[j])), dp[i][j-1] + ((n-halted) * abs(a[j]-a[i]))});
        }
    }

    cout << min(dp[0][n], dp[n][0]);
}

int main(){
    setio("cowrun");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```
