CM Round yay!
```

My mistake during the contest is trying to look for optimal move for a single subarray, but none of that matters in the actual solution

Solution

Let's first notice that, with a placement of 0, the subarray that is adjcent to it can be moved to anywhere with the cost of length of the subarray

So this gives us an idea,

For every k <= n, we find the minimal sum of length of the subarrays that needed to be rearranged to anywhere in the array s.t number of subarrays <= k

So how do we guarantee the minimal sum of length of the subarrays for each k?

Now notice that, between subarrays that needs to be rearranged, there will exist an element in between the subarray, otherwise we're just essentially rearranging the entire array, (which means we only need a 0, since we're arranging all of them anyway). What should be the numbers in between? Obviously, these are the numbers that aren't gonna move, so they have to be an increasing sequence

Now this gives us an idea to do dynamic programming, since n <= 500, we're free to do N^3

dp state

dp[i][j] = minimal sum of all the subarrays' length s.t there are j subarray and ith element is one of the fixed element

transition

dp[i][j + (1 if there exist at least an element between i and k)] = min(dp[k][j] + total elements in between i and k)

There are some edge cases we need to be careful about, 

The last element element is not necessarily a fixed element, so with dp[i][j] s.t i is the not the last element, we can also consider letting dp[i][j+1] + n-i-1 be the answer for k >= j+1

Element i could be the first fixed element, so dp[i][1] = i-1

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
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
    
    //dp[i][j] = minimal to have j subarrays 
    vector<vi> dp(n+5, vi(n+5, INT_MAX));
    
    dp[0][0] = 0;
 
    vi res(n+5, INT_MAX);
 
    if (n == 1){
        cout << 0 << '\n';
        return;
    }else{
        res[1] = n-1;
    }
    
    for(int i{1}; i < n; i++){
        dp[i][1] = i;
        for(int j{}; j < i; j++){
            if (a[i] > a[j]){
                for(int k{}; k < n; k++){
                    if (dp[j][k] == INT_MAX) continue;
                    dp[i][k+(i-j-1 >= 1)] = min(dp[i][k+(i-j-1 >= 1)], dp[j][k] + i-j-1);
                }
            }
        }
        for(int j{}; j < n; j++){
            if (dp[i][j] == INT_MAX) continue;
            res[j+(i != n-1)] = min(res[j+(i != n-1)], dp[i][j] + n-i-1);
        }
    }
    int mn = res[0];
    for(int i{}; i < n; i++){
        mn = min(mn, res[i+1]);
        cout << mn << ' ';
    }
    cout << '\n';
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