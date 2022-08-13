```

I am being so careless, had the right idea all along, but one tiny mistake had me failed for hours.


Basically, I was trying to greedy it with only 1 dimensional dp, and it turned out we actually need 2 dimensional dp.

The reason is that, the minimum time and the last mice we can reach all the mice in subset s, do not guarantee us that we can reach the next mice. That's why when we transition from dp[i^(1<<j)][k] (k != j, k = bit 1 in i), we have consider transitioning from every mice, not just the one that gives us the minimal time.

And with that, we can easily do this question.

n is <= 15, and time constraint is ~ 10 seconds.

It gives us the freedom to binary search the initial velocity. And we need DP to identify whether the initial velocity is okay.

And finally print the minimal of it.
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

double distance(vi& a, vi& b){
    return hypot(a[0]-b[0], a[1]-b[1]);
}

bool bitmask_dp(double u, double m, vector<vi>& a){
    //{time, last mouse}
    vector<vector<double>> dp(1 << sz(a), vector<double> (sz(a)));

    for(int i{1}; i < (1<<sz(a)); i++){
        int bit_count = __builtin_popcount(i);
        for(int j{}; j < (sz(a)) ; j++){
            if (i & (1 << j)){
                dp[i][j] = INT_MAX;
                if (bit_count == 1){
                    vi empty = {0,0};
                    double time_taken = distance(empty, a[j])/ u;
                    if (time_taken <= (double)a[j][2]){
                        dp[i][j] = min(dp[i][j], time_taken);
                    }
                }
                for(int k{}; k < sz(a); k++){
                    if (i & (1 << k) && j != k){
                        if (dp[i^(1<<j)][k] == INT_MAX) continue;
                        double time_taken = distance(a[k], a[j])/ (u * pow(m,bit_count-1)) ; 
                        if (dp[i^(1<<j)][k] + time_taken <= (double)a[j][2]){
                            dp[i][j] = min(dp[i][j], dp[i^(1<<j)][k] + time_taken);
                        }
                    }
                }
            }
        }
    }

    for(int i{}; i < sz(a); i++)
        if (dp[(1<<sz(a))-1][i] != INT_MAX) return true;
    return false;
}

void solve(){
    int n;
    cin >> n;

    vector<vi> a(n, vi (3));


    for(auto& i : a) cin >> i[0] >> i[1] >> i[2];
        
    double m;
    cin >> m;

    long double lo = 0, hi = INT_MAX;
    long double res = INT_MAX;
    while (hi >= lo){
        long double mid = lo + (hi-lo)/2; 
        if (bitmask_dp(mid, m, a)){
            res = mid;
            hi = mid-1e-6;
        }else lo = mid+1e-6;
    }
    cout << setprecision(6) << fixed;
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