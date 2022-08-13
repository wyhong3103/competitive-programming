```
We can use a similar concept to elavator to solve this problem.

dp state = subset s
dp value = {x - notes finished, y - current value}

notes finished represents the first x n notes finish, so now we're gathering bank notes for a_x+1

dp transition:

For each subset s, each note selected, let it be i, we will select it as the last note, and transition from dp[s^(1 << i)]

b[i] either adds up to the current note we're trying finish, or bring it close, it cannot exceeds a[x], because that would violate the rules.
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
const double EPS = (1e-7);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    int n, m;
    cin >> n >> m;

    vi a(n);
    vi b(m);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    vector<pi> dp(1 << m);

    bool ok = 0;
    for(int i{}; i < (1 << m); i++){
        for(int j{}; j < m; j++){
            if (i & (1 << j)){
                if (dp[i ^ (1<<j)].sec + b[j] == a[dp[i^(1<<j)].fir]){
                    dp[i] = max(dp[i], {dp[i^(1<<j)].fir+1, 0});
                }else if (dp[i ^ (1<<j)].sec + b[j] < a[dp[i^(1<<j)].fir]){
                    dp[i] = max(dp[i], {dp[i^(1<<j)].fir, dp[i^(1<<j)].sec + b[j]});
                }
                ok |= dp[i].fir == n;
            }
        }
    }
    
    cout << (ok ? "YES" : "NO");
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