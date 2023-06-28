```

Naive BFS with multidimensional vis array would be too slow, because we're visiting the cell for many time.

The idea is to DP it.

For each dp[i][j] we store the OPTIMAL time that Tema an be at (i,j).

WLOG, let's just focus on transition to dp[i+1][j]

for every optimal time t at dp[i][j] from big to small,

Now the candidate for optimal time from dp[i][j] at time t, to dp[i][j+1] are

{t+1 iff t+1 isn't restricted, for all the time T+1 that isn't restricted s.t time T is restricted}

Basically, to visualize it, if we have

t                             x t1 (timeline at (i,j))
? o x x x x x o o o o o o x x o  ? (timeline at (i+1,j))

x represent restricted at that time, o represent non restricted, t is current time, t1 is the previous optimal time at dp[i][j] (that is larger than t, because we go from big to small)

Notice that, the optimal transition is to t+1, and every first o that come right after x, because if we have a segment of o, it is always optimal to reach the first o, OR the first o we can reach (at t + 1)

we need not to care about the o that comes after t1, because, at t1, we already made the transition

We need not to care about the o that comes at the first x that happens after t, because we wouldn't be able to make the move at that time, we would be dead

Time complexity

at each dp[i][j], there will only be at most 100 candidate, because we're only generating new candidate when we encounter a restriction.

complete transition from dp[i][j] to dp[i+1][j] takes about O(100* log(100)) as it involves sorting

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
    int n, m;
    cin >> n >> m;
    n++;m++;

    vector<vector<set<int>>> dp(n, vector<set<int>> (m));

    map<int, set<int>> h;
    map<int, set<int>> v;
    
    int r;
    cin >> r;
    for(int i{}; i < r; i++){
        int t, d, c;
        cin >> t >> d >> c;
        if (d == 1){
            h[c].insert(t);
        }else{
            v[c].insert(t);
        }
    }

    dp[0][0].insert(0);

    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (!sz(dp[i][j])) continue;

            auto it = dp[i][j].rbegin();
            ll prev = 1e9 + 5;
            while (it != dp[i][j].rend()){ 
                prev = min(prev, (h[i].upper_bound(*it) != h[i].end() ? *h[i].upper_bound(*it) : prev));
                prev = min(prev, (v[j].upper_bound(*it) != v[j].end() ? *v[j].upper_bound(*it) : prev));

                if (i+1 < n){
                    vi temp;
                    auto it2 = h[i+1].upper_bound(*it);
                    while (it2 != h[i+1].end() && *it2 < prev){
                        temp.pb(*it2);
                        it2++;
                    }
                    
                    it2 = v[j].upper_bound(*it);
                    while (it2 != v[j].end() && *it2 < prev){
                        temp.pb(*it2);
                        it2++;
                    }

                    sort(all(temp));
                    
                    int cur = *it + 1;
                    for(auto& k : temp){
                        if (k == cur) cur++;
                        else{
                            dp[i+1][j].insert(cur);
                            cur = k+1;
                        }
                    }
                    if (!(h[i+1].count(cur) || v[j].count(cur)) )dp[i+1][j].insert(cur);
                }
                if (j+1 < m){
                    vi temp;
                    auto it2 = h[i].upper_bound(*it);
                    while (it2 != h[i].end() && *it2 < prev){
                        temp.pb(*it2);
                        it2++;
                    }

                    it2 = v[j+1].upper_bound(*it);
                    while (it2 != v[j+1].end() && *it2 < prev){
                        temp.pb(*it2);
                        it2++;
                    }

                    sort(all(temp));
                    
                    int cur = *it + 1;
                    for(auto& k : temp){
                        if (k == cur) cur++;
                        else{
                            dp[i][j+1].insert(cur);
                            cur = k+1;
                        }
                    }
                    if (!(h[i].count(cur) || v[j+1].count(cur)) )dp[i][j+1].insert(cur);
                }

                prev = *it;
                it++;
            }
        }
    }

    cout << (sz(dp[n-1][m-1]) ? *dp[n-1][m-1].begin() : -1) << '\n';


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