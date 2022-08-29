AC Solution, got that DP part right, but not the part where we have to find the triplet.
```
Instead of finding the triplet in O(N^2 log n), we could find it in O(N^2)

In fact, we could find trp[i][k] (i+1 <= k <= n) in O(N)

the idea is to iterate from i+1 to n

and keep track of the frequency of each element from i+1 to k, and at each instant we do dp[i][k+1] = freq[-a[i]-a[k]]

Now dp[i][j] = number of triplets that have both ends on i and j

And now we simply need to do Range DP with PIE trick, to combine the counts.

One way to improve our time complexity (rather than using hash map to keep track of the frequency of each element), we can use a regular array, as the size is only ~2e6, -1e6 <= a[i] <= 1e6

So we store freq[a[i]] as freq[a[i]+1e6] (because negative value cannot be an index)

And to find our desired number, we simply do a[1e6 + (-a[i]-a[j])] and make sure it wouldn't go out of bounds. If the index > 2e6 then the number simply does't exist.

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

const int MX_VAL = 1e6;

void solve(){
    int n, q;
    cin >> n >> q;

    vll a(n);
    for(auto& i : a) cin >> i;

    vector<vll> dp (n, vll (n));
    

    vi freq((MX_VAL*2)+5);
    for(int i{}; i < n-2; i++){
        for(int j{i+1}; j < n-1; j++){
            freq[a[j]+MX_VAL]++;
            int target = MX_VAL-a[i]-a[j+1];
            if (target >= 0 && target <= 2*MX_VAL) dp[i][j+1] += freq[target];
        }
        for(int j{i+1}; j < n-1; j++){
            freq[a[j]+MX_VAL]--;
        }
    }
    
    for(int i{3}; i <= n; i++){
        for(int j{}; j <= n-i; j++){
            dp[j][j+i-1] += dp[j][j+i-2]+dp[j+1][j+i-1]-dp[j+1][j+i-2];
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        cout << dp[l][r] << '\n';
    }
}

int main(){
    setio("threesum");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```

Working solution, but TLE on test 8,9,10. The idea is to simply binary search the target value in the interval of each subarray, and find how many there is element there is in between with the target value. And then, we can simply DP on the subarray.
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
    int n, q;
    cin >> n >> q;

    vll a(n);
    for(auto& i : a) cin >> i;

    vector<vll> dp (n, vll (n));
    
    unordered_map<int,vi> mp;
    for(int i{}; i < n; i++){
        mp[a[i]].pb(i);
    }

    for(int i{3}; i <= n; i++){
        for(int j{}; j <= n-i; j++){
            int target = -(a[j]+a[j+i-1]);
            if (mp.count(target)){
                pi range = {-1,-1};
                //beginning
                int lo = 0, hi = sz(mp[target])-1;
                while (hi >= lo){
                    int mid = lo+(hi-lo)/2;
                    if (mp[target][mid] > j){
                        range.fir = mid;
                        hi = mid-1;
                    }else lo = mid+1;
                }

                //end
                lo = 0, hi = sz(mp[target])-1;
                while (hi >= lo){
                    int mid = lo+(hi-lo)/2;
                    if (mp[target][mid] < j+i-1){
                        range.sec = mid;
                        lo = mid+1;
                    }else hi = mid-1;
                }

                if (range.fir != - 1 && range.sec != -1 && mp[target][range.fir] > j && mp[target][range.sec] < j+i-1){
                    dp[j][j+i-1] += range.sec-range.fir+1;
                }
            }
            dp[j][j+i-1] += dp[j][j+i-2]+dp[j+1][j+i-1]-dp[j+1][j+i-2];
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        cout << dp[l][r] << '\n';
    }
}

int main(){
    setio("threesum");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```